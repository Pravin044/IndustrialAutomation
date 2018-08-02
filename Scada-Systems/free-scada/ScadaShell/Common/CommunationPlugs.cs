﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using FreeSCADA.Interfaces;


namespace FreeSCADA.Common
{
	public class CommunationPlugs
	{
		public delegate void ChannelsChangedHandler(ICommunicationPlug plug);
		public event ChannelsChangedHandler ChannelsChanged;

		private List<ICommunicationPlug> commPlugs = new List<ICommunicationPlug>();

		public void Load()
		{
			DirectoryInfo di = new DirectoryInfo(AppDomain.CurrentDomain.BaseDirectory);
			foreach (FileInfo fi in di.GetFiles("Communication.*.dll"))
			{
				Assembly lib = Assembly.LoadFrom(fi.FullName);
				foreach (Type t in lib.GetExportedTypes())
				{
					if (t.GetInterface(typeof(ICommunicationPlug).FullName) != null)
					{
						ICommunicationPlug plug = (ICommunicationPlug)Activator.CreateInstance(t);
						InitializePlugin(Env.Current, plug);
					}
				}
			}
		}

		private void InitializePlugin(IEnvironment env, ICommunicationPlug plug)
		{
			plug.Initialize(env);
			plug.ChannelsChanged += new EventHandler(OnPluginChannelsChanged);
			commPlugs.Add(plug);
		}

		void OnPluginChannelsChanged(object sender, EventArgs e)
		{
			if(ChannelsChanged != null)
			{
				if (sender is ICommunicationPlug)
					ChannelsChanged(sender as ICommunicationPlug);
				else
					ChannelsChanged(null);
			}
		}

		public List<string> PluginIds
		{
			get
			{
				List<string> list = new List<string>();
				foreach (ICommunicationPlug plug in commPlugs)
					list.Add(plug.PluginId);
				return list;
			}
		}

		public ICommunicationPlug this[string pluginId]
		{
			get
			{
				foreach (ICommunicationPlug plug in commPlugs)
					if (plug.PluginId == pluginId)
						return plug;
				return null;
			}
		} 

		public bool Connect()
		{
			foreach (ICommunicationPlug plug in commPlugs)
			{
				bool connectResult = false;
				try 
				{
					connectResult = plug.Connect();
				} 
				catch (Exception e)
				{
					Env.Current.Logger.LogError(StringResources.msgFailedToConnectPlugins);
					Env.Current.Logger.LogError(e.Message);
					return false;
				}

				if (connectResult == false)
				{
					Env.Current.Logger.LogError(StringResources.msgFailedToConnectPlugins);
					Disconnect();
					return false;
				}
			}
			return true;
		}

		public void Disconnect()
		{
			foreach (ICommunicationPlug plug in commPlugs)
				plug.Disconnect();
		}

		public bool IsConnected
		{
			get
			{
				foreach (ICommunicationPlug plug in commPlugs)
				{
					if (plug.IsConnected == false)
						return false;
				}
				return true;
			}
		}
        
        public IChannel GetChannel(string name)
        {
            if (name == null) return null;
            string[] splited = name.Split('.');
            if(splited.Length>1)
            {
                ICommunicationPlug plug;
                if( (plug=this[splited[0]])!=null)
                {
                    foreach (IChannel chanel in plug.Channels)
                    {
                        if(chanel.FullId==name)
                            return chanel;
                    }
                } 
            } 
			return null;
        }
	}
}

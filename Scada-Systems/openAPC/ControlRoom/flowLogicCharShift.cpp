/******************************************************************************

This file is part of ControlRoom process control/HMI software.

ControlRoom is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option) any
later version.

ControlRoom is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
details.

You should have received a copy of the GNU General Public License along with
ControlRoom. If not, see http://www.gnu.org/licenses/

*******************************************************************************

For different licensing and/or usage of the sources apart from GPL or any other
open source license, please contact us at https://openapc.com/contact.php

*******************************************************************************/

#include <wx/wx.h>

#ifdef ENV_DEBUGGER
#include "DebugWin.h"
#endif
#include "iff.h"
#include "globals.h"
#include "flowObject.h"
#include "flowLogic.h"
#include "flowLogicCharShift.h"
#include "oapc_libio.h"


flowLogicCharShift::flowLogicCharShift():flowLogic()
{
   this->data.type=flowObject::FLOW_TYPE_LOGI_CHARSHIFT;
   this->data.stdIN= OAPC_DIGI_IO0|OAPC_DIGI_IO1|OAPC_CHAR_IO2;
   this->data.stdOUT=OAPC_CHAR_IO0|OAPC_CHAR_IO1|OAPC_CHAR_IO2|OAPC_CHAR_IO3|OAPC_CHAR_IO4|OAPC_CHAR_IO5|OAPC_CHAR_IO6|OAPC_CHAR_IO7|FLOW_TYPE_FLAG_CHAR_OVERFLOW_OUT;
}



flowLogicCharShift::~flowLogicCharShift()
{
}



wxString flowLogicCharShift::getDefaultName()
{
   return _T("Character Shift Register");
}



#ifdef ENV_PLAYER
wxUint64 flowLogicCharShift::getAssignedOutput(wxUint64 input)
{
   if (input & OAPC_DIGI_IO0) return OAPC_CHAR_IO_MASK;
   return 0;
}



wxByte flowLogicCharShift::setDigitalInput(FlowConnection *connection,wxByte value,wxUint32 *flowThreadID,flowObject *WXUNUSED(object))
{
   wxInt32 i;

   if (!threadIDOK(flowThreadID,false)) return 0;
#ifdef ENV_DEBUGGER
   if ((connection->targetInputNum!=0) && (connection->targetInputNum!=1))
   {
      wxASSERT(0);
      g_debugWin->setDebugInformation(this,DEBUG_STOP_COND_ILLEGAL_IO,_T(""));
      return 0;
   }
#else
   connection=connection;
#endif

   if (value==0) return 1;
   if (connection->targetInputNum==1) for (i=0; i<MAX_NUM_IOS; i++) txt[i]=_T("");
   return 1;
}



wxByte flowLogicCharShift::setCharInput(FlowConnection *connection,wxString value,wxUint32 *flowThreadID,flowObject *WXUNUSED(object))
{
   wxString overflow;
   wxInt32  i;

   if (!threadIDOK(flowThreadID,false)) return 0;
#ifdef ENV_DEBUGGER
   if (connection->targetInputNum!=2)
   {
      wxASSERT(0);
      g_debugWin->setDebugInformation(this,DEBUG_STOP_COND_ILLEGAL_IO,_T(""));
      return 0;
   }
#else
   connection=connection;
#endif
   overflow=txt[MAX_NUM_IOS-1];
   g_flowPool.startOverflowFlows(this,FLOW_TYPE_FLAG_CHAR_OVERFLOW_OUT,0,0.0,overflow,oapcBinHeadSp(),wxGetLocalTimeMillis()); // TODO: fetch creation time from original thread

   for (i=MAX_NUM_IOS-1; i>0; i--) txt[i]=txt[i-1];
   txt[0]=value;
   return 1;
}



wxString flowLogicCharShift::getCharOutput(FlowConnection *connection,wxInt32 *rcode,wxUint64 WXUNUSED(lastInput))
{
#ifdef ENV_DEBUGGER
   if ((connection->sourceOutputNum<0) || (connection->sourceOutputNum>=MAX_NUM_IOS))
   {
      g_debugWin->setDebugInformation(this,DEBUG_STOP_COND_ILLEGAL_IO,_T(""));
      *rcode=OAPC_ERROR_NO_SUCH_IO;
      return _T("");
   }
#endif
   *rcode=OAPC_OK;
   return txt[connection->sourceOutputNum];
}


#endif







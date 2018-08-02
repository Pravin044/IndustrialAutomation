/******************************************************************************

This file is part of E1803inter shared library

E1803inter is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

E1803inter is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
E1803inter. If not, see <http://www.gnu.org/licenses/>.

E1803inter linking exception: Linking this library dynamically with other
modules is making a combined work based on this library. Thus, the terms and
conditions of the GNU General Public License cover the whole combination. As a
special exception, the copyright holders of this library give you permission
to link this library with independent modules to produce an executable,
regardless of the license terms of these independent modules, and to copy and
distribute the resulting executable under terms of your choice, provided that
you also meet, for each linked independent module, the terms and conditions of
the license of that module. An independent module is a module which is not
derived from or based on this library. If you modify this library, you may
extend this exception to your version of the library, but you are not
obliged to do so. If you do not wish to do so, delete this exception statement
from your version.

*******************************************************************************/

#include <stdio.h>

#include "libe1803.h"
#include "libe1803inter.h"

#ifdef ENV_WINDOWS
 #define snprintf _snprintf
#endif

extern char m_isOpened[E1803_MAX_HEAD_NUM+1];


E1803_API int  EtherDreamGetCardNum(void)
{
   return EzAudDacGetCardNum();
}


E1803_API void EtherDreamGetDeviceName(const int *card,char *buf,int max)
{
   snprintf(buf,max,"E1803-%d",*card);
}


E1803_API bool EtherDreamOpenDevice(const int *card)
{
   if (E1803_load_correction((unsigned char)*card,NULL,0)==E1803_OK)
   {
      m_isOpened[(unsigned char)*card]=1;
      E1803_tune(((unsigned char)*card),E1803_TUNE_10V_ANALOGUE_XYZ);
      return true;
   }
   return false;
}


E1803_API bool EtherDreamWriteFrame(const int *card,const struct point_xy_rgbia *data,int size,unsigned short pps,unsigned short rep)
{
   return EzAudDacWriteFrameNR(card,data,size,pps,rep);
}


E1803_API int  EtherDreamGetStatus(const int *card)
{
   return EzAudDacGetStatus(card);
}


E1803_API bool EtherDreamWriteDMX(const int*,int,const unsigned char*)
{
   return false;
}


E1803_API bool EtherDreamReadDMX(const int*,int,unsigned char*)
{
   return false;
}


E1803_API bool EtherDreamStop(const int *card)
{
   return EzAudDacStop(card);
}


E1803_API bool EtherDreamCloseDevice(const int *card)
{
   E1803_close((unsigned char)*card);
   m_isOpened[(unsigned char)*card]=0;
   return true;
}


E1803_API bool EtherDreamClose(void)
{
   EzAudDacClose();
   return true;
}

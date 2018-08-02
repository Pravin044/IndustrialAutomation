/******************************************************************************

This file is part of E1701inter shared library

E1701inter is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

E1701inter is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
E1701inter. If not, see <http://www.gnu.org/licenses/>.

E1701inter linking exception: Linking this library dynamically with other
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

#include "libe1701.h"
#include "libe1701inter.h"


E1701_API int E1701_GCODE_set_script(const char *script, int length)
{
    char *end,*c;

    c=(char*)script;
    end=c+length;

    while ((*c) && (script!=end))
    {

       c++;
    }
    return E1701_OK;
}


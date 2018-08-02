/*
 Mango - Open Source M2M - http://mango.serotoninsoftware.com
 Copyright (C) 2006-2011 Serotonin Software Technologies Inc.
 @author Matthew Lohbihler
    
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package com.serotonin.mango.db.upgrade;

import com.serotonin.mango.Common;
import java.io.OutputStream;
import javax.sql.DataSource;

/**
 * @author Matthew Lohbihler
 */
public class Upgrade1_8_2 extends DBUpgrade {

    private Upgrade1_8_2() {
        super();
    }
    
   @Deprecated
    private Upgrade1_8_2(DataSource dataSource) {
        super(dataSource);
    }

     public static Upgrade1_8_2 getInstance() {
        return new Upgrade1_8_2(Common.ctx.getDatabaseAccess().getDataSource());
    }
    
    @Override
    public void upgrade() throws Exception {
        try (OutputStream out = createUpdateLogOutputStream("1_8_2")) {
            out.flush();
        }
    }

    @Override
    protected String getNewSchemaVersion() {
        return "1.8.3";
    }
}

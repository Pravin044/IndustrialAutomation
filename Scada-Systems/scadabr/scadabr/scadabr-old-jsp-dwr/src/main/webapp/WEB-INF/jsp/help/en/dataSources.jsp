<%--
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
    along with this program.  If not, see http://www.gnu.org/licenses/.
--%>
<p>The <b>data source list</b> lists all data sources defined in the system, displaying the name, type, connection attributes, and status for each. <b>Connection</b> attributes are configuration values that depend on the data source type. The <b>Status</b> determines whether the data source is enabled (<img src="images/database_go.png"/>) or disabled (<img src="images/database_stop.png"/>). Clicking on the status icon toggles the data source's status.</p>
    <%-- TODO load image via css to be consistent with scheme this is a hack, but it works ...  ?? --%>
<p>To add a new data source, select the data source type from the list and click the <img class="scadaBrAddDataSourceIcon" src="images/18x18_transparent_image.png" /> icon at the top of the list. To edit an existing data source, click the <img src="images/icon_ds_edit.png"/> icon associated with the data source. To delete a data source, click the <img src="images/icon_ds_delete.png"/> icon associated with the data source. Depending upon the amount of data stored for the data source it may take a significant amount of time to delete; be sure to let the delete process finish before continuing.</p>

<p>The <img src="images/arrow_out.png"/> and <img src="images/arrow_in.png"/> icons toggle the display of the points defined for the data source. Similar to data sources, points can be enabled (<img src="images/brick_go.png"/>) or disabled (<img src="images/brick_stop.png"/> here.</p>
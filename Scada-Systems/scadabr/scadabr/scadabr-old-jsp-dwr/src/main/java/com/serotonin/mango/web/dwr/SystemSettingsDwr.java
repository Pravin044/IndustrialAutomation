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
package com.serotonin.mango.web.dwr;

import java.io.File;
import java.net.SocketTimeoutException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ResourceBundle;

import br.org.scadabr.db.configuration.ConfigurationDB;

import br.org.scadabr.InvalidArgumentException;
import br.org.scadabr.l10n.AbstractLocalizer;
import com.serotonin.mango.Common;
import com.serotonin.mango.db.dao.DataPointDao;
import com.serotonin.mango.db.dao.EventDao;
import com.serotonin.mango.db.dao.SystemSettingsDao;
import com.serotonin.mango.rt.event.type.AuditEventType;
import com.serotonin.mango.rt.event.type.SystemEventType;
import com.serotonin.mango.rt.maint.DataPurge;
import com.serotonin.mango.rt.maint.VersionCheck;
import com.serotonin.mango.rt.maint.work.EmailWorkItem;
import com.serotonin.mango.vo.User;
import com.serotonin.mango.vo.bean.PointHistoryCount;
import com.serotonin.mango.vo.permission.Permissions;
import com.serotonin.mango.web.dwr.beans.IntegerPair;
import com.serotonin.mango.web.email.MangoEmailContent;
import br.org.scadabr.util.ColorUtils;
import br.org.scadabr.util.DirectoryInfo;
import br.org.scadabr.util.DirectoryUtils;
import br.org.scadabr.web.dwr.DwrResponseI18n;
import br.org.scadabr.web.dwr.MethodFilter;
import br.org.scadabr.utils.i18n.LocalizableMessage;
import br.org.scadabr.utils.i18n.LocalizableMessageImpl;
import br.org.scadabr.l10n.Localizer;
import br.org.scadabr.vo.event.AlarmLevel;
import br.org.scadabr.vo.event.type.AuditEventSource;
import br.org.scadabr.vo.event.type.SystemEventSource;
import com.serotonin.mango.db.dao.UserDao;
import javax.inject.Inject;

public class SystemSettingsDwr extends BaseDwr {

    @Inject
    private SystemSettingsDao systemSettingsDao;
    
    @MethodFilter
    public Map<String, Object> getSettings() {
        Permissions.ensureAdmin();
        Map<String, Object> settings = new HashMap<>();

        // Email
        settings.put(SystemSettingsDao.EMAIL_SMTP_HOST,
                SystemSettingsDao.getValue(SystemSettingsDao.EMAIL_SMTP_HOST));
        settings.put(SystemSettingsDao.EMAIL_SMTP_PORT, SystemSettingsDao
                .getIntValue(SystemSettingsDao.EMAIL_SMTP_PORT));
        settings.put(SystemSettingsDao.EMAIL_FROM_ADDRESS, SystemSettingsDao
                .getValue(SystemSettingsDao.EMAIL_FROM_ADDRESS));
        settings.put(SystemSettingsDao.EMAIL_FROM_NAME,
                SystemSettingsDao.getValue(SystemSettingsDao.EMAIL_FROM_NAME));
        settings.put(SystemSettingsDao.EMAIL_AUTHORIZATION, SystemSettingsDao
                .getBooleanValue(SystemSettingsDao.EMAIL_AUTHORIZATION));
        settings.put(SystemSettingsDao.EMAIL_SMTP_USERNAME, SystemSettingsDao
                .getValue(SystemSettingsDao.EMAIL_SMTP_USERNAME));
        settings.put(SystemSettingsDao.EMAIL_SMTP_PASSWORD, SystemSettingsDao
                .getValue(SystemSettingsDao.EMAIL_SMTP_PASSWORD));
        settings.put(SystemSettingsDao.EMAIL_TLS,
                SystemSettingsDao.getBooleanValue(SystemSettingsDao.EMAIL_TLS));
        settings.put(SystemSettingsDao.EMAIL_CONTENT_TYPE, SystemSettingsDao
                .getIntValue(SystemSettingsDao.EMAIL_CONTENT_TYPE));

        // System event types
        settings.put("systemEventTypes", SystemEventType.SYSTEM_EVENT_TYPES.keySet());

        // System event types
        settings.put("auditEventTypes", AuditEventType.AUDIT_EVENT_TYPES.keySet());

        // Http
        settings.put(SystemSettingsDao.HTTP_CLIENT_USE_PROXY, SystemSettingsDao
                .getBooleanValue(SystemSettingsDao.HTTP_CLIENT_USE_PROXY));
        settings.put(SystemSettingsDao.HTTP_CLIENT_PROXY_SERVER,
                SystemSettingsDao
                .getValue(SystemSettingsDao.HTTP_CLIENT_PROXY_SERVER));
        settings.put(SystemSettingsDao.HTTP_CLIENT_PROXY_PORT,
                SystemSettingsDao
                .getIntValue(SystemSettingsDao.HTTP_CLIENT_PROXY_PORT));
        settings.put(SystemSettingsDao.HTTP_CLIENT_PROXY_USERNAME,
                SystemSettingsDao
                .getValue(SystemSettingsDao.HTTP_CLIENT_PROXY_USERNAME));
        settings.put(SystemSettingsDao.HTTP_CLIENT_PROXY_PASSWORD,
                SystemSettingsDao
                .getValue(SystemSettingsDao.HTTP_CLIENT_PROXY_PASSWORD));

        // Misc
        settings.put(SystemSettingsDao.EVENT_PURGE_PERIOD_TYPE,
                SystemSettingsDao
                .getIntValue(SystemSettingsDao.EVENT_PURGE_PERIOD_TYPE));
        settings.put(SystemSettingsDao.EVENT_PURGE_PERIODS, SystemSettingsDao
                .getIntValue(SystemSettingsDao.EVENT_PURGE_PERIODS));
        settings.put(
                SystemSettingsDao.REPORT_PURGE_PERIOD_TYPE,
                SystemSettingsDao
                .getIntValue(SystemSettingsDao.REPORT_PURGE_PERIOD_TYPE));
        settings.put(SystemSettingsDao.REPORT_PURGE_PERIODS, SystemSettingsDao
                .getIntValue(SystemSettingsDao.REPORT_PURGE_PERIODS));
        settings.put(SystemSettingsDao.UI_PERFORAMANCE, SystemSettingsDao
                .getIntValue(SystemSettingsDao.UI_PERFORAMANCE));
        settings.put(SystemSettingsDao.GROVE_LOGGING, SystemSettingsDao
                .getBooleanValue(SystemSettingsDao.GROVE_LOGGING));
        settings.put(
                SystemSettingsDao.FUTURE_DATE_LIMIT_PERIOD_TYPE,
                SystemSettingsDao
                .getIntValue(SystemSettingsDao.FUTURE_DATE_LIMIT_PERIOD_TYPE));
        settings.put(
                SystemSettingsDao.FUTURE_DATE_LIMIT_PERIODS,
                SystemSettingsDao
                .getIntValue(SystemSettingsDao.FUTURE_DATE_LIMIT_PERIODS));

        // System
        settings.put(
                SystemSettingsDao.NEW_VERSION_NOTIFICATION_LEVEL,
                SystemSettingsDao
                .getValue(SystemSettingsDao.NEW_VERSION_NOTIFICATION_LEVEL));
        settings.put(SystemSettingsDao.INSTANCE_DESCRIPTION, SystemSettingsDao
                .getValue(SystemSettingsDao.INSTANCE_DESCRIPTION));

        // Language
        settings.put(SystemSettingsDao.LANGUAGE,
                SystemSettingsDao.getValue(SystemSettingsDao.LANGUAGE));

        // Colours
        settings.put(SystemSettingsDao.CHART_BACKGROUND_COLOUR,
                SystemSettingsDao
                .getValue(SystemSettingsDao.CHART_BACKGROUND_COLOUR));
        settings.put(SystemSettingsDao.PLOT_BACKGROUND_COLOUR,
                SystemSettingsDao
                .getValue(SystemSettingsDao.PLOT_BACKGROUND_COLOUR));
        settings.put(SystemSettingsDao.PLOT_GRIDLINE_COLOUR, SystemSettingsDao
                .getValue(SystemSettingsDao.PLOT_GRIDLINE_COLOUR));

        return settings;
    }

    @MethodFilter
    public Map<String, Object> getDatabaseSize() {
        Permissions.ensureAdmin();
        Map<String, Object> data = new HashMap<>();

        // Database size
        File dataDirectory = Common.ctx.getDatabaseAccess().getDataDirectory();
        long dbSize = 0;
        if (dataDirectory != null) {
            DirectoryInfo dbInfo = DirectoryUtils
                    .getDirectorySize(dataDirectory);
            dbSize = dbInfo.getSize();
            data.put("databaseSize", DirectoryUtils.bytesDescription(dbSize));
        } else {
            data.put("databaseSize", "(" + getMessage("common.unknown") + ")");
        }

        // Filedata data
        DirectoryInfo fileDatainfo = DirectoryUtils.getDirectorySize(new File(
                Common.getFiledataPath()));
        long filedataSize = fileDatainfo.getSize();
        data.put("filedataCount", fileDatainfo.getCount());
        data.put("filedataSize", DirectoryUtils.bytesDescription(filedataSize));

        data.put("totalSize",
                DirectoryUtils.bytesDescription(dbSize + filedataSize));

        // Point history counts.
        List<PointHistoryCount> counts = dataPointDao.getTopPointHistoryCounts();
        int sum = 0;
        for (PointHistoryCount c : counts) {
            sum += c.getCount();
        }

        data.put("historyCount", sum);
        data.put("topPoints", counts);
        data.put("eventCount", eventDao.getEventCount());

        return data;
    }

    @MethodFilter
    public void saveEmailSettings(String host, int port, String from,
            String name, boolean auth, String username, String password,
            boolean tls, int contentType) {
        Permissions.ensureAdmin();
        systemSettingsDao.setValue(SystemSettingsDao.EMAIL_SMTP_HOST, host);
        systemSettingsDao.setIntValue(SystemSettingsDao.EMAIL_SMTP_PORT, port);
        systemSettingsDao.setValue(SystemSettingsDao.EMAIL_FROM_ADDRESS, from);
        systemSettingsDao.setValue(SystemSettingsDao.EMAIL_FROM_NAME, name);
        systemSettingsDao.setBooleanValue(
                SystemSettingsDao.EMAIL_AUTHORIZATION, auth);
        systemSettingsDao.setValue(SystemSettingsDao.EMAIL_SMTP_USERNAME,
                username);
        systemSettingsDao.setValue(SystemSettingsDao.EMAIL_SMTP_PASSWORD,
                password);
        systemSettingsDao.setBooleanValue(SystemSettingsDao.EMAIL_TLS, tls);
        systemSettingsDao.setIntValue(SystemSettingsDao.EMAIL_CONTENT_TYPE,
                contentType);
    }

    @MethodFilter
    public Map<String, Object> sendTestEmail(String host, int port,
            String from, String name, boolean auth, String username,
            String password, boolean tls, int contentType) {
        Permissions.ensureAdmin();

        // Save the settings
        saveEmailSettings(host, port, from, name, auth, username, password,
                tls, contentType);

        // Get the web context information
        User user = Common.getUser();

        Map<String, Object> result = new HashMap<>();
        try {
            ResourceBundle bundle = getResourceBundle();
            Map<String, Object> model = new HashMap<>();
            model.put("message", new LocalizableMessageImpl(
                    "systemSettings.testEmail"));
            MangoEmailContent cnt = new MangoEmailContent("testEmail", model,
                    bundle, AbstractLocalizer.localizeI18nKey("ftl.testEmail", bundle),
                    Common.UTF8);
            EmailWorkItem.queueEmail(user.getEmail(), cnt);
            result.put("message", new LocalizableMessageImpl(
                    "common.testEmailSent", user.getEmail()));
        } catch (Exception e) {
            result.put("exception", e.getMessage());
        }
        return result;
    }

    @MethodFilter
    public void saveSystemEventAlarmLevels(List<IntegerPair> eventAlarmLevels) {
        Permissions.ensureAdmin();
        for (IntegerPair eventAlarmLevel : eventAlarmLevels) {
            SystemEventType.setEventTypeAlarmLevel(SystemEventSource.fromMangoDbId(eventAlarmLevel.getI1()),
                    AlarmLevel.fromMangoDbId(eventAlarmLevel.getI2()));
        }
    }

    @MethodFilter
    public void saveAuditEventAlarmLevels(List<IntegerPair> eventAlarmLevels) {
        Permissions.ensureAdmin();
        for (IntegerPair eventAlarmLevel : eventAlarmLevels) {
            AuditEventType.setEventTypeAlarmLevel(AuditEventSource.fromMangoDbId(eventAlarmLevel.getI1()),
                    AlarmLevel.fromMangoDbId(eventAlarmLevel.getI2()));
        }
    }

    @MethodFilter
    public void saveHttpSettings(boolean useProxy, String host, int port,
            String username, String password) {
        Permissions.ensureAdmin();
        systemSettingsDao.setBooleanValue( SystemSettingsDao.HTTP_CLIENT_USE_PROXY, useProxy);
        systemSettingsDao.setValue(SystemSettingsDao.HTTP_CLIENT_PROXY_SERVER, host);
        systemSettingsDao.setIntValue(SystemSettingsDao.HTTP_CLIENT_PROXY_PORT, port);
        systemSettingsDao.setValue(SystemSettingsDao.HTTP_CLIENT_PROXY_USERNAME, username);
        systemSettingsDao.setValue(SystemSettingsDao.HTTP_CLIENT_PROXY_PASSWORD, password);
    }

    @MethodFilter
    public void saveMiscSettings(int eventPurgePeriodType,
            int eventPurgePeriods, int reportPurgePeriodType,
            int reportPurgePeriods, int uiPerformance, boolean groveLogging,
            int futureDateLimitPeriodType, int futureDateLimitPeriods) {
        Permissions.ensureAdmin();
        systemSettingsDao.setIntValue(SystemSettingsDao.EVENT_PURGE_PERIOD_TYPE, eventPurgePeriodType);
        systemSettingsDao.setIntValue(SystemSettingsDao.EVENT_PURGE_PERIODS, eventPurgePeriods);
        systemSettingsDao.setIntValue(SystemSettingsDao.REPORT_PURGE_PERIOD_TYPE, reportPurgePeriodType);
        systemSettingsDao.setIntValue(SystemSettingsDao.REPORT_PURGE_PERIODS, reportPurgePeriods);
        systemSettingsDao.setIntValue(SystemSettingsDao.UI_PERFORAMANCE, uiPerformance);
        systemSettingsDao.setBooleanValue(SystemSettingsDao.GROVE_LOGGING, groveLogging);
        systemSettingsDao.setIntValue(SystemSettingsDao.FUTURE_DATE_LIMIT_PERIOD_TYPE, futureDateLimitPeriodType);
        systemSettingsDao.setIntValue(SystemSettingsDao.FUTURE_DATE_LIMIT_PERIODS, futureDateLimitPeriods);
    }

    @MethodFilter
    public DwrResponseI18n saveColourSettings(String chartBackgroundColour,
            String plotBackgroundColour, String plotGridlineColour) {
        Permissions.ensureAdmin();

        DwrResponseI18n response = new DwrResponseI18n();

        try {
            ColorUtils.toColor(chartBackgroundColour);
        } catch (InvalidArgumentException e) {
            response.addContextual( SystemSettingsDao.CHART_BACKGROUND_COLOUR, "systemSettings.validation.invalidColour");
        }

        try {
            ColorUtils.toColor(plotBackgroundColour);
        } catch (InvalidArgumentException e) {
            response.addContextual( SystemSettingsDao.PLOT_BACKGROUND_COLOUR, "systemSettings.validation.invalidColour");
        }

        try {
            ColorUtils.toColor(plotGridlineColour);
        } catch (InvalidArgumentException e) {
            response.addContextual( SystemSettingsDao.PLOT_GRIDLINE_COLOUR, "systemSettings.validation.invalidColour");
        }

        if (response.isEmpty()) {
            systemSettingsDao.setValue(
                    SystemSettingsDao.CHART_BACKGROUND_COLOUR,
                    chartBackgroundColour);
            systemSettingsDao.setValue(
                    SystemSettingsDao.PLOT_BACKGROUND_COLOUR,
                    plotBackgroundColour);
            systemSettingsDao.setValue(SystemSettingsDao.PLOT_GRIDLINE_COLOUR,
                    plotGridlineColour);
        }

        return response;
    }

    @MethodFilter
    public void saveInfoSettings(String newVersionNotificationLevel,
            String instanceDescription) {
        Permissions.ensureAdmin();
        systemSettingsDao.setValue(
                SystemSettingsDao.NEW_VERSION_NOTIFICATION_LEVEL,
                newVersionNotificationLevel);
        systemSettingsDao.setValue(SystemSettingsDao.INSTANCE_DESCRIPTION,
                instanceDescription);
    }

    @MethodFilter
    public String newVersionCheck(String newVersionNotificationLevel) {
        Permissions.ensureAdmin();
        try {
            return getMessage(VersionCheck
                    .newVersionCheck(newVersionNotificationLevel));
        } catch (SocketTimeoutException e) {
            return getMessage("systemSettings.versionCheck1");
        } catch (Exception e) {
            return getMessage(new LocalizableMessageImpl(
                    "systemSettings.versionCheck2", e.getClass().getName(),
                    e.getMessage()));
        }
    }

    @MethodFilter
    public void saveLanguageSettings(String language) {
        Permissions.ensureAdmin();
        systemSettingsDao.setValue(SystemSettingsDao.LANGUAGE, language);
        Common.setSystemLanguage(language);
    }

    @MethodFilter
    public void purgeNow() {
        Permissions.ensureAdmin();
        DataPurge dataPurge = new DataPurge();
        dataPurge.execute(System.currentTimeMillis());
    }

    @MethodFilter
    public LocalizableMessage purgeAllData() {
        Permissions.ensureAdmin();
        long cnt = runtimeManager.purgeDataPointValues();
        return new LocalizableMessageImpl("systemSettings.purgeDataComplete", cnt);
    }

    @MethodFilter
    public void useDerbyDB() {
        Permissions.ensureAdmin();
        ConfigurationDB.useDerbyDB();
    }

    @MethodFilter
    public void useMysqlDB() {
        Permissions.ensureAdmin();
        ConfigurationDB.useMysqlDB();
    }

    @MethodFilter
    public void useMssqlDB() {
        Permissions.ensureAdmin();
        ConfigurationDB.useMssqlDB();
    }

    @MethodFilter
    public String checkTypeDB() {
        return Common.getEnvironmentString("db.type", "derby");
    }

    @MethodFilter
    public String getAppServer() {
        return Common.ctx.getServletContext().getServerInfo();
    }

    /**
     * @return the systemSettingsDao
     */
    public SystemSettingsDao getSystemSettingsDao() {
        return systemSettingsDao;
    }

    /**
     * @param systemSettingsDao the systemSettingsDao to set
     */
    public void setSystemSettingsDao(SystemSettingsDao systemSettingsDao) {
        this.systemSettingsDao = systemSettingsDao;
    }

}

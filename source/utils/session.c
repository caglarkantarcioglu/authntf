#include "session.h"

Bool Session_parseFromLog(const char *log, Session *session) {
    char ip[16];
    char user[256];
    char monthStr[4];
    int day = 0, hour = 0, minute = 0, second = 0;

    int matched = sscanf(log, LOG_FORMAT, monthStr, &day, &hour, &minute, &second, user, ip);

    if (matched != 7) return false;

    int year = Date_getCurrentYear();
    int month = Date_convertMonth(monthStr);

    Date date = {year, month, day, hour, minute, second};

    strcpy(session->user, user);
    strcpy(session->ip, ip);
    session->date = date;

    return true;
}

Bool Session_checkLogDate(const char *log, Date lastSessionDate) {
    char monthStr[4];
    int day = 0, hour = 0, minute = 0, second = 0;

    int matched = sscanf(log, LOG_DATE_FORMAT, monthStr, &day, &hour, &minute, &second);

    if (matched != 5) return false;

    int year = Date_getCurrentYear();
    int month = Date_convertMonth(monthStr);

    Date date = {year, month, day, hour, minute, second};

    return Date_isAfter(date, lastSessionDate);
};
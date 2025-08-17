#include "session.h"

Bool Session_parseFromLog(const char *log, Session *session) {
    char server[256], user[64], ip[64], fingerprint[256];
    int year, month, day, hour, minute, second, sessionId;

    int matched = sscanf(
            log,
            LOG_FORMAT,
            &year, &month, &day, &hour, &minute, &second,
            server, &sessionId, user, ip, fingerprint
    );

    if (matched != 11) return false;

    year = Date_getCurrentYear();

    Date date = {year, month, day, hour, minute, second};

    strcpy(session->ip, ip);
    strcpy(session->user, user);
    strcpy(session->server, server);
    strcpy(session->fingerprint, fingerprint);

    session->date = date;
    session->sessionId = sessionId;

    return true;
}

Bool Session_checkLogDate(const char *log, Date lastSessionDate) {
    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;

    int matched = sscanf(log, LOG_DATE_FORMAT, &year, &month, &day, &hour, &minute, &second);

    if (matched != 6) return false;

    year = Date_getCurrentYear();

    Date date = {year, month, day, hour, minute, second};

    return Date_isAfter(date, lastSessionDate);
};
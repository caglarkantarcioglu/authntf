/**
 * @file session.h
 *
 * @author Caglar Kantarcioglu
 */

#ifndef SESSION_H
#define SESSION_H

#define LOG_FORMAT "%4d-%2d-%2dT%2d:%2d:%2d.%*d+00:00 %255s sshd-session[%d]: Accepted publickey for %63s from %63s port %*d ssh2: %*s %255s"
#define LOG_DATE_FORMAT "%4d-%2d-%2dT%2d:%2d:%2d"

#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "bool.h"

typedef struct {
    char ip[16];
    char user[256];
    char server[256];
    char fingerprint[256];
    int sessionId;
    Date date;
} Session;


Bool Session_parseFromLog(const char *log, Session *session);

Bool Session_checkLogDate(const char *log, Date lastSessionDate);

#endif
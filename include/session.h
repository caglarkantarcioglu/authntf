/**
 * @file session.h
 *
 * @author Caglar Kantarcioglu
 */

#ifndef SESSION_H
#define SESSION_H

#define LOG_FORMAT "%3s %2d %2d:%2d:%2d %*s sshd[%*d]: Accepted publickey for %256s from %15s"
#define LOG_DATE_FORMAT "%3s %2d %2d:%2d:%2d"

#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "bool.h"

typedef struct {
    char ip[16];
    char user[256];
    Date date;
} Session;


Bool Session_parseFromLog(const char *log, Session *session);

Bool Session_checkLogDate(const char *log, Date lastSessionDate);

#endif
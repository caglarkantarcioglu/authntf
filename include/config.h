/**
 * @file config.h
 *
 * @author Caglar Kantarcioglu
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"

#define CONFIG_FILE "/etc/authntf/authntf.conf"

#define TELEGRAM_API_URL "https://api.telegram.org"

typedef struct {
    char authLogFile[256];
    char telegramToken[64];
    char telegramChatId[64];
} Config;

extern Config config;

Bool Config_init();

#endif
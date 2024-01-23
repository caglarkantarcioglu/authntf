#include "config.h"

Config config = {};

Bool Config_init() {
    Config *pConfig = &config;

    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        return false;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        strtok(line, "\n");
        strtok(line, "\r");
        strtok(line, " ");

        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (key != NULL && value != NULL) {
            if (strcmp(key, "auth_log_file") == 0) {
                strncpy(pConfig->authLogFile, value, sizeof(pConfig->authLogFile));
            } else if (strcmp(key, "telegram.token") == 0) {
                strncpy(pConfig->telegramToken, value, sizeof(pConfig->telegramToken));
            } else if (strcmp(key, "telegram.chat_id") == 0) {
                strncpy(pConfig->telegramChatId, value, sizeof(pConfig->telegramChatId));
            }
        }
    }

    fclose(file);
    return true;
}
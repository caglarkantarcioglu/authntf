#include "telegram.h"

void setTelegramUrl(char *url) {
    sprintf(url, "%s/bot%s/sendMessage", TELEGRAM_API_URL, config.telegramToken);
}

void setSessionMessage(Session session, char *message) {
    char *format = "<b>New Session: </b> %s | <b>PID</b>: %d | %s %%0A<b>User:</b> %s | <b>IP</b>: %s %%0A<b>Fingerprint</b>: %s";

    char date[20];
    Date_formatStr(session.date, date);

    sprintf(message, format, session.server, session.sessionId, date, session.user, session.ip, session.fingerprint);
}

void setCommand(char *command, char *url, char *message) {
    char *format = "curl -X POST \"%s\" ""-d \"chat_id=%s\" ""-d \"text=%s\" ""-d \"parse_mode=HTML\"";

    sprintf(command, format, url, config.telegramChatId, message);
}

void Telegram_sendSessionLog(Session session) {
    char message[512];
    char url[256];
    char command[1024];

    setTelegramUrl(url);
    setSessionMessage(session, message);
    setCommand(command, url, message);

    system(command);
}

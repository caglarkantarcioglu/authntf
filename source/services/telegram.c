#include "telegram.h"

void setTelegramUrl(char *url) {
    sprintf(url, "%s/bot%s/sendMessage", TELEGRAM_API_URL, config.telegramToken);
}

void setSessionMessage(Session session, char *message) {
    char *format = "New Session | User: **%s** IP: **%s** Date: **%s**";

    char date[20];
    Date_formatStr(session.date, date);

    sprintf(message, format, session.user, session.ip, date);
}

void setCommand(char *command, char *url, char *message) {
    char *format = "curl -X POST \"%s\" ""-d \"chat_id=%s\" ""-d \"text=%s\"";

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

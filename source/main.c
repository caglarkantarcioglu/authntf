#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#include "config.h"
#include "date.h"
#include "session.h"

#include "telegram.h"

// Global Variables
pid_t pid;
Date lastSessionDate = {};


void signalHandler(int signum) {
    // kill(pid, SIGTERM);
    exit(EXIT_SUCCESS);
}

void daemonize() {
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }

    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void processLog(const char *line) {
    if (line[0] == '\0') return;

    if (!(strstr(line, "sshd") && strstr(line, "Accepted"))) return;

    if (!Session_checkLogDate(line, lastSessionDate)) return;

    Session session = {};
    int parseResult = Session_parseFromLog(line, &session);

    if (!parseResult) return;

    Telegram_sendSessionLog(session);

    lastSessionDate = session.date;
}

void readAuthLog() {
    FILE *file = fopen(config.authLogFile, "r");

    if (file == NULL) exit(EXIT_FAILURE);

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        processLog(line);
    }

    fclose(file);
}

int main() {
    daemonize();

    // Terminate handler
    signal(SIGTERM, signalHandler);

    pid = getpid();
    Date_getCurrentDate(&lastSessionDate);

    int confLoaded = Config_init();

    if (!confLoaded) exit(EXIT_FAILURE);

    while (1) {
        readAuthLog();

        sleep(60);
    }
}
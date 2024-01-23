#include "date.h"

void Date_formatStr(Date date, char *format) {
    sprintf(format, "%d/%02d/%d %02d:%02d:%02d", date.month, date.day, date.year, date.hour, date.minute, date.second);
}

int Date_getCurrentYear() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    return now->tm_year + 1900;
}

int Date_convertMonth(char *month) {
    if (strcmp(month, "Jan") == 0) return 1;
    else if (strcmp(month, "Feb") == 0) return 2;
    else if (strcmp(month, "Mar") == 0) return 3;
    else if (strcmp(month, "Apr") == 0) return 4;
    else if (strcmp(month, "May") == 0) return 5;
    else if (strcmp(month, "Jun") == 0) return 6;
    else if (strcmp(month, "Jul") == 0) return 7;
    else if (strcmp(month, "Aug") == 0) return 8;
    else if (strcmp(month, "Sep") == 0) return 9;
    else if (strcmp(month, "Oct") == 0) return 10;
    else if (strcmp(month, "Nov") == 0) return 11;
    else if (strcmp(month, "Dec") == 0) return 12;
    else return 0;
}

Bool Date_isAfter(Date d1, Date d2) {
    char v1[20];
    char v2[20];

    sprintf(v1, "%d%d%02d%02d%02d%02d", d1.year, d1.month, d1.day, d1.hour, d1.minute, d1.second);
    sprintf(v2, "%d%d%02d%02d%02d%02d", d2.year, d2.month, d2.day, d2.hour, d2.minute, d2.second);

    return strcmp(v1, v2) > 0 ? true : false;
}

void Date_getCurrentDate(Date *date) {
    time_t current_time = time(NULL);
    struct tm *now = localtime(&current_time);

    date->year = now->tm_year + 1900;
    date->month = now->tm_mon + 1;
    date->day = now->tm_mday;
    date->hour = now->tm_hour;
    date->minute = now->tm_min;
    date->second = now->tm_sec;
}
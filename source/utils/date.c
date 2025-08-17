#include "date.h"

void Date_formatStr(Date date, char *format) {
    sprintf(format, "%04d-%02d-%02d %02d:%02d:%02d", date.year, date.month, date.day, date.hour, date.minute, date.second);
}

int Date_getCurrentYear() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    return now->tm_year + 1900;
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
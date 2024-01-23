/**
 * @file date.h
 *
 * @author Caglar Kantarcioglu
 */

#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "bool.h"

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Date;

void Date_formatStr(Date date, char *format);

int Date_convertMonth(char *month);

int Date_getCurrentYear();

Bool Date_isAfter(Date first, Date second);

void Date_getCurrentDate(Date *date);

#endif
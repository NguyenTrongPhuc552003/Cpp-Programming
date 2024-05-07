//
// Created by Trong_Phuc on 16/05/2023.
//

#ifndef DYNAMIC_MEMORY_V5_MY_MEMORY_H
#define DYNAMIC_MEMORY_V5_MY_MEMORY_H

#include <memory.h>

unsigned int stlen(const char *data) { // string length
    unsigned int str_length = 0;

    while (*(data + str_length) != '\0') str_length++;
    return str_length;
}

void stcat(char *des, char *src) { // string cat
    memmove(des + stlen(des), src, stlen(src));
}

void stcpy(char *des, char *src) { // string copy
    memcpy(des, src, stlen(src) > stlen(des) ? stlen(src) : stlen(des));
}

#endif //DYNAMIC_MEMORY_V5_MY_MEMORY_H

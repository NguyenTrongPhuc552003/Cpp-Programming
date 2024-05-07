//
// Created by Trong_Phuc on 06/04/2023.
//

#ifndef DYNAMIC_MEMORY_V3_MEMALLOC_H
#define DYNAMIC_MEMORY_V3_MEMALLOC_H

#include "malloc.h"

typedef struct me_al {
    unsigned int n = 0;
    int* intType = (int*)malloc(n * sizeof(int));

    int begin();
    int end();
    void push_back(int &data);
    void pop_back();
    void erase();
    unsigned int size();
} my_array;

int my_array::begin() {
    return my_array::intType[0];
}

int my_array::end() {
    return my_array::intType[my_array::size() - 1];
}

void my_array::push_back(int &data) {
    static unsigned int n_copied = n;

    my_array::intType[my_array::n - n_copied] = data;
    n_copied--;
}

void my_array::pop_back() {
    my_array arrCopied;

    my_array::n--;
    arrCopied.intType = my_array::intType; // sao chep con tro
    my_array::intType = (int*)realloc(arrCopied.intType, my_array::n * sizeof(int));
}

void my_array::erase() {
    my_array arrCopied;

    my_array::n = 0;
    arrCopied.intType = my_array::intType; // sao chep con tro
    my_array::intType = (int*)realloc(arrCopied.intType, my_array::n * sizeof(int));
}

unsigned int my_array::size() {
    return my_array::n;
}

#endif //DYNAMIC_MEMORY_V3_MEMALLOC_H

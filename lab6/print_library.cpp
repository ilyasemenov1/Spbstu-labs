
#include "app.h"
#include <cstdio>

void print_library(const Lib* lib) {
    if (lib->size == 0) {
        printf("На данный момент в вашей библиотеке нет книг. Довавьте книги или загрузите их из файла.\n");
        return;
    }

    for (int i = 0; i < lib->size; ++i) print_book(lib->books[i]);
}
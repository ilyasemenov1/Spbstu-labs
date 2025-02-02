
#include "app.h"
#include <cstdio>
#include <cstring>
#include <stdio.h>

void delete_book_by_name(Lib* lib) {

    if (lib->size == 0) {
        printf("На данный момент в вашей библиотеке нет книг. Довавьте книги или загрузите их из файла.\n");
        return;
    }

    printf("Книги в картотеке:");
    for (int i = 0; i < lib->size; ++i) {
        printf(" %s", lib->books[i].title);
    }
    printf("\n");

    char* fake1 = read_line();
    printf("Введите название книги для удаления: ");
    char* title = read_line();

    delete[] fake1; 

    for (int i = 0; i < lib->size; ++i) {
        if (strcmp(lib->books[i].title, title) == 0) {
            book_free(&lib->books[i]);
            for (int j = i; j < lib->size - 1; ++j) {
                lib->books[j] = lib->books[j + 1];
            }
            lib->size--;
            printf("Книга успешно удалена!\n");
            return;
        }
    }

    printf("Книга не найдена!\n");
}
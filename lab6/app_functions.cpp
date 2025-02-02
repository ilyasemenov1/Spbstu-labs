
#include "app.h"
#include <cstddef>
#include <cstring>
#include <stdio.h>

void init_lib(Lib* lib) {
    lib->size = 0;
    lib->capacity = INIT_CAPCITY;
    lib->books = new Book[INIT_CAPCITY];
}

char* read_line() {
    char* str = new char[INIT_CAPCITY]{};
    int ch;
    int size = 0;
    int capaticy = INIT_CAPCITY;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (size + 1 >= capaticy) {
            int new_capaticy = capaticy*GROWTH_FACTOR;
            char* tmp = new char[new_capaticy]{};
            memcpy(tmp, str, capaticy*sizeof(char));
            delete[] str;
            capaticy = new_capaticy;
            str = tmp;
        }
        str[size++] = (char) ch;
    }

    return str;
}

char* transform_line(char line[]) {
    char* str = new char[INIT_CAPCITY]{};
    int size = 0;
    int capaticy = INIT_CAPCITY;

    while (line[size] != 0) {
        if (size + 1 >= capaticy) {
            int new_capaticy = capaticy*GROWTH_FACTOR;
            char* tmp = new char[new_capaticy]{};
            memcpy(tmp, str, capaticy*sizeof(char));
            delete[] str;
            capaticy = new_capaticy;
            str = tmp;
        }
        str[size++] = line[size];
    }

    return str;
}

void resize_lib(Lib *lib) {
    int new_capacity = lib->capacity * GROWTH_FACTOR;
    Book *new_books = new Book[new_capacity];
    memcpy(new_books, lib->books, (lib->capacity)*sizeof(Book));
    delete[] lib->books;
    lib->books = new_books;
    lib->capacity = new_capacity;
}

void book_free(Book* book) {
    delete[] book->title;
    book->title = nullptr;

    delete[] book->author;
    book->author = nullptr;

    delete[] book->genre;
    book->genre = nullptr;

    delete[] book->description;
    book->description = nullptr;
}

void print_book(Book book) {
    printf("Книга №%d: %s\n", book.number, book.title);
    printf("Автор: %s\n", book.author);
    printf("Год изнания: %d\n", book.year);
    printf("Жанр: %s\n", book.genre);
    printf("Описание: %s\n", book.description);
}
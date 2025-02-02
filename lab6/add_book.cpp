
#include "app.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

void book_add_input(char** obj, const char* text, const char* err) {
    char* value = 0;
    do {
        printf("%s", text);
        value = read_line();
        if (strlen(value) != 0) (*obj) = value;
        else {
            printf("%s\n", err);
        }
    } while (strlen(value) == 0);
}

bool add_book(Lib* lib) {

    if (lib->size >= lib->capacity) resize_lib(lib);

    Book book;

    char* fake_str = read_line();

    book_add_input(&book.title, "Введите название книги: ", "Некорректное название книги!");
    book_add_input(&book.author, "Введите автора книги: ", "Некорректный автор книги!");

    int year = -1;
    do {
        printf("Введите год издания книги: ");
        int res = scanf("%d", &year);
        if (year < 0 ||year > 2100 || !res) {
            printf("Некорректный год издания.\n");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            book.year = year;
        }
    } while (year < 0 || year > 2100);

    char* fake_str2 = read_line();
    book_add_input(&book.genre, "Введите жанр книги: ", "Некорректный жанр книги!");
    book_add_input(&book.description, "Введите описание книги: ", "Некорректное описание книги!");

    delete[] fake_str;
    delete[] fake_str2;

    book.number = lib->size + 1;

    lib->books[lib->size++] = book;

    printf("Книга успешно добавлена в библиотеку!\n");

    return true;
}
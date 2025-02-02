
#include "app.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

void edit_library(Lib* lib) {

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
    printf("Введите название книги для редактирования: ");
    char* title = read_line();
    delete[] fake1;

    for (int i = 0; i < lib->size; ++i) {
        if (strcmp(lib->books[i].title, title) == 0) {
            printf("Редактируемая книга: %s\n", title);
            printf("Текущее название книги: %s\n",  lib->books[i].title);
            printf("Введите новое название книги: ");
            char* title = read_line();
            if (strlen(title) != 0) lib->books[i].title = title;
            
            printf("Текущей автор книги: %s\n",  lib->books[i].author);
            printf("Введите нового автора книги: ");
            char* author = read_line();
            if (strlen(author) != 0) lib->books[i].author = author;
            
            printf("Текущей год издания книги: %d\n",  lib->books[i].year);
            int year = -1;
            do {
                printf("Введите новый год издания книги: ");

                int res = scanf("%d", &year);
                if (year < 0 ||year > 2100 || !res) {
                    printf("Некорректный год издания.\n");
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    lib->books[i].year = year;
                }
            } while (year < 0 || year > 2100);

            printf("Текущей жанр книги: %s\n",  lib->books[i].genre);
            char* fake_str2 = read_line();
            printf("Введите новый жанр книги: ");
            char* genre = read_line();
            if (strlen(genre) != 0) lib->books[i].genre = genre;

            printf("Текущее описание книги: %s\n",  lib->books[i].description);
            printf("Введите новое описание книги: ");
            char* description = read_line();
            if (strlen(description) != 0) lib->books[i].description = description;

            delete[] fake_str2;

            printf("Книга успешно обновлена!\n");

            return;
        }
    }

    printf("Книга не найдена!\n");
}
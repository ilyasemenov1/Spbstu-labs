
#include "app.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

bool comp(const char* mask, const char* title) {
    int len = min(strlen(mask), strlen(title)); 
    bool flag = true;
    for (int i = 0; i < len; ++i) {
        if (mask[i] != title[i]) flag = false;
    }

    return flag;
}

void search_by_title(const Lib* lib) {
    printf("Ведите заголовок для поиска:");
    const char* mask = read_line();
    for (int i = 0; i < lib->size; ++i) {
        if (comp(mask, lib->books[i].title)) {
            print_book(lib->books[i]);
            return;
        }
    }
    printf("Ничего не найдено!\n");
}

void search_by_author(const Lib* lib) {
    printf("Ведите автора для поиска:");
    const char* mask = read_line();
    for (int i = 0; i < lib->size; ++i) {
        if (comp(mask, lib->books[i].author)) {
            print_book(lib->books[i]);
            return;
        }
    }
    printf("Ничего не найдено!\n");
}

void search_by_genre(const Lib* lib) {
    printf("Ведите жанр для поиска:");
    const char* mask = read_line();
    for (int i = 0; i < lib->size; ++i) {
        if (comp(mask, lib->books[i].genre)) {
            print_book(lib->books[i]);
            return;
        }
    }
    printf("Ничего не найдено!\n");
}

void open_search(const Lib* lib) {
    if (lib->size == 0) {
        printf("На данный момент в вашей библиотеке нет книг. Довавьте книги или загрузите их из файла.\n");
        return;
    }

    printf("Поиск по:\n");

    const char* app_menu[] = {
        "- названию книги",
        "- автору",
        "- жанру"
    };

    const int num_options = sizeof(app_menu)/sizeof(char*); 

    for (int i = 0; i < num_options; i++) {
      printf("[%d] %s.\n", i + 1, app_menu[i]);
    }
    
    int option;
    int res = 1;

    do {
        printf("Выберите действие [1-3]: ");
        res = scanf("%d", &option);

        if (!res || !(1 <= option && option <= 3) ) {
            printf("Выбрана невалидная опция!\n");
            option = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!res || !(1 <= option && option <= 3));

    char* fake = read_line();
    delete[] fake;

    switch (option) {
        case 1:
            search_by_title(lib);
            break;
        case 2: 
            search_by_author(lib);
            break;
        case 3:
            search_by_genre(lib);
            break;
    }
}

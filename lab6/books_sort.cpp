#include <stdio.h>
#include <string.h>
#include "app.h"
#include <iostream>
#include <limits>

using namespace std;

void sort_by_title(Lib* lib, int invert) {
    int n = lib->size;
    for (int i = 1; i < n; i++) {
        Book key = lib->books[i];
        int j = i - 1;

        
        while (j >= 0 && (strcmp(lib->books[j].title, key.title)*(invert) > 0)) {
            lib->books[j+1] = lib->books[j];
            j--;
        }
        lib->books[j+1] = key;
    }
}

void sort_by_author(Lib* lib, int invert) {
    int n = lib->size;
    for (int i = 1; i < n; i++) {
        Book key = lib->books[i];
        int j = i - 1;

        
        while (j >= 0 && (strcmp(lib->books[j].author, key.author)*(invert) > 0)) {
            lib->books[j+1] = lib->books[j];
            j--;
        }
        lib->books[j+1] = key;
    }
}

void sort_by_genre(Lib* lib, int invert) {
    int n = lib->size;
    for (int i = 1; i < n; i++) {
        Book key = lib->books[i];
        int j = i - 1;

        
        while (j >= 0 && (strcmp(lib->books[j].genre, key.genre)*(invert) > 0)) {
            lib->books[j+1] = lib->books[j];
            j--;
        }
        lib->books[j+1] = key;
    }
}

void sort_by_desc(Lib* lib, int invert) {
    int n = lib->size;
    for (int i = 1; i < n; i++) {
        Book key = lib->books[i];
        int j = i - 1;

        
        while (j >= 0 && (strcmp(lib->books[j].description, key.description)*(invert) > 0)) {
            lib->books[j+1] = lib->books[j];
            j--;
        }
        lib->books[j+1] = key;
    }
}

void sort_by_year(Lib* lib, int invert) {
    int n = lib->size;  
    for (int i = 1; i < n; i++) {
        Book key = lib->books[i];
        int j = i - 1;

        
        while (j >= 0 && ((lib->books[j].year - key.year)*(invert) > 0)) {
            lib->books[j+1] = lib->books[j];
            j--;
        }
        lib->books[j+1] = key;
    }
}

void open_sort(Lib* lib) {
    if (lib->size == 0) {
        printf("На данный момент в вашей библиотеке нет книг. Довавьте книги или загрузите их из файла.\n");
        return;
    }

    printf("Сортировка по:\n");

    const char* app_menu[] = {
        "- названию книги",
        "- автору",
        "- жанру",
        "- году издания",
        "- описанию"
    };

    const int num_options = sizeof(app_menu)/sizeof(char*); 

    for (int i = 0; i < num_options; i++) {
      printf("[%d] %s.\n", i + 1, app_menu[i]);
    }
    
    int option;
    int res = 1;

    do {
        printf("Выберите действие [1-5]: ");
        res = scanf("%d", &option);

        if (!res || !(1 <= option && option <= 5) ) {
            printf("Выбрана невалидная опция!\n");
            option = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!res || !(1 <= option && option <= 5));

    char* option2;
    printf("Инвертировать сортировку [N/y]: ");
    scanf("%s", option2);

    int invert = ((option2[0] == 'y' || option2[0] == 'Y') && strlen(option2) == 1) ? -1 : 1;

    char* fake = read_line();
    delete[] fake;

    switch (option) {
        case 1:
            sort_by_title(lib, invert);
            break;
        case 2: 
            sort_by_author(lib, invert);
            break;
        case 3:
            sort_by_genre(lib, invert);
            break;
        case 4:
            sort_by_year(lib, invert);
            break;
        case 5:
            sort_by_desc(lib, invert);
            break;
    }

    for (int i = 0; i < lib->size; ++i) print_book(lib->books[i]);
}

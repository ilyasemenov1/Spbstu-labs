#include "book.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void print_book(const Book& book) {
    printf("Автор: %s\n", book.author);
    printf("Название: %s\n", book.title);
    printf("Год издания: %d\n", book.year);
    printf("Цена: %.2f\n", book.price);
    printf("Категория: %s\n", book.category);
}

bool input_book(Book& book) {
    int result;

    printf("Введите автора: ");
    result = scanf(" %255[^\n]", book.author);
    if (result != 1) {
        return false;
    }

    printf("Введите название: ");
    result = scanf(" %255[^\n]", book.title);
    if (result != 1) {
        return false;
    }

    printf("Введите год издания: ");
    result = scanf("%d", &book.year);
    if (result != 1) {
        return false;
    }
    if (book.year < 1450 || book.year > 2100) {
        cerr << "Некорректный год издания.\n";
        return false;
    }

    printf("Введите цену: ");
    result = scanf("%lf", &book.price);
    if (result != 1) {
        return false;
    }
    if (book.price < 0) {
        cerr << "Цена не может быть отрицательной.\n";
        return false;
    }

    printf("Введите категорию: ");
    result = scanf(" %255[^\n]", book.category);
    if (result != 1) {
        return false;
    }

    return true;
}
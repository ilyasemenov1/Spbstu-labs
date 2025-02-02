#include "book.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define VALIDATE_RES(res) if (res != 1) return false;

void print_book(const Book* book) {
    printf("Автор: %s\n", book->author);
    printf("Название: %s\n", book->title);
    printf("Год издания: %d\n", book->year);
    printf("Цена: %.2f\n", book->price);
    printf("Категория: %s\n", book->category);
}

bool input_book(Book* book) {
    int res;

    printf("Введите автора: ");
    res = scanf(" %255[^\n]", book->author);
    VALIDATE_RES(res)

    printf("Введите название: ");
    res = scanf(" %255[^\n]", book->title);
    VALIDATE_RES(res)

    printf("Введите год издания: ");
    res = scanf("%d", &book->year);
    VALIDATE_RES(res)
    if (book->year < 1450 || book->year > 2100) {
        printf("Некорректный год издания.\n");
        return false;
    }

    printf("Введите цену: ");
    res = scanf("%lf", &book->price);
    VALIDATE_RES(res)
    if (book->price < 0) {
        printf("Цена не может быть отрицательной.\n");
        return false;
    }

    printf("Введите категорию: ");
    res = scanf(" %255[^\n]", book->category);
    VALIDATE_RES(res)

    return true;
}
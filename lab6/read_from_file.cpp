
#include "app.h"
#include <cstdio>
#include <cstring>

void read_from_file(Lib *lib) {

    char* fake1 = read_line();
    printf("Введите название файла: ");
    char* filename = read_line();
    delete[] fake1;

    filename[strcspn(filename, "\n")] = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка при чтении файла.\n");
        return;
    }

    char title[500], author[300], genre[100], description[1000];
    int year, number;
    int line = 1;
    int index = 0;

    while(!feof(file)) {
        int res = fscanf(file, "Название: %[^\n]\nАвтор: %[^\n]\nГод издания: %d\nЖанр: %[^\n]\nОписание: %[^\n]\nНомер: %d\n", title, author, &year, genre, description, &number);
        if (res == 6) {
            if (lib->size >= lib->capacity) resize_lib(lib);
            lib->books[index].title = transform_line(title);
            lib->books[index].author = transform_line(author);
            lib->books[index].year = year;
            lib->books[index].genre = transform_line(genre);
            lib->books[index].description = transform_line(description);
            lib->books[index].number = number;
            lib->size = ++index;
        } else if (res == EOF) {
            break;
        } else {
            printf("Ошибка форматирования файла в строке %d.\n", line);
            break;
        }
        line += 7;
    }
    fclose(file);

    delete[] filename;
    printf("Библиотека книг успешно загружена!\n");
}
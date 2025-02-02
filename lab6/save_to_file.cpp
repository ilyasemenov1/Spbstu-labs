
#include "app.h"
#include <cstdio>
#include <cstring>

void save_to_file(const Lib *lib) {

    if (lib->size == 0) {
        printf("На данный момент в вашей библиотеке нет книг, чтобы загрузить их в файл. Довавьте книги или загрузите их из файла.\n");
        return;
    }

    char* fake1 = read_line();
    printf("Введите название файла: ");
    char* filename = read_line();
    delete[] fake1;

    filename[strcspn(filename, "\n")] = 0;

    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка при открытии файла.\n");
        return;
    }
    for (int i = 0; i < lib->size; ++i) {
        fprintf(file, "Название: %s\nАвтор: %s\nГод издания: %i\nЖанр: %s\nОписание: %s\nНомер: %i\n\n", lib->books[i].title, lib->books[i].author, lib->books[i].year, lib->books[i].genre, lib->books[i].description, lib->books[i].number);
    }

    fclose(file);
    printf("Библиотека книг успешно загружена в файл!\n");

    delete[] filename; 
}

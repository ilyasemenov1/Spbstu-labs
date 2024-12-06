
#include <iostream>
#include <cstring>

using namespace std;

char* readLine() {
    int capacity = 10;
    int length = 0;
    char* buffer = new char[capacity];
    char c;

    while (cin.get(c)) {
        if (c == '\n') break;

        if (length + 1 >= capacity) {
            capacity *= 2;
            char* new_buffer = new char[capacity];
            strcpy(new_buffer, buffer);
            delete[] buffer;
            buffer = new_buffer;
        }

        buffer[length++] = c;
    }

    return buffer;
}

int main() {
    cout << "Введите строку: ";
    char* input = readLine();
    cout << "Вы ввели: " << input << ' ' << strlen(input) << endl;

    delete[] input;
    return 0;
}
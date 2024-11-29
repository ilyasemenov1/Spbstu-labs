#include "other.h"
#include <codecvt>
#include <iostream>
#include <iomanip>

using namespace std;

int incByValue(int number) {
    return number + 1;
}

int incByPointer(int* number) {
    return (*number) + 1;
}

int incByReference(int &number) {
    return number + 1;
}

void swapPtr(int* ptrA, int* ptrB) {
    int buf = *ptrA;
    *ptrA = *ptrB;
    *ptrB = buf;
}

void swapRef(int &refA, int &refB) {
    int buf = refA;
    refA = refB;
    refB = buf;
}

int minInArray(const int* arr, const int arrSize) {
    if (arrSize) return -2;

    int min = 1000;
    for (int i = 0; i < arrSize; i++) {
        min = *(arr + i) < min ? *(arr + i) : min;
    }

    return min;
}

int minIn2DArray(const int* arr, const int arrRows, const int arrColums) {
    if (arrRows < 1 || arrColums < 1) return -2;

    int min = 1000;
    for (int i = 0; i < arrRows; i++) {
        int minLow = minInArray(arr + i * arrColums,arrColums );
        min = minLow < min ? minLow : min;
    }

    return min;
}

int myStrCmp(const char* str1, const char* str2) {
    
    while (*str1 != 0 && *str2 != 0 && *str1 == *str2) {
        str1++;
        str2++;
    }

    int x = *str1 - *str2;

    return (x > 0) - (x < 0);
}

bool isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }

int dayOfYear(int day, int month, int year, int* table) {
    int isLeap = isLeapYear(year);
    int dayNumber = 0;

    for (int i = 0; i < month; i++) dayNumber += *(table + 12 * isLeap + i);

    return dayNumber + day;
}

int* dayOfMonth(int dayOfTheYear, int year, int* table) {
    int isLeap = isLeapYear(year);
    int i = 0;

    while (dayOfTheYear - *(table + i) >= 0) {
        dayOfTheYear -= *(table + i);
        i++;
    }

    int* monthData = new int[2];
    monthData[0] = dayOfTheYear;
    monthData[1] = i + 1;

    return monthData;
}

void addUnique(int* arr, int i, int n, int newValue) {
    bool isUnic = true;
    for (int j = 0; j < n; j++) if (arr[j] == newValue) isUnic = false;
    if (isUnic) arr[i] = newValue;
}

void printArray(int* arr, int n) {
    const int WIDTH = 20;

    for (int j = 0; j * WIDTH < n; j++) {
        cout << j * WIDTH + 1 << '-' << min((j + 1) * WIDTH, n) << ":";
        for (int i = j * WIDTH; i < min(WIDTH * (j + 1), n); i++) {
            cout << ' ' << arr[i];
        }
        cout << endl;
    }
}

int sumN(int n) {
    return n > 1 ? n + sumN(n - 1) : 1;
}

const char table[32] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', '1', '2', '3', '4', '5', '6'
};

// int encoded32_size(int raw_size) {

// }
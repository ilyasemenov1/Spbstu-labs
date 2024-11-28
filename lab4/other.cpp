#include "other.h"
#include <codecvt>

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

int dayOfYear(int day, int month, int year, int table[2][12]) {
    int isLeap = isLeapYear(year);
    int dayNumber = 0;

    for (int i = 0; i < month; i++) dayNumber += table[isLeap][i];

    return dayNumber + day;
}

const char table[32] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', \
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', \
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', \
    'Y', 'Z', '1', '2', '3', '4', '5', '6'
};

// int encoded32_size(int raw_size) {

// }
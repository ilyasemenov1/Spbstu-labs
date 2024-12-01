#include "other.h"
#include <codecvt>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <string.h>

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

const char ENCODE_TABLE[32] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', '1', '2', '3', '4', '5', '6'
};

int* generateDecodeTable(char* encodeTable) {
    int* decodeTable = new int[32];
    for (int i = 0; i < 32; ++i) decodeTable[i] = -1;
    for (int i = 0; i < 32; ++i) {
        decodeTable[(unsigned char)(encodeTable[i])] = i;
    }

    return decodeTable;
}

int encoded32Size(int rawSize) {
    return (rawSize * 8) / 5 + 1;
}

int decoded32Size(int encodeSize) {
    return (encodeSize * 5) / 8;
}

int encode32(char* rawData, int rawSize, char* dst) {
    if (!rawData || rawSize <= 0 || !dst) return 1;

    int bitLineBuffer = 0;
    int bitLineSize = 0;
    int dstIndex = 0;

    for (int i = 0; i < rawSize; ++i) {
        char symbol = rawData[i];
        bitLineBuffer = (bitLineBuffer << 8) | (unsigned char) symbol;
        bitLineSize += 8;

        while (bitLineSize >= 5) {
            bitLineSize -= 5;
            int encodeTableSymbolIndex = (bitLineBuffer >> bitLineSize) & 0x1F;
            dst[dstIndex++] = ENCODE_TABLE[encodeTableSymbolIndex];
        }
    }

    if (bitLineSize > 0) {
        int encodeTableSymbolIndex = (bitLineBuffer << (5 - bitLineSize)) & 0x1F;
        dst[dstIndex] = ENCODE_TABLE[encodeTableSymbolIndex];
    }

    return 0;
}

int decode32(char* encodedData, int encodedSize, char* dst) {
    if (!encodedData || encodedSize <= 0 || !dst) return 1;
    const int* DECODE_TABLE = generateDecodeTable((char*) ENCODE_TABLE);

    int bitLineBuffer = 0;
    int bitLineSize = 0;
    int dstIndex = 0;


    for (int i = 0; dstIndex < encodedSize; ++i) {
        char symbol = encodedData[i];
        int value = DECODE_TABLE[(unsigned char) symbol];
        if (value == -1) return 2;

        bitLineBuffer = (bitLineBuffer << 5) | value;
        bitLineSize += 5;

        while (bitLineSize >= 8) {
            bitLineSize -= 8;
            dst[dstIndex++] = (bitLineBuffer >> bitLineSize) & 0xFF;
        } 

    }

    delete[] DECODE_TABLE;

    return 0;
}

char* encodeString(char* string) {
    int rawSize = strlen(string);
    int encodedSize = encoded32Size(rawSize);
    
    char* encodedStrig = new char[encodedSize];

    int key = encode32(string, rawSize, encodedStrig);

    for (int i = 0; i < encodedSize; i++) {
        cout << encodedStrig[i];
    }
    cout << endl;

    cout << "Encoding finished with exit code " << key << '.' << endl;

    return encodedStrig;
}

char* decodeString(char* encodedStrig) {
    int decodedSize = decoded32Size(strlen(encodedStrig));
    char* decodedString = new char[decodedSize];

    int key = decode32(encodedStrig, decodedSize, decodedString);

    for (int i = 0; i < decodedSize; i++) {
        cout << decodedString[i];
    }
    cout << endl;

    cout << "Decoding finished with exit code " << key << '.' << endl;

    return decodedString;
}
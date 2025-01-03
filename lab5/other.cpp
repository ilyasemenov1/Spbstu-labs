#include "other.h"
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void sort(char* pcFirst, int nNumber, int size,
     void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
    int i;
    for(i=1; i<nNumber; i++)
        for(int j=nNumber-1; j>=i; j--)
        {
            char* pCurrent = pcFirst+j*size;
            char* pPrevious = pcFirst+(j-1)*size;
            if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
                                                //переставить
                (*Swap)( pPrevious, pCurrent );
        }
}

void swap_int(void* p1, void* p2) {
    int temp = *(static_cast<int*>(p1));
    *(static_cast<int*>(p1)) = *(static_cast<int*>(p2));
    *(static_cast<int*>(p2)) = temp;
}

int cmp_int(void* p1, void* p2) {
    return *(static_cast<int*>(p1)) - *(static_cast<int*>(p2));
}

void swap_double(void* p1, void* p2) {
    double temp = *(static_cast<double*>(p1));
    *(static_cast<double*>(p1)) = *(static_cast<double*>(p2));
    *(static_cast<double*>(p2)) = temp;
}

int cmp_double(void* p1, void* p2) {
    double diff = *(static_cast<double*>(p1)) - *(static_cast<double*>(p2));
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

void swap_str(void* p1, void* p2) {
    const char* temp = *(static_cast<const char**>(p1));
    *(static_cast<const char**>(p1)) = *(static_cast<const char**>(p2));
    *(static_cast<const char**>(p2)) = temp;
}

int cmp_str(void* p1, void* p2) {
    const char* str1 = *(static_cast<const char* const*>(p1));
    const char* str2 = *(static_cast<const char* const*>(p2));
    return strcmp(str1, str2);
}

double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mul(double x, double y) {
    return x * y;
}

double div(double x, double y) {
    return (y != 0) ? x / y : 0;
}

void print_max(int* arr, int size) {
    if (arr == nullptr || size <= 0) return;
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Максимальный элемент: " << max << endl;
}

void print_min(int* arr, int size) {
    if (arr == nullptr || size <= 0) return;
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Минимальный элемент: " << min << endl;
}

void sort_asc(int* arr, int size) {
    if (arr == nullptr || size <= 0) return;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Массив, отсортированный по возрастанию: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort_desc(int* arr, int size) {
    if (arr == nullptr || size <= 0) return;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Массив, отсортированный по убыванию: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
double integrate(double (*f)(double), double a, double b, int n) {
    if (n <= 0) return 0;

    double h = (b - a) / n;
    double integral = 0;

    for (int i = 0; i < n; ++i) {
        integral += f(a + i * h) * h;
    }

    return integral;
}

double linear(double x) { return 2 * x + 3; }
double parabola(double x) { return x * x - 4 * x + 5; }
#include "other.h"
#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdarg>

using namespace std;

int inc_by_value(int number) {
    return number + 1;
}

int inc_by_pointer(int* number) {
    return (*number) + 1;
}

int inc_by_reference(int &number) {
    return number + 1;
}

void swap_ptr(int* ptr_a, int* ptr_b) {
    int buf = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = buf;
}

void swap_ref(int &ref_a, int &ref_b) {
    int buf = ref_a;
    ref_a = ref_b;
    ref_b = buf;
}

int min_in_array(const int* arr, const int arr_size) {
    if (arr_size) return -2;

    int min = 1000;
    for (int i = 0; i < arr_size; i++) {
        min = *(arr + i) < min ? *(arr + i) : min;
    }

    return min;
}

int min_in_2d_array(const int* arr, const int arr_rows, const int arr_colums) {
    if (arr_rows < 1 || arr_colums < 1) return -2;

    int min = 1000;
    for (int i = 0; i < arr_rows; i++) {
        int minLow = min_in_array(arr + i * arr_colums,arr_colums );
        min = minLow < min ? minLow : min;
    }

    return min;
}

int my_str_cmp(const char* str1, const char* str2) {
    
    while (*str1 != 0 && *str2 != 0 && *str1 == *str2) {
        str1++;
        str2++;
    }

    int x = *str1 - *str2;

    return (x > 0) - (x < 0);
}

bool is_leap_year(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }

int day_of_year(int day, int month, int year, int* table) {
    int is_leap = is_leap_year(year);
    int day_number = 0;

    for (int i = 0; i < month; i++) day_number += *(table + 12 * is_leap + i);

    return day_number + day;
}

int* day_of_month(int day_of_the_year, int year, int* table) {
    int is_leap = is_leap_year(year);
    int i = 0;

    while (day_of_the_year - *(table + i) >= 0) {
        day_of_the_year -= *(table + i);
        i++;
    }

    int* month_data = new int[2];
    month_data[0] = day_of_the_year;
    month_data[1] = i + 1;

    return month_data;
}

void add_unique(int* arr, int i, int n, int new_value) {
    bool isUnic = true;
    for (int j = 0; j < n; j++) if (arr[j] == new_value) isUnic = false;
    if (isUnic) arr[i] = new_value;
}

void print_array(int* arr, int n) {
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

int DECODE_TABLE[256];

void generate_decode_table() {
    for (int i = 0; i < 256; ++i) DECODE_TABLE[i] = -1; 
    for (int i = 0; i < 32; ++i) DECODE_TABLE[(int) ENCODE_TABLE[i]] = i;
}

int encoded32_size(int rawSize) {
    return (rawSize * 8) / 5 + 1;
}

int decoded32_size(int encodeSize) {
    return (encodeSize * 5) / 8;
}

int encode32(char* raw_data, int raw_size, char* dst) {
    if (!raw_data || raw_size <= 0 || !dst) return 1;

    int bit_line_buffer = 0;
    int bit_line_size = 0;
    int dst_index = 0;

    for (int i = 0; i < raw_size; ++i) {
        char symbol = raw_data[i];
        bit_line_buffer = (bit_line_buffer << 8) | (unsigned char) symbol;
        bit_line_size += 8;

        while (bit_line_size >= 5) {
            bit_line_size -= 5;
            int encode_table_symbol_index = (bit_line_buffer >> bit_line_size) & 0x1F;
            dst[dst_index++] = ENCODE_TABLE[encode_table_symbol_index];
        }
    }

    if (bit_line_size > 0) {
        int encodeTableSymbolIndex = (bit_line_buffer << (5 - bit_line_size)) & 0x1F;
        dst[dst_index] = ENCODE_TABLE[encodeTableSymbolIndex];
    }

    return 0;
}

int decode32(char* encoded_data, int encoded_size, char* dst) {
    if (!encoded_data || encoded_size <= 0 || !dst) return 1;

    generate_decode_table();

    int bit_line_buffer = 0;
    int bit_line_size = 0;
    int dst_index = 0;

    for (int i = 0; dst_index < encoded_size; ++i) {
        char symbol = encoded_data[i];
        int value = DECODE_TABLE[(unsigned char) symbol];
        if (value == -1) return 2;

        bit_line_buffer = (bit_line_buffer << 5) | value;
        bit_line_size += 5;

        while (bit_line_size >= 8) {
            bit_line_size -= 8;
            dst[dst_index++] = (bit_line_buffer >> bit_line_size) & 0xFF;
        } 
    }

    return 0;
}

char* encode_string(char* string) {
    int raw_size = strlen(string);
    int encoded_size = encoded32_size(raw_size);
    
    char* encoded_strig = new char[encoded_size];

    int key = encode32(string, raw_size, encoded_strig);

    for (int i = 0; i < encoded_size; ++i) {
        cout << encoded_strig[i];
    }
    cout << endl;

    cout << "Encoding finished with exit code " << key << '.' << endl;

    return encoded_strig;
}

char* decode_string(char* encoded_strig) {
    int decoded_size = decoded32_size(strlen(encoded_strig));
    char* decoded_string = new char[decoded_size];

    int key = decode32(encoded_strig, decoded_size, decoded_string);

    for (int i = 0; i < decoded_size; ++i) {
        cout << decoded_string[i];
    }
    cout << endl;

    cout << "Decoding finished with exit code " << key << '.' << endl;

    return decoded_string;
}

void var_args(int nN1, ...) {
    if (nN1 == 0) {
        cout << "No arguments provided." << endl;
        return;
    }

    va_list args;
    va_start(args, nN1);

    int args_count = 0;
    int value = nN1;

    while (value != 0) {
        cout << value << " ";
        args_count++;
        value = va_arg(args, int);
    }

    va_end(args);

    cout << "\nNumber of arguments: " << args_count << endl;
}

int* my_min(int* arr, int arr_size) {
    if (arr_size <= 0) return nullptr;

    int* min_ptr = arr;
    for (int i = 1; i < arr_size; ++i) {
        if (arr[i] < *min_ptr) min_ptr = &arr[i];
    }
    return min_ptr;
}
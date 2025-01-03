#include <cctype>
#include <cstring>
#include "alg.h"

using namespace std;

char enter_new_char(const char* text, char base, int shift, int alpha, int i) {
    return (char)(((text[i] - base + shift) % alpha + alpha) % alpha + base);
}

void caesar_cipher(const char* text, int shift, char* dst) {
    int len = strlen(text);
    for (int i = 0; i < len; ++i) {
        if (isalpha(text[i])) {
            char base = (islower(text[i])) ? 'a' : 'A';
            dst[i] = enter_new_char(text, base, shift, 26, i);
        } else if (text[i] >= 32 && text[i] <= 64) {
            dst[i] = enter_new_char(text, 32, -shift * 2, 32, i);
        }
    }
}
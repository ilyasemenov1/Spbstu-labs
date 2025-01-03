
#include <cstddef>
#include <iostream>
#include <cctype>
#include <cstring>
#include "alg.h"


using namespace std;

int main() {
    const char* text = "Sid Meier's Civilization VI is a 2016 4X turn-based strategy video game developed by Firaxis Games and published by 2K. The mobile and Nintendo Switch port was published by Aspyr Media. The latest entry into the Civilization series, it was released on Windows and macOS in October 2016, with later ports for Linux in February 2017, iOS in December 2017, Nintendo Switch in November 2018, PlayStation 4 and Xbox One in November 2019, and Android in 2020. ";
    int shift = 5;

    char* encoded = new char[strlen(text)];
    caesar_cipher(text, shift, encoded);

    cout << encoded << endl;

    char* decoded = new char[strlen(text)];
    caesar_cipher(encoded, -shift, decoded);

    cout << decoded << endl;

    delete [] encoded;
    encoded = nullptr;

    delete [] decoded;
    decoded = nullptr;

    return 0;
}

#define MAX_STR_LEN 256

struct Book {
    char author[MAX_STR_LEN];
    char title[MAX_STR_LEN];
    int year;
    double price;
    char category[MAX_STR_LEN];
};

bool input_book(Book&);
void print_book(const Book&);
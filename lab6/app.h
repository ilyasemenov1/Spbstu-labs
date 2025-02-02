
#define INIT_CAPCITY 10
#define GROWTH_FACTOR 2

struct Book {
    char* title;
    char* author;
    int year;
    char* genre;
    char* description;
    int number;
};

struct Lib {
    Book* books;
    int size;
    int capacity;
};

char* read_line();
bool add_book(Lib* lib);
void print_library(const Lib* lib);
void init_lib(Lib* lib);
void resize_lib(Lib *lib);
void edit_library(Lib* lib);
void book_free(Book* book);
void delete_book_by_name(Lib* lib);
void save_to_file(const Lib *lib);
void read_from_file(Lib *lib);
void print_book(Book book);
void open_search(const Lib* lib);
void open_sort(Lib* lib);
char* transform_line(char line[]);
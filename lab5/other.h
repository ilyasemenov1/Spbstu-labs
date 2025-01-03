
//Прототипы используемых в данном задании функций:

void sort(char* pcFirst, int nNumber, int size,
     void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void swap_int(void* p1, void* p2);
int cmp_int(void* p1, void* p2);
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);
int cmp_double(void* p1, void* p2);
void swap_double(void* p1, void* p2);
void swap_str(void* p1, void* p2);
int cmp_str(void* p1, void* p2);

typedef void (*ArrayFunction)(int*, int);

void print_max(int* arr, int size);
void print_min(int* arr, int size);
void sort_asc(int* arr, int size);
void sort_desc(int* arr, int size);

double integrate(double (*f)(double), double a, double b, int n);
double linear(double x);
double parabola(double x);
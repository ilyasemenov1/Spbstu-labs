
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
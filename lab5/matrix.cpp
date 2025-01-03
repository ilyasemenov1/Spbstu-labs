#include "matrix.h"
#include <cstring>

using namespace std;

void m_zero(Matrix* A, int m, int n) {
    if (A == nullptr) return;

    A->rows = m;
    A->cols = n;
    A->data = new double[m * n]{};
}

void m_id(Matrix* A, int n) {
    m_zero(A, n, n);
    for (int i = 0; i < n; ++i) {
        m_set(A, i, i, 1);
    }
}

void m_free(Matrix* A) {
    delete[] A->data;
    A->data = nullptr;
    A->rows = 0;
    A->cols = 0;
}

void m_copy(const Matrix* src, Matrix* dst) {
    if (src->rows != dst->rows || src->cols != dst->cols) return;
    memcpy(dst->data, src->data, src->rows * src->cols * sizeof(double));
}

int m_width(const Matrix* A) { return (A != nullptr) ? A->cols : 0; }
int m_height(const Matrix* A) { return (A != nullptr) ? A->rows : 0; }

double m_get(const Matrix* A, int i, int j) {
    if (i < 0 || i >= A->rows || j < 0 || j >= A->cols) return 0;
    return A->data[i * A->cols + j];
}

void m_set(Matrix* A, int i, int j, double value) {
     if (i < 0 || i >= A->rows || j < 0 || j >= A->cols) return;
    A->data[i * A->cols + j] = value;
}

int m_add(Matrix* A, const Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) return 1;
    for (int i = 0; i < A->rows * A->cols; ++i) {
        A->data[i] += B->data[i];
    }
    return 0;
}

void m_neg(Matrix* A) {
    for (int i = 0; i < A->rows * A->cols; ++i) {
        A->data[i] = -A->data[i];
    }
}

int m_mult(const Matrix* A, const Matrix* B, Matrix* dst) {
    if (A->cols != B->rows) return 1;

    m_zero(dst, A->rows, B->cols);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->cols; ++j) {
            for (int k = 0; k < A->cols; ++k) {
                m_set(dst, i, j, m_get(dst, i, j) + m_get(A, i, k) * m_get(B, k, j));
            }
        }
    }
    return 0;
}
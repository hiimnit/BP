#ifndef CMATRIX_CSR_H
#define CMATRIX_CSR_H

#include <iostream>
#include "CMatrix_COO.h"

using namespace std;

class CMatrix_CSR : public CMatrix {
    int * line_count, * pos;
    float * values;
public:
    CMatrix_CSR();
    virtual ~CMatrix_CSR();
    virtual void print();
    virtual bool add(int, int, float) {return false;};
    bool COO2CSR(CMatrix_COO *);
};

#endif // CMATRIX_CSR_H

#ifndef CMATRIX_COO_H
#define CMATRIX_COO_H

#include <iostream>
#include "CMatrix.h"

using namespace std;

class CMatrix_COO : public CMatrix {
//    AOS vs SOA
//    int * x, * y;
//    float * v;
    struct CPoint {
        int x, y;
        float value;
        CPoint(int x, int y, float val) : x(x), y(y), value(val) {};
    };
    CPoint ** p;
public:
    CMatrix_COO(int, int);
    virtual ~CMatrix_COO();
    virtual void print();
    virtual bool add(int, int, float);
    float getPoint(int, int *, int *);
};

#endif // CMATRIX_COO_H

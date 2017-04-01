#ifndef CMATRIX_H
#define CMATRIX_H

class CMatrix {
protected:
    int row_l, col_l, no_nonzeroes;
public:
    CMatrix(int, int);
    virtual ~CMatrix();
    virtual bool add(int, int, float) = 0;
    virtual void print() = 0;
    int getNoRows() const { return row_l; }
    int getNoCols() const { return col_l; }
    int getNoNonzeroes() const { return no_nonzeroes; }
};

#endif // CMATRIX_H

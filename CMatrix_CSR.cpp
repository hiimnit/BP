#include "CMatrix_CSR.h"

CMatrix_CSR::CMatrix_CSR() : CMatrix(0, 0) {
}

CMatrix_CSR::~CMatrix_CSR() {
    delete line_count;
    delete pos;
    delete values;
}

void CMatrix_CSR::print() {
    // line count - no. points on row // size = no. columns
    // pos - point's position on row // size = no. nonzeroes
    cout << "CSR: " << row_l << "x" << col_l << endl;
    cout << "size: " << no_nonzeroes << endl;
    
    cout << "line_count: ";
    for(int i = 0; i < col_l; ++i) cout << line_count[i] << ' ';
    
    cout << endl << "pos: ";
    for(int i = 0; i < no_nonzeroes; ++i) cout << pos[i] << ' ';
    
    cout << endl;
    
    int x = 0, p = 0;
    for(int i = 0; i < col_l; ++i) {
        for(int j = x; j < x + line_count[i]; ++j) {
            p = pos[j];
            for(int k = 0; k < p; ++k) {
                cout << 0 << ' ';
            }
            cout << values[j] << ' ';
        }
        x += line_count[i];
        for(int k = p; k < row_l - 1; ++k) {
            cout << 0 << ' ';
        }
        cout << '\n';
    }
}

bool CMatrix_CSR::COO2CSR(CMatrix_COO * matrix) {
    no_nonzeroes = matrix->getNoNonzeroes();
    row_l = matrix->getNoRows();
    col_l = matrix->getNoCols();
    
    line_count = new int[col_l];
    pos = new int[no_nonzeroes];
    values = new float[no_nonzeroes];
    
    int line_c = 0, curr_row = 0, x, y;
    float val;
    for(int i = 0; i < no_nonzeroes; ++i) {
        val = matrix->getPoint(i, &x, &y);
        while(curr_row < y) {
            line_count[curr_row] = line_c;
            line_c = 0;
            curr_row++;
        }
        line_c++;
        values[i] = val;
        pos[i] = x;
    }
    line_count[curr_row] = line_c;
    
    return true;
}


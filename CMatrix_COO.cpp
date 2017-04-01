#include "CMatrix_COO.h"

CMatrix_COO::CMatrix_COO(int n, int m) : CMatrix(n, m) {
    p = new CPoint*[n * m];
}

CMatrix_COO::~CMatrix_COO() {
    for(int i = 0; i < no_nonzeroes; ++i) {
        delete p[i];
    }
    delete p;
}

void CMatrix_COO::print() {
    cout << "COO: " << row_l << "x" << col_l << endl;
    cout << "size: " << no_nonzeroes << endl;
    
    int pos, last_pos = 0, new_line = row_l;
    for(int i = 0; i < no_nonzeroes; ++i) {
        pos = (p[i]->y) * row_l + p[i]->x;
        for (int j = 0; j < pos - last_pos - 1; ++j, --new_line) {
            if (!new_line) {
                cout << '\n'; 
                new_line = row_l;
            }
            cout << 0 << ' ';
        }
        cout << p[i]->value << ' ';
        last_pos = pos;
        --new_line;
    }
    cout << '\n';
}

bool CMatrix_COO::add(int x, int y, float val) {
    if (x >= row_l || y >= col_l) return false;
    p[no_nonzeroes++] = new CPoint(x, y, val);
    return true;
}

float CMatrix_COO::getPoint(int pos, int * n, int * m) {
    *n = p[pos]->x;
    *m = p[pos]->y;
    return p[pos]->value;
}


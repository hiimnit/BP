#include <stdio.h>
#include "CMatrix_COO.h"
#include "CMatrix_CSR.h"

using namespace std;

bool PII_LUDecomposition(float m[sz][sz], int n, double &det, int* ri, int* irow) {
    // Factors "m" matrix into A=LU where L is lower triangular and U is upper
    // triangular. The matrix is overwritten by LU with the diagonal elements
    // of L (which are unity) not stored. This must be a square n x n matrix.
    // ri[n] and irow[n] are scratch vectors used by LUBackSubstitution.
    // d is returned +-1 indicating that the
    // number of row interchanges was even or odd respectively.
    
    int i, j, k;
    int size, last, end, pe;
    int last8, end8, pe8;
    float frcp, tmp, pivel;
    
    float *ptr2, *ptr;
    float* pdata = m[0];
    det = 1.0;
    
    // Initialize the pointer vector.
    for (i = 0 ; i < n; i++)
        ri[i] = i;
    
    // LU factorization.
    for (int p = 1 ; p <= n - 1; p++) {
        // Find pivot element.
        for (i = p + 1 ; i <= n; i++) {
            if (Abs(m[ri[i-1]][p-1]) > Abs(m[ri[p-1]][p-1])) {
                // Switch the index for the p-1 pivot row if necessary.
                int t = ri[p-1];
                ri[p-1] = ri[i-1];
                ri[i-1] = t;
                det = -det;
            }
        }
        if (m[ri[p-1]][p-1] == 0) {
            // The matrix is singular.
            return false;
        }
        
        // Multiply the diagonal elements.
        det = det * m[ri[p-1]][p-1];
        
        // Form multiplier.
        for (i = p + 1 ; i <= n; i++) {
            m[ri[i-1]][p-1] /= m[ri[p-1]][p-1];
            
            // Eliminate [p-1].
            for (int j = p + 1 ; j <= n; j++)
                m[ri[i-1]][j-1] -= m[ri[i-1]][p-1] * m[ri[p-1]][j-1];
        }
    }
    
    det = det * m[ri[n-1]][n-1];
    return det != 0.0;
}

int main(int argc, char **argv) {
	CMatrix_COO * m1 = new CMatrix_COO(4, 4);
    
    m1->add(0, 0, 5.0);
    m1->add(1, 1, 5.0);
    m1->add(2, 2, 5.0);
    m1->add(3, 3, 5.0);
    
    m1->print();
    
    CMatrix_CSR * m2 = new CMatrix_CSR();
    
    m2->COO2CSR(m1);
    
    m2->print();
    
    delete m1;
    delete m2;
    return 0;
}

#include <stdio.h>
#include <cmath>
#include "CMatrix_COO.h"
#include "CMatrix_CSR.h"

using namespace std;

bool PII_LUDecomposition(float m[3][3], int n, double &det, int * ri) {
    // Factors "m" matrix into A=LU where L is lower triangular and U is upper
    // triangular. The matrix is overwritten by LU with the diagonal elements
    // of L (which are unity) not stored. This must be a square n x n matrix.
    // ri[n] and irow[n] are scratch vectors used by LUBackSubstitution.
    // d is returned +-1 indicating that the
    // number of row interchanges was even or odd respectively.
    
    det = 1.0;
    
    // Initialize the pointer vector.
    for (int i = 0; i < n; i++)
        ri[i] = i;
    
    // LU factorization.
    // for (int p = 1; p <= n - 1; p++) {
    for (int p = 0; p < n - 1; p++) {
        // Find pivot element.
        /*
        for (int i = p + 1; i <= n; i++) {
            if (fabs(m[ri[i-1]][p-1]) > fabs(m[ri[p-1]][p-1])) {
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
        */
        
        // Multiply the diagonal elements.
        //det = det * m[p-1][p-1];
        det = det * m[p][p];
        
        // Form multiplier.
        // for (int i = p + 1; i <= n; i++) {
        for (int i = p + 1; i < n; i++) {
            // m[ri[i-1]][p-1] /= m[ri[p-1]][p-1];
            m[i][p] /= m[p][p];
            
            // Eliminate [p-1].
            // for (int j = p + 1; j <= n; j++)
            for (int j = p + 1; j < n; j++)
                // m[ri[i-1]][j-1] -= m[ri[i-1]][p-1] * m[ri[p-1]][j-1];
                m[i][j] -= m[i][p] * m[p][j];
        }
    }
    
    det = det * m[ri[n-1]][n-1];
    return det != 0.0;
}

int main(int argc, char **argv) {
	double det;
    float m[3][3];
    int r[3];
    
    m[0][0] =  5;
    m[0][1] =  8;
    m[0][2] = -1;
    m[1][0] =  1;
    m[1][1] = -2;
    m[1][2] =  3;
    m[2][0] =  2;
    m[2][1] =  1;
    m[2][2] =  1;
    
    
    cout << m[0][0] << ' ' << m[0][1] << ' ' << m[0][2] << endl; 
    cout << m[1][0] << ' ' << m[1][1] << ' ' << m[1][2] << endl; 
    cout << m[2][0] << ' ' << m[2][1] << ' ' << m[2][2] << endl; 
    
    cout << "-------------------------------------------" << endl;
    
    PII_LUDecomposition(m, 3, det, r);
    
    cout << m[0][0] << ' ' << m[0][1] << ' ' << m[0][2] << endl; 
    cout << m[1][0] << ' ' << m[1][1] << ' ' << m[1][2] << endl; 
    cout << m[2][0] << ' ' << m[2][1] << ' ' << m[2][2] << endl; 
    
    /*
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
    */
    return 0;
}

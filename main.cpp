#include <stdio.h>
#include "CMatrix_COO.h"
#include "CMatrix_CSR.h"

using namespace std;

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

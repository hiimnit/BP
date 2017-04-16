#include <stdio.h>
#include <cmath>
#include <iostream>

#define SIZE 25
#define N 5
#define MIN(a, b) (a < b ? a : b)

using namespace std;

float m_i[SIZE];
float m_l[SIZE];
float m_o[SIZE];

/*
for k = 1 to min(i, j) − 1
    recv broadcast of akj from task (k, j)
    recv broadcast of lik from task (i, k)
    aij = aij − lik akj
end
if i ≤ j then
    broadcast aij to tasks (k, j), k = i + 1, . . . , n
else
    recv broadcast of ajj from task (j, j)
    lij = aij/ajj
    broadcast lij to tasks (i, k), k = j + 1, . . . , n
end
*/
int FG(int i, int j) {
    m_o[i * N + j] = m_i[i * N + j];
    for(int k = 0; k < MIN(i, j); ++k) {
        m_o[i * N + j] -= m_o[k * N + j] * m_l[i * N + k];
    }

    if(i <= j) {
        // send = save to m_o
    } else {
        // recv
        m_l[i * N + j] = m_o[i * N + j] / m_o[j * N + j];
        // send = save to m_l
    }

    return 0;
}


int main(int argc, char **argv) {
    int x;
    for(int i = 0; i < SIZE; ++i) {
        m_l[i] = 0;
        m_o[i] = 0;
    }

    m_i[0]  = 5; m_i[1]  = 4; m_i[2]  = 3; m_i[3]  = 4; m_i[4]  = 5;
    m_i[5]  = 3; m_i[6]  = 9; m_i[7]  = 1; m_i[8]  = 4; m_i[9]  = 2;
    m_i[10] = 4; m_i[11] = 5; m_i[12] = 7; m_i[13] = 6; m_i[14] = 2;
    m_i[15] = 3; m_i[16] = 5; m_i[17] = 2; m_i[18] = 1; m_i[19] = 2;
    m_i[20] = 2; m_i[21] = 1; m_i[22] = 4; m_i[23] = 3; m_i[24] = 6;

    for(int i = 0; i < SIZE; ++i) {
        FG(i % N, i / N);
        cout << i % N << ' ' << i / N << endl;
    }


    cout << "=============================" << endl;
    cout << "m_o: ";
    for(int i = 0; i < SIZE; ++i) {
        if(i % N == 0) cout << endl;
        cout << m_o[i] << ' ';
    }

    cout << endl << "=============================" << endl;
    cout << "m_l: ";
    for(int i = 0; i < SIZE; ++i) {
        if(i % N == 0) cout << endl;
        cout << m_l[i] << ' ';
    }

    cout << endl;

    return 0;
}

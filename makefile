GXX=g++
FLAGS=-pedantic -Wall -O3 -ffast-math
HPP=CMatrix.h CMatrix_COO.h CMatrix_CSR.h 
CPP=main.cpp CMatrix.cpp CMatrix_COO.cpp CMatrix_CSR.cpp
OUT=o.out
STD=-std=c++11

all:
	$(GXX) $(FLAGS) $(HPP) $(CPP) -o $(OUT) $(STD)
clean:
	rm $(OUT)


all:big vec main
big:BigInt.cpp BigInt.h
	g++ -c BigInt.cpp

vec:MyVector.cpp MyVector.h
	g++ -c MyVector.cpp

main:BigInt.o MyVector.o main.cpp
	g++ main.cpp  BigInt.o MyVector.o

clean:
	rm BigInt.o MyVector.o ./a.out
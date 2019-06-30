all:account save check invest port main
account:Account.cpp Account.h
	g++ -c Account.cpp

port:Portfolio.cpp Portfolio.h
	g++ -c Portfolio.cpp
save:Savings.cpp Savings.h
	g++ -c Savings.cpp
check:Checking.cpp Checking.h
	g++ -c Checking.cpp
invest:Investment.cpp Investment.h
	g++ -c Investment.cpp
main:Account.o Portfolio.o Savings.o Checking.o Investment.o main.cpp
	g++ main.cpp  Account.o Portfolio.o Savings.o Checking.o Investment.o
clean:
	rm Account.o Portfolio.o Savings.o Checking.o Investment.o
	
main.o:account_system.cpp main.cpp account_system.h
	g++ -c main.cpp

account_system:main.o
	g++ main.o -o account_system

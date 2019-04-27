account_system.o:account_system.cpp main.cpp account_system.h
	g++ -c main.cpp

account_system:account_system.o
	g++ account_system.o -o account_system

main.o:account_system.cpp main.cpp account_system.h
	g++ -c main.cpp account_system.cpp

account_system:main.o
	g++ main.o account_system.o -o account_system
clean:
	rm main.o account_system.o

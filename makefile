CC = g++

main: main.o 
	$(CC) main.cpp 

clean:
	rm -f *.o

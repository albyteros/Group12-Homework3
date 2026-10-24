C = g++
CF = -std=c++11 -Wall
OBJS = main.o address.o credit_card.o person.o product.o transaction.o store.o

all: main


main: $(OBJS)
	$(C) $(CF) $(OBJS) -o main

%.o: %.cpp
	$(C) $(CF) -c $< -o $@

.PHONY: all clean
clean:
	rm -f *.o main

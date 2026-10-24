CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJS = main.o address.o credit_card.o person.o product.o transaction.o store.o

all: main


main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o: address.h credit_card.h person.h product.h store.h transaction.h
address.o: address.h
credit_card.o: credit_card.h
person.o: person.h address.h credit_card.h
product.o: product.h
transaction.o: transaction.h person.h product.h
store.o: store.h person.h product.h transaction.h

.PHONY: all clean
clean:
	rm -f $(OBJS) main

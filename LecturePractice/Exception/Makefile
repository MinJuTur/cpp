# Makefile
CC = g++
CCFLAGS = -g

main : main.o Bvector.o BitSet.o Kvector.o
	$(CC) $(CCFLAGS) -o main main.o Bvector.o BitSet.o Kvector.o

BitSet: BitSet.o Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o BitSet BitSet.o Bvector.o Kvector.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<

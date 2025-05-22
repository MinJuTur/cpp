# Makefile
CC = g++
CCFLAGS = -g

Template : main.o team.o
	$(CC) $(CCFLAGS) -o Template main.o team.o
clean:
	rm -f *.o


%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<



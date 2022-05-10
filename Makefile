CC = g++

FLAGS = -c -Wall

OBJS = main.o solver.o

Solver: $(OBJS)
	$(CC) $(OBJS) -o Solver

solver.o: solver.cpp solver.h constants.h main.h
	$(CC) $(FLAGS) solver.cpp

main.o: main.cpp main.h constants.h solver.h
	$(CC) $(FLAGS) main.cpp

clean:
	rm *.o ./Solver
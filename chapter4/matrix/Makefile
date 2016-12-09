CC = g++
CXXFLAGS = -Wall

targets = main
objects = main.o matrix.o 

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

main.o : matrix.h

matrix.o : matrix.h

.PHONY : clean
clean:
	rm $(targets) $(objects)

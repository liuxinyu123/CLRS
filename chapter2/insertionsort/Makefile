CC = g++
CXXFLAGS = -Wall

objects = main.o insertionsort.o
targets = insertionsort

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

main.o : insertionsort.h
insertionsort.o : insertionsort.h

.PHONY : clean
clean:
	rm $(targets) $(objects)

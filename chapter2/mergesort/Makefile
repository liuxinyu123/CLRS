CC = g++
CXXFLAGS = -Wall

objects = main.o mergesort.o printarray.o
targets = mergesort

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

main.o : printarray.h mergesort.h
printarray.o : printarray.h
mergesort.o : mergesort.h

.PHONY : clean
clean:
	rm $(targets) $(objects)


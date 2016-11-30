CC = g++
CXXFLAGS = -Wall

objects = main.o selectionsort.o printarray.o
targets = selectionsort

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

main.o : printarray.h selectionsort.h
printarray.o : printarray.h
selectionsort.o : selectionsort.h

.PHONY : clean
clean:
	rm $(targets) $(objects)


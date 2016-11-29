CC = g++
CXXFLAGS = -Wall

objects = main.o linearfind.o printarray.o
targets = linearfind

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

mai.o : linearfind.h printarray.h
linearfind.o : linearfind.h
printarray.o : printarray.h

.PHONY : clean
clean:
	rm $(targets) $(objects)

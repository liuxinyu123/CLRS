CC = g++
CXXFLAGS = -Wall

target = maxsubsquence
objects = main.o maxsubsquence.o printarray.o

$(target) : $(objects)
	$(CC) -o $(target) $(objects)

main.o : maxsubsquence.h printarray.h

maxsubsquence.o : maxsubsquence.h

printarray.o : printarray.h

.PHONY : clean

clean:
	rm $(target) $(objects)

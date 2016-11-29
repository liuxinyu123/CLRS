CC = g++
CXXFALGS = -Wall

objects = main.o printarray.o binadd.o
targets = binadd

$(targets) : $(objects)
	$(CC) -o $(targets) $(objects)

main.o : printarray.h binadd.h
printarray.o : printarray.h
binadd.o : binadd.h

.PHONY : clean
clean:
	rm $(targets) $(objects)

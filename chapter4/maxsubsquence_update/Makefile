cc = g++ 
CXXFLAGS = -Wall
CXXFLAGS += -std=gnu++11

target = main
objects = main.o maxsubsquence.o

$(target) : $(objects)
	$(cc) $(CXXFLAGS) -o $(target) $(objects)

main.o : maxsubsquence.h

maxsubsquence.o : maxsubsquence.h

.PHONY : clean

clean :
	rm $(target) $(objects)


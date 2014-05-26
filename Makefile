LIBS	     = -lrt

CXX = gcc

all: test

clean: 
	rm -rf ./*o
	rm -rf test

test: 
	$(CXX) -o test ./test.c $(LIBS)
	./test
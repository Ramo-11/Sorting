main: main.o Sort.o
	g++ -g main.o Sort.o -o main

main.o: main.cpp 
	g++ -g -c main.cpp

Sort.o: Sort.h Sort.cpp	
	g++ -g -c Sort.cpp

run:
	./main

clean:
	rm *.o
	rm main
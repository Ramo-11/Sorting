main: main.o
	g++ -g main.o -o main

main.o: main.cpp 
	g++ -g -c main.cpp

run:
	./main

clean:
	rm *.o
	rm main
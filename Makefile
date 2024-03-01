
output: main.o boardGenerator.o
	g++ main.o boardGenerator.o -o output

main.o: main.cpp
	g++ -c main.cpp

boardGenerator.o: boardGenerator.cpp
	g++ -c boardGenerator.cpp

clean:
	rm *.o output
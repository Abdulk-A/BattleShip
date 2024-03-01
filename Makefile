
output: CompileFiles/main.o CompileFiles/boardGenerator.o
	g++ CompileFiles/main.o CompileFiles/boardGenerator.o -o output

CompileFiles/main.o: main.cpp
	g++ -c main.cpp -o CompileFiles/main.o

CompileFiles/boardGenerator.o: Generators/boardGenerator.cpp
	g++ -c Generators/boardGenerator.cpp -o CompileFiles/boardGenerator.o

clean:
	rm -f CompileFiles/*.o output

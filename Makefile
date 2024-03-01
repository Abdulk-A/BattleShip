
CXXFLAGS = -std=c++11

output: CompileFiles/main.o CompileFiles/boardGenerator.o
	g++ $(CXXFLAGS) CompileFiles/main.o CompileFiles/boardGenerator.o -o output

CompileFiles/main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp -o CompileFiles/main.o

CompileFiles/boardGenerator.o: Generators/boardGenerator.cpp
	g++ $(CXXFLAGS) -c Generators/boardGenerator.cpp -o CompileFiles/boardGenerator.o

clean:
	rm -f CompileFiles/*.o output

all: main

main: main.cpp de_alg.o obs.o
	g++ -o main main.cpp de_alg.o obs.o -std=c++11 -Wall

de_alg.o: de_alg.cpp de_alg.hpp
	g++ -c de_alg.cpp -std=c++11 -Wall

obs.o: obs.cpp obs.hpp
	g++ -c obs.cpp -std=c++11 -Wall

clean:
	mv main working_file/

cleaner:
	mv *~ working_file/
	mv *.o working_file/

cleanest: clean cleaner
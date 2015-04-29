all: main

main: main.cpp de_alg.o obs.o
	g++ -o main main.cpp de_alg.o obs.o -std=c++11 -Wall

test_stud: obs.o
	g++ -o test_stud test_stud.cpp obs.o -std=c++11 -Wall

test_de: obs.o de_alg.o
	g++ -o test_de test_de.cpp obs.o de_alg.o -std=c++11 -Wall

de_alg.o: de_alg.cpp de_alg.hpp
	g++ -c de_alg.cpp -std=c++11 -Wall

obs.o: obs.cpp obs.hpp
	g++ -c obs.cpp -std=c++11 -Wall

clean:
	rm main

cleaner:
	rm *~ 
	rm *.o

cleanest: clean cleaner

clean_test: 
	rm test_stud
	rm test_de
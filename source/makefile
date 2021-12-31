cc = g++
CXXFLAGS = $(cc) -std=c++11 -g

all: similarity_finder.out

similarity_finder.out: main.o process_functions.o doc_functions.o
	$(CXXFLAGS) main.cpp process_functions.cpp doc_functions.cpp

main.o: main.cpp class_process.hpp
	$(CXXFLAGS) -c main.cpp -o main.o

process_functions.o: process_functions.cpp class_process.hpp
	$(CXXFLAGS) -c process_functions.cpp -o process_functions.o

doc_functions.o: doc_functions.cpp class_doc.hpp
	$(CXXFLAGS) -c doc_functions.cpp -o doc_functions.o

clean:
	rm -r *.o

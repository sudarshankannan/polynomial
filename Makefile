#Makefile for PA 1

CXX=g++
CXXFLAGS = -Wall -g
#.PHONY: long //this is a list of phony targets - tells compiler not to look for
         #    //a file named long

main: main.o linkedList.o polyLL.o
	${CXX} ${CXXFLAGS} -o main main.o linkedList.o polyLL.o

main.o: main.cpp  linkedList.cpp polyLL.cpp
	${CXX} -c main.cpp linkedList.cpp polyLL.cpp
linkedList.o: linkedList.cpp
	${CXX} -c linkedList.cpp
polyLL.o: polyLL.cpp
	${CXX} -c polyLL.cpp

clean:
	rm -f *.o *~  main
long:
	ls -l; ls -l | awk 'if(system(find -maxdepth 0 -fname main) != main){system(g++ -o main linkedList.cpp polyLL.cpp)}'



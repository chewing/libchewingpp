OBJS=Chewing.o

all: Chewing test.txt
	./Chewing < test.txt

clean:
	rm -f Chewing Chewing.o testchewing.o *.bb *.bbg *.da *.gcov *.out

Chewing: Chewing.o testchewing.o
	g++ -fprofile-arcs -ftest-coverage -pg -lchewing -L/usr/local/lib -o $@ Chewing.o testchewing.o

Chewing.o: ../src/Chewing.cpp ../src/Chewingpp.h
	g++ -fprofile-arcs -ftest-coverage -pg -I/usr/local/include -I../src -c -o $@ ../src/Chewing.cpp

%.o: %.cpp
	g++ -fprofile-arcs -ftest-coverage -pg -I../src -c $<

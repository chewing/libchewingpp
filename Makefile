
all: framework

framework:
	make -C src/ all

test:
	make -C test/ all

clean:
	make -C src/ clean
	make -C test/ clean

%.o: %.cpp
	g++ -c $<


OBJS=Chewing.o

all: framework

objs: $(OBJS)

install: 
	cp -r ChewingPP.framework /Library/Frameworks

framework: $(OBJS) Chewingpp.h
	mkdir -p ChewingPP.framework/Headers/
	cp Chewingpp.h ChewingPP.framework/Headers/
	g++ -g -Wall -L/usr/local/lib -lchewing -dynamiclib -o ChewingPP.framework/ChewingPP Chewing.o

clean:
	rm -f *~ Chewing $(OBJS) $(GOAL)
	rm -rf ChewingPP.framework/

%.o: %.cpp
	g++ -g -Wall -c -I/usr/local/include  $<

OBJS=Chewing.o

all: framework

objs: $(OBJS)

install: 
	cp -r ChewingPP.framework /Library/Frameworks

framework: $(OBJS) Chewingpp.h
	mkdir -p ChewingPP.framework/Headers/
	cp Chewingpp.h ChewingPP.framework/Headers/
	g++ -lchewing -dynamiclib -o ChewingPP.framework/ChewingPP Chewing.o

clean:
	rm -f *~ Chewing $(OBJS) $(GOAL)
	rm -rf ChewingPP.framework/

%.o: %.cpp
	g++ -c $<


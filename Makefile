all:bin/main
bin/main: obj/main.o 
	g++ obj/main.o -Wall -Werror -o bin/main
obj/main.o:src/geomviz/main.cpp
	g++ -c src/geomviz/main.cpp -Wall -Werror -o obj/main.o -I libgeomviz
run:
	./bin/main
clean:
	find . -name "*.o" -exec {} \;
	find . -name "*.o" -exec {} \;
.PHONY: clean


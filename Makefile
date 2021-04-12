all:bin/main
bin/main: obj/main.o 
	g++ obj/main.o -Wall -Werror -o bin/main
obj/main.o:src/geomviz/main.cpp
	g++ -c src/geomviz/main.cpp -include src/libgeomviz/ParseString.h -Wall -Werror -o obj/main.o -I libgeomviz
run:
	./bin/main
clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "main" -exec  rm '{}' \;
.PHONY: clean run all


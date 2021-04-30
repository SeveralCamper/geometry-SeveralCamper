all:bin/main
bin/main: obj/main.o obj/lib/geometrylib.a 
	g++ obj/main.o -Wall -Werror -L. obj/lib/geometrylib.a -o $@
obj/main.o:src/geomviz/main.cpp obj/lib/geometrylib.a
	g++ -c src/geomviz/main.cpp -include src/lib/ParseString.h -I src/lib -Wall -Werror -o obj/main.o

obj/src/CirclePandS.o:src/lib/CirclePandS.cpp
	g++ -c src/lib/CirclePandS.cpp -Wall -Werror -o $@

obj/src/TrianglePandS.o:src/lib/TrianglePandS.cpp
	g++ -c src/lib/TrianglePandS.cpp -Wall -Werror -o $@

obj/src/length.o:src/lib/length.cpp
	g++ -c src/lib/length.cpp -Wall -Werror -o $@	
	
obj/src/ShowCoordinatesCircle.o:src/lib/ShowCoordinatesCircle.cpp
	g++ -c src/lib/ShowCoordinatesCircle.cpp -Wall -Werror -o $@	

obj/src/ShowCoordinatesTriangle.o:src/lib/ShowCoordinatesTriangle.cpp
	g++ -c src/lib/ShowCoordinatesTriangle.cpp -Wall -Werror -o $@

obj/src/Tokenizer.o:src/lib/Tokenizer.h
	g++ -c src/lib/Tokenizer.h -Wall -Werror -o $@
	
obj/lib/geometrylib.a:obj/src/CirclePandS.o obj/src/length.o obj/src/TrianglePandS.o obj/src/ShowCoordinatesCircle.o obj/src/ShowCoordinatesTriangle.o obj/src/Tokenizer.o
	ar rcs $@ $^
	
run:
	./bin/main
clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "main" -exec rm -f '{}' \;
	find ./bin -type f -name "test" -exec rm -f '{}' \;
.PHONY: clean run all


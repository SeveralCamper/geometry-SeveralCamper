all:bin/main
bin/main: obj/main.o obj/lib/geometrylib.a obj/mlib/parsestringlib.a
	g++ obj/main.o -Wall -Werror -L. obj/lib/geometrylib.a -L. obj/mlib/parsestringlib.a -o $@
obj/main.o:src/geomviz/main.cpp obj/lib/geometrylib.a obj/mlib/parsestringlib.a
	g++ -c src/geomviz/main.cpp -include src/mlib/ParseString.h -include src/lib/Tokenizer.h -I src/lib -I src/mlib -Wall -Werror -o obj/main.o

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

obj/src/ToLower.o:src/mlib/ToLower.cpp
	g++ -c src/mlib/ToLower.cpp -Wall -Werror -o $@

obj/src/IsNotChar.o:src/mlib/IsNotChar.cpp
	g++ -c src/mlib/IsNotChar.cpp -Wall -Werror -o $@

obj/src/IsEqualsKeyWord.o:src/mlib/IsEqualsKeyWord.cpp
	g++ -c src/mlib/IsEqualsKeyWord.cpp -Wall -Werror -o $@
	
obj/src/IsDigitalSymbol.o:src/mlib/IsDigitalSymbol.cpp
	g++ -c src/mlib/IsDigitalSymbol.cpp -Wall -Werror -o $@

obj/src/IsWhiteSpace.o:src/mlib/IsWhiteSpace.cpp
	g++ -c src/mlib/IsWhiteSpace.cpp -Wall -Werror -o $@

obj/src/IsOpenParenthesis.o:src/mlib/IsOpenParenthesis.cpp
	g++ -c src/mlib/IsOpenParenthesis.cpp -Wall -Werror -o $@

obj/src/IsCloseParenthesis.o:src/mlib/IsCloseParenthesis.cpp
	g++ -c src/mlib/IsCloseParenthesis.cpp -Wall -Werror -o $@
		
obj/src/IsComma.o:src/mlib/IsComma.cpp
	g++ -c src/mlib/IsComma.cpp -Wall -Werror -o $@

obj/src/FindFirstCharDifferentFrom.o:src/mlib/FindFirstCharDifferentFrom.cpp
	g++ -c src/mlib/FindFirstCharDifferentFrom.cpp -Wall -Werror -o $@

obj/src/Equals.o:src/mlib/Equals.cpp
	g++ -c src/mlib/Equals.cpp -Wall -Werror -o $@

obj/src/SetString.o:src/mlib/SetString.cpp
	g++ -c src/mlib/SetString.cpp -Wall -Werror -o $@
		
obj/src/SubStr.o:src/mlib/SubStr.cpp
	g++ -c src/mlib/SubStr.cpp -Wall -Werror -o $@

obj/src/GetIndex.o:src/mlib/GetIndex.cpp
	g++ -c src/mlib/GetIndex.cpp -Wall -Werror -o $@

obj/src/Lenght.o:src/mlib/Lenght.cpp
	g++ -c src/mlib/Lenght.cpp -Wall -Werror -o $@

obj/src/FindDigital.o:src/mlib/FindDigital.cpp
	g++ -c src/mlib/FindDigital.cpp -Wall -Werror -o $@

obj/src/FindNumber.o:src/mlib/FindNumber.cpp
	g++ -c src/mlib/FindNumber.cpp -Wall -Werror -o $@

obj/src/StrToInt.o:src/mlib/StrToInt.cpp
	g++ -c src/mlib/StrToInt.cpp -Wall -Werror -o $@

obj/lib/geometrylib.a:obj/src/CirclePandS.o obj/src/length.o obj/src/TrianglePandS.o obj/src/ShowCoordinatesCircle.o obj/src/ShowCoordinatesTriangle.o
	ar rcs $@ $^

obj/mlib/parsestringlib.a:obj/src/ToLower.o obj/src/IsNotChar.o obj/src/IsEqualsKeyWord.o obj/src/IsDigitalSymbol.o obj/src/IsWhiteSpace.o obj/src/IsOpenParenthesis.o 
obj/mlib/parsestringlib.a:obj/src/IsCloseParenthesis.o obj/src/IsComma.o obj/src/FindFirstCharDifferentFrom.o obj/src/Equals.o obj/src/SetString.o obj/src/SubStr.o
obj/mlib/parsestringlib.a:obj/src/GetIndex.o obj/src/Lenght.o obj/src/FindDigital.o obj/src/FindNumber.o obj/src/StrToInt.o
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


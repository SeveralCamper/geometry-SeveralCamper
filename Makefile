all:bin/main
bin/main: obj/main.o obj/lib/geometrylib.a obj/lib/parsestringlib.a
	g++ obj/main.o -Wall -Werror -L. obj/lib/geometrylib.a -L. obj/lib/parsestringlib.a -o $@
obj/main.o:src/geomviz/main.cpp obj/lib/geometrylib.a obj/lib/parsestringlib.a
	g++ -c src/geomviz/main.cpp -include src/lib/ParseString.h -include src/lib/Tokenizer.h -I src/lib -Wall -Werror -o obj/main.o

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

obj/src/ToLower.o:src/lib/ToLower.cpp
	g++ -c src/lib/ToLower.cpp -Wall -Werror -o $@

obj/src/IsNotChar.o:src/lib/IsNotChar.cpp
	g++ -c src/lib/IsNotChar.cpp -Wall -Werror -o $@

obj/src/IsEqualsKeyWord.o:src/lib/IsEqualsKeyWord.cpp
	g++ -c src/lib/IsEqualsKeyWord.cpp -Wall -Werror -o $@
	
obj/src/IsDigitalSymbol.o:src/lib/IsDigitalSymbol.cpp
	g++ -c src/lib/IsDigitalSymbol.cpp -Wall -Werror -o $@

obj/src/IsWhiteSpace.o:src/lib/IsWhiteSpace.cpp
	g++ -c src/lib/IsWhiteSpace.cpp -Wall -Werror -o $@

obj/src/IsOpenParenthesis.o:src/lib/IsOpenParenthesis.cpp
	g++ -c src/lib/IsOpenParenthesis.cpp -Wall -Werror -o $@

obj/src/IsCloseParenthesis.o:src/lib/IsCloseParenthesis.cpp
	g++ -c src/lib/IsCloseParenthesis.cpp -Wall -Werror -o $@
		
obj/src/IsComma.o:src/lib/IsComma.cpp
	g++ -c src/lib/IsComma.cpp -Wall -Werror -o $@

obj/src/FindFirstCharDifferentFrom.o:src/lib/FindFirstCharDifferentFrom.cpp
	g++ -c src/lib/FindFirstCharDifferentFrom.cpp -Wall -Werror -o $@

obj/src/Equals.o:src/lib/Equals.cpp
	g++ -c src/lib/Equals.cpp -Wall -Werror -o $@

obj/src/SetString.o:src/lib/SetString.cpp
	g++ -c src/lib/SetString.cpp -Wall -Werror -o $@
		
obj/src/SubStr.o:src/lib/SubStr.cpp
	g++ -c src/lib/SubStr.cpp -Wall -Werror -o $@

obj/src/GetIndex.o:src/lib/GetIndex.cpp
	g++ -c src/lib/GetIndex.cpp -Wall -Werror -o $@

obj/src/Lenght.o:src/lib/Lenght.cpp
	g++ -c src/lib/Lenght.cpp -Wall -Werror -o $@

obj/src/FindDigital.o:src/lib/FindDigital.cpp
	g++ -c src/lib/FindDigital.cpp -Wall -Werror -o $@

obj/src/FindNumber.o:src/lib/FindNumber.cpp
	g++ -c src/lib/FindNumber.cpp -Wall -Werror -o $@

obj/src/StrToInt.o:src/lib/StrToInt.cpp
	g++ -c src/lib/StrToInt.cpp -Wall -Werror -o $@

obj/lib/geometrylib.a:obj/src/CirclePandS.o obj/src/length.o obj/src/TrianglePandS.o obj/src/ShowCoordinatesCircle.o obj/src/ShowCoordinatesTriangle.o
	ar rcs $@ $^

obj/lib/parsestringlib.a:obj/src/ToLower.o obj/src/IsNotChar.o obj/src/IsEqualsKeyWord.o obj/src/IsDigitalSymbol.o obj/src/IsWhiteSpace.o obj/src/IsOpenParenthesis.o 
obj/lib/parsestringlib.a:obj/src/IsCloseParenthesis.o obj/src/IsComma.o obj/src/FindFirstCharDifferentFrom.o obj/src/Equals.o obj/src/SetString.o obj/src/SubStr.o
obj/lib/parsestringlib.a:obj/src/GetIndex.o obj/src/Lenght.o obj/src/FindDigital.o obj/src/FindNumber.o obj/src/StrToInt.o
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


CFLAGS := -Wall -Werror -std=c++17
CPPFLAGS := -MMD 
CXX := g++

TARGET := bin/main

SOURCES := $(wildcard src/geomviz/*.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)
LIBMSOURCES := $(wildcard src/mlib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/geometrylib.a

MLIBOBJ := $(patsubst src/mlib/%.cpp, obj/src/%.o, $(LIBMSOURCES))
MLIB := obj/mlib/parsestringmlib.a 

OBJ := $(patsubst src/geomviz/%.cpp, obj/src/%.o, $(SOURCES))

TEST := $(wildcard test/geometryLibCheck/*.cpp) 
TESTOBJ := $(patsubst test/geometryLibCheck/%.cpp, obj/test/%.o, $(TEST))
TESTTARGET := bin/geometry-test
CTEST := thirdparty/ctest.h

all:$(TARGET)

$(TARGET): $(OBJ) $(LIB) $(MLIB)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) $(MLIB) 

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

$(MLIB): $(MLIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I src/lib -I src/mlib

obj/src/%.o: src/mlib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I src/lib -I src/mlib

obj/src/%.o: src/geomviz/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -I src/lib -I src/mlib
	
test: $(TESTTARGET)
	./$(TESTTARGET)

$(TESTTARGET): $(TESTOBJ) $(CTEST) $(LIB) $(MLIB)
	$(CXX) $(CPPFLAGS) $(CFLAGS)  $(TESTOBJ) -o $@ -L. $(LIB) $(MLIB) -I src/lib -I src/mlib -I thirdparty

obj/test/%.o: test/geometryLibCheck/%.cpp $(CTEST)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c  $< -o $@ -I src/lib -I src/mlib -I thirdparty
		
run: $(TARGET)
	./$(TARGET)
	
clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "main" -exec rm -f '{}' \;
	find ./bin -type f -name "test" -exec rm -f '{}' \;
	find . -name "geometry" -exec rm {} \;
	find . -name "geometry-test" -exec rm {} \;
	
.PHONY: clean test run all


CFLAGS := -Wall -Werror -std=c++17
CPPFLAGS := -MMD 
CXX := g++

TARGET := bin/main

SOURCES := $(wildcard src/*.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)
LIBMSOURCES := $(wildcard src/mlib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/geometrylib.a

MLIBOBJ := $(patsubst src/mlib/%.cpp, obj/src/%.o, $(LIBMSOURCES))
MLIB := obj/mlib/parsestringmlib.a -L. src/mlib/ParseString.h

OBJ := $(patsubst src/geomviz/%.cpp, obj/src/%.o, $(SOURCES))

all:$(TARGET)

$(TARGET): $(OBJ) $(LIB) $(MLIB)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) $(MLIB)

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

$(MLIB): $(MLIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

obj/src/%.o: src/mlib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

obj/src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@  
		
run: $(TARGET)
	./$(TARGET)
	
clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	find ./bin -type f -name "main" -exec rm -f '{}' \;
	find ./bin -type f -name "test" -exec rm -f '{}' \;
	
.PHONY: clean run all


# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

BIN = bin/Game
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj $(BIN)

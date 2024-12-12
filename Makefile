# Configuración de MinGW y SFML
CXX = g++
CXXFLAGS = -std=c++17 -I./include -I"C:/SFML/include" -Wall -g
LDFLAGS = -L"C:/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
OBJ_DIR = bin
INC_DIR = include

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXEC = pong

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(OBJ_DIR)/$(EXEC) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/$(EXEC)

run: $(EXEC)
	./$(OBJ_DIR)/$(EXEC)

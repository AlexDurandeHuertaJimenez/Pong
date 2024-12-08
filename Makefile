CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iinclude  # Agregar la ruta de los encabezados
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/Game.cpp src/Paddle.cpp src/Ball.cpp src/Score.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = bin/Game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
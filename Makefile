CXX			:= g++
CXX_FLAGS	:= -std=c++17 -ggdb

BIN			:= bin
SRC			:= $(wildcard **/*.cpp)
INCLUDE		:= include

LIBRARIES	:= -lpthread -lGLU -lglut -lGLEW -lglfw -lX11 -ldl -lGL 
EXECUTABLE	:= app


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

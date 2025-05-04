# Makefile - Emergency Tycoon (C++ + SFML)

CXX := clang++
CXXFLAGS:= -std+c++17 -Wall -Wextra -Iinclude -I/usr/include/catch2
TARGET := emergency_tycoon

CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude

LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SRC := $(shell find src -name '*.cpp')
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
	rm -f src/**/*.o emergency_tycoon

fclean: clean
	rm -rf build

re: fclean all

.PHONY: all clean fclean re
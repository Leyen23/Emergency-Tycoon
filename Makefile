# Makefile - Emergency Tycoon (C++ + SFML)

# Compilador y flags
CXX        := clang++
CXXFLAGS   := -std=c++17 -Wall -Wextra -Iinclude

# Librerías SFML
SFML_LIBS  := -lsfml-graphics -lsfml-window -lsfml-system

# Directorios
BUILD_DIR  := build
OBJ_DIR    := $(BUILD_DIR)/obj

# Fuentes
CORE_INCLUDE    := $(wildcard include/core/*.hpp)
CORE_SRCS      := $(wildcard src/core/*.cpp)
GAME_INCLUDE     := $(wildcard include/game/*.hpp)
GAME_SRCS      := $(wildcard src/game/*.cpp)
SIM_SRCS       := $(wildcard include/simulation/*.hpp)
SIM_SRCS       := $(wildcard src/simulation/*.cpp)
SRCS           := $(CORE_SRCS) $(GAME_SRCS) $(SIM_SRCS)

# Objetos
OBJS := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Ejecutable principal
TARGET := emergency_tycoon

# Regla por defecto
all: $(TARGET)

# Enlazado
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Compilación de cada fuente
$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para tests (opcional)
.PHONY: test
test:
	@echo "Ejecuta tus tests aquí"

# Limpiar
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

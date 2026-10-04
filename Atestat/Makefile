# Compiler & Flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# SFML Libraries (graphics, window, audio, network, system)
LIBS     := -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

# Target executable name
TARGET   := game

# Source and Object files
SRCS     := main.cpp Car.cpp CustomMenu.cpp Game.cpp Level.cpp MainMenu.cpp ParkedCar.cpp universal.cpp
OBJS     := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run target
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run

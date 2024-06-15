# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinc -I/usr/include/SFML
LDFLAGS = -L/usr/lib
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin

# Source files
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))

# Target executable
TARGET = $(BINDIR)/tic-tac-toe
TEST_TARGET = $(BINDIR)/test

# Default target
all: $(TARGET)

# Create directories if they do not exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Build the target executable
$(TARGET): $(OBJDIR) $(BINDIR) $(OBJFILES) main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(OBJFILES) main.cpp $(LDFLAGS) $(SFMLFLAGS)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Test target
test: $(TEST_TARGET)
	./$(TEST_TARGET)
# Build the test executable
$(TEST_TARGET): $(OBJDIR) $(BINDIR) $(OBJFILES) test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(OBJFILES) test.cpp  $(LDFLAGS) $(SFMLFLAGS) -lgtest -lgtest_main -pthread


# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony targets
.PHONY: all clean test

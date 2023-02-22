# Specify the compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Specify the name of the executable
EXECUTABLE = app

# Specify the source files
SRC = main.cc

# Specify the object files
OBJ = $(SRC:.cc=.o)

# Default target, compile the executable
all: $(EXECUTABLE)

# Link the object files to create the executable
$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each source file into an object file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the object files and executable
clean:
	rm -f $(OBJ) $(EXECUTABLE)


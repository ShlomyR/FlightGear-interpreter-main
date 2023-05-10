# the name of your executable
TARGET = solid_test

# launches your target in terminal
RUN = ./$(TARGET)

# directory for your source files
SRC_DIR = src/sourcefiles

# directory for your heder files
SRC_DIR_COMMAND = src/sourcefiles/Commands

# directory for your source files
SRC_DIR_EXPRESSION = src/sourcefiles/Expressions

# directory for your source files
SRC_DIR_ARITHMETIC = src/sourcefiles/Expressions/ArithmeticExpression

# directory for your heder files
SRC_DIR_PARSER = src/sourcefiles/Parser

# directory for your source files
SRC_DIR_SHUNTING_YARD = src/sourcefiles/ShuntingYard

# directory for your source files
SRC_DIR_TOKEN = src/sourcefiles/Token

# directory for your heder files
HEDER_DIR = src/hederfiles

# directory for your object files
BUILD_DIR = bin

# add more CompilerFLAGS as your project requires
CFLAGS = -std=c++17 -Wall -O2 -Wextra 

# add libraries for your project here
LDFLAGS =

# add library linker commands here (start with -l)
LOADLIBS = -lpthread

# add library search paths here (start with -L)
LDLIBS = 

# add include paths (start with -I)
INC = -I $(HEDER_DIR)

# finds all your objects that corrispond to your .cpp files, system agnostic version
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

OBJECTS += $(patsubst $(SRC_DIR_COMMAND)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR_COMMAND)/*.cpp))

OBJECTS += $(patsubst $(SRC_DIR_EXPRESSION)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR_EXPRESSION)/*.cpp))

OBJECTS += $(patsubst $(SRC_DIR_ARITHMETIC)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR_ARITHMETIC)/*.cpp))

OBJECTS += $(patsubst $(SRC_DIR_PARSER)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR_PARSER)/*.cpp))

OBJECTS += $(patsubst $(SRC_DIR_SHUNTING_YARD)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR_SHUNTING_YARD)/*.cpp))

OBJECTS += $(patsubst $(SRC_DIR_TOKEN)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR_TOKEN)/*.cpp))

OBJECTS += main.cpp

.PHONY: all
# makes build directory, updates your objects, builds your executable
all: 
	mkdir -p $(BUILD_DIR)
	+$(MAKE) $(TARGET)

# updates your objects, builds your executable
$(TARGET): $(OBJECTS) $(HEDER_DIR)/*.hpp
	$(CXX) $(OBJECTS) $(CFLAGS) -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

# builds your objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

$(BUILD_DIR)/%.o: $(SRC_DIR_COMMAND)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

$(BUILD_DIR)/%.o: $(SRC_DIR_EXPRESSION)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

$(BUILD_DIR)/%.o: $(SRC_DIR_ARITHMETIC)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

$(BUILD_DIR)/%.o: $(SRC_DIR_PARSER)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

$(BUILD_DIR)/%.o: $(SRC_DIR_SHUNTING_YARD)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

$(BUILD_DIR)/%.o: $(SRC_DIR_TOKEN)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)


# deletes your built objects and executable
.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR) $(TARGET)

# makes build direcotry, updates your objects, builds your executable, launches your program
.PHONY: run
run: 
	+$(MAKE) all
	$(RUN)

# explains the only three options you should be using (unless you build more of your own)
.PHONY: help
help:
	@echo "make       - builds/updates everything, is ready to run with '$(RUN)' after completion"
	@echo "make clean - removes object file folder and executable"
	@echo "make run   - builds/updates everything, runs immediately"
	@echo "src: " $(OBJECTS)
# the name of your executable
TARGET = FS_interpater

# launches your target in terminal
RUN = ./$(TARGET)

# directory for your source files
SRC_DIR = src/sourcefiles
SRC_DIR_COMMAND = src/sourcefiles/Commands
SRC_DIR_EXPRESSION = src/sourcefiles/Expressions
SRC_DIR_ARITHMETIC = src/sourcefiles/Expressions/ArithmeticExpression
SRC_DIR_PARSER = src/sourcefiles/Parser
SRC_DIR_SHUNTING_YARD = src/sourcefiles/ShuntingYard
SRC_DIR_TOKEN = src/sourcefiles/Token

# directory for your heder files
HEDER_DIR_SRC = src/hederfiles
HEDER_DIR_COMMANDS = src/hederfiles/Commands
HEDER_DIR_EXPRESSIONS = src/hederfiles/Expressions
HEDER_DIR_ARITHMETIC = src/hederfiles/Expressions/ArithmeticExpression
HEDER_DIR_PARSER = src/hederfiles/Parser
HEDER_DIR_SHUNTING_YARD = src/hederfiles/ShuntingYard
HEDER_DIR_INTERFACES = src/hederfiles/Interfaces
HEDER_DIR_TOKENS = src/hederfiles/Token

# directory for your object files
BUILD_DIR_SRC = bin/src
BUILD_DIR_COMMANDS = bin/commands
BUILD_DIR_EXPRESSIONS = bin/expression
BUILD_DIR_ARITHMETIC = bin/arithmetic
BUILD_DIR_PARSER = bin/parser
BUILD_DIR_SHUNTING_YARD = bin/shuntingYard
BUILD_DIR_TOKENS = bin/tokens

# add more CompilerFLAGS as your project requires
CFLAGS = -std=c++17 -Wall -O2 -Wextra 

# add libraries for your project here
LDFLAGS =

# add library linker commands here (start with -l)
LOADLIBS = -lpthread

# add library search paths here (start with -L)
LDLIBS = 

# add include paths (start with -I)
INC = -I $(HEDER_DIR_SRC)
INC += -I $(HEDER_DIR_COMMANDS)
INC += -I $(HEDER_DIR_EXPRESSIONS)
INC += -I $(HEDER_DIR_ARITHMETIC)
INC += -I $(HEDER_DIR_PARSER)
INC += -I $(HEDER_DIR_SHUNTING_YARD)
INC += -I $(HEDER_DIR_INTERFACES)
INC += -I $(HEDER_DIR_TOKENS)

# finds all your objects that corrispond to your .cpp files, system agnostic version
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR_SRC)/%.o, $(wildcard $(SRC_DIR)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_COMMAND)/%.cpp, $(BUILD_DIR_COMMANDS)/%.o, $(wildcard $(SRC_DIR_COMMAND)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_EXPRESSION)/%.cpp, $(BUILD_DIR_EXPRESSIONS)/%.o, $(wildcard $(SRC_DIR_EXPRESSION)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_ARITHMETIC)/%.cpp, $(BUILD_DIR_ARITHMETIC)/%.o, $(wildcard $(SRC_DIR_ARITHMETIC)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_PARSER)/%.cpp, $(BUILD_DIR_PARSER)/%.o, $(wildcard $(SRC_DIR_PARSER)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_SHUNTING_YARD)/%.cpp, $(BUILD_DIR_SHUNTING_YARD)/%.o, $(wildcard $(SRC_DIR_SHUNTING_YARD)/*.cpp))
OBJECTS += $(patsubst $(SRC_DIR_TOKEN)/%.cpp, $(BUILD_DIR_TOKENS)/%.o, $(wildcard $(SRC_DIR_TOKEN)/*.cpp))
OBJECTS += main.cpp

.PHONY: all
# makes build directory, updates your objects, builds your executable
all: 
	mkdir -p $(BUILD_DIR_SRC)
	mkdir -p $(BUILD_DIR_COMMANDS)
	mkdir -p $(BUILD_DIR_EXPRESSIONS)
	mkdir -p $(BUILD_DIR_ARITHMETIC)
	mkdir -p $(BUILD_DIR_PARSER)
	mkdir -p $(BUILD_DIR_SHUNTING_YARD)
	mkdir -p $(BUILD_DIR_TOKENS)
	+$(MAKE) $(TARGET)

# updates your objects, builds your executable
$(TARGET): $(OBJECTS) $(HEDER_DIR_SRC)/*.hpp $(HEDER_DIR_COMMANDS)/*.hpp $(HEDER_DIR_EXPRESSIONS)/*.hpp $(HEDER_DIR_ARITHMETIC)/*.hpp $(HEDER_DIR_PARSER)/*.hpp $(HEDER_DIR_SHUNTING_YARD)/*.hpp $(HEDER_DIR_INTERFACES)/*.hxx $(HEDER_DIR_TOKENS)/*.hpp
	$(CXX) $(OBJECTS) $(CFLAGS) -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)

# builds your objects
$(BUILD_DIR_SRC)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_COMMANDS)/%.o: $(SRC_DIR_COMMAND)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_EXPRESSIONS)/%.o: $(SRC_DIR_EXPRESSION)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_ARITHMETIC)/%.o: $(SRC_DIR_ARITHMETIC)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_PARSER)/%.o: $(SRC_DIR_PARSER)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_SHUNTING_YARD)/%.o: $(SRC_DIR_SHUNTING_YARD)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)
$(BUILD_DIR_TOKENS)/%.o: $(SRC_DIR_TOKEN)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(LOADLIBS) $(LDFLAGS) $(LDLIBS) $(INC)


# deletes your built objects and executable
.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR_SRC) $(BUILD_DIR_COMMANDS) $(BUILD_DIR_EXPRESSIONS) $(BUILD_DIR_ARITHMETIC) $(BUILD_DIR_PARSER) $(BUILD_DIR_SHUNTING_YARD) $(BUILD_DIR_TOKENS) $(TARGET)

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
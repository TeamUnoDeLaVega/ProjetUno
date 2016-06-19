PACKAGES = zlib
CXXFLAGS = -std=c++14 -Wall -Wextra -g 
LDFLAGS = 
LIBS = 
MAINSRC = ./src/MainProg.cpp ./src/MainTest.cpp

CXXFLAGS += `pkg-config --cflags $(PACKAGES)`
LDFLAGS +=`pkg-config --libs-only-L --libs-only-other $(PACKAGES)`
LIBS +=`pkg-config --libs-only-l $(PACKAGES)`
BINDIR = ./bin
OBJDIR = ./obj
SRCDIR = ./src
SRC = $(filter-out $(MAINSRC), $(shell find $(SRCDIR) -name *.cpp))
TEST = $(shell find $(SRCDIR) -name "*_test.hpp")
OBJ = $(subst $(SRCDIR)/, $(OBJDIR)/, $(SRC:.cpp=.o))
BIN = $(subst $(SRCDIR)/, $(BINDIR)/, $(MAINSRC:.cpp=.out))
.PHONY : all clean
.SECONDARY:
all: $(BIN)
$(BINDIR)/%.out: $(OBJDIR)/%.o $(OBJ) $(TEST)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $< $(OBJ) $(LIBS)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(SRCDIR)/%.hpp)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:
	find $(OBJDIR) -name "*.o" | xargs rm $(BIN) 

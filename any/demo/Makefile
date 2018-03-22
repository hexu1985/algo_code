
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -I../include #-std=c++17 -I../include_std 
INCLUDES = 
LDFLAGS =
LDPATH =

SOURCES = $(shell ls *.cpp)
PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)

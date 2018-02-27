
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++98
INCLUDES = -I../lib 
LDFLAGS = -lrc_object
LDPATH = -L../lib 

SOURCES = $(shell ls *.cpp)
PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS) *.o

%.o:%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDES)

$(PROGS): %: %.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

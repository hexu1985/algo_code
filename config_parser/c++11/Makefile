# Makefile

RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
INCLUDE = 
LDFLAGS = -lboost_program_options 
LDPATH =
VPATH = 

COM_OBJS = config_parser.lambda.o 

PROGS =	parse_command_line parse_environment parse_config_file parse_all

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

%.o:%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

parse_command_line: ../parse_command_line.o ../config_parser_util.o $(COM_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

parse_environment: ../parse_environment.o ../config_parser_util.o $(COM_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

parse_config_file: ../parse_config_file.o ../config_parser_util.o $(COM_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

parse_all: ../parse_all.o ../config_parser_util.o $(COM_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)


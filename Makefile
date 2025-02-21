CXX=g++
CXXFLAGS= -Wall -std=c++11

SRCS=$(wildcard *.cpp)

OBJS=$(SRCS:.cpp=.o)

all: amazon
	@echo "Cleaning up temporary files..."
	rm -f $(OBJS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c $<

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

clean:
	rm -f *.o amazon
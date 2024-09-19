CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
SRCS := main.cpp algorithm.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := main

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $

TARGET=target
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
CXXFLAGS=-std=c++11
LIBS=-pthread

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

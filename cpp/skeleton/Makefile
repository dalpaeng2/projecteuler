TARGET=target
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
LIBS=

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

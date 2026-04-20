CXX = ccache g++
CXXFLAGS = -std=c++17 -O2 -I./external_deps/notcurses/include \
           -I./external_deps/matplot/source \
           -I./external_deps/matplot/build/source/matplot

LDFLAGS = -L./external_deps/notcurses/build \
          -L./external_deps/matplot/build/source/matplot \
          -L./external_deps/matplot/build/source/3rd_party

# Added -ljpeg at the end
LIBS = -lnotcurses++ -lnotcurses -lnotcurses-core -lmatplot -lnodesoup -lz -lpng -ljpeg -ltiff

TARGET = my_app
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(LIBS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

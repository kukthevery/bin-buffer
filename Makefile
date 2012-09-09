CXXFLAGS = -Wall

target := cbuffer

objs := Cbuffer.o main.o

$(target): $(objs)
	$(CXX) $^ -o $@

all: $(target)
    
clean:
	rm -f $(target) $(objs)
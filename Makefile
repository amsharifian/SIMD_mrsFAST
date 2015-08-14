
CXXFLAGS = -Wall -g -c

test: main.o bitConvert.o sequence.o simdCompare.o
	$(CXX) -o test main.o bitConvert.o sequence.o simdCompare.o

main.o: main.cpp bitConvert.hpp sequence.hpp simdCompare.hpp
	$(CXX) $(CXXFLAGS) main.cpp

bitConvert.o: bitConvert.cpp bitConvert.hpp
	$(CXX) $(CXXFLAGS) bitConvert.cpp
sequence.o: sequence.cpp sequence.hpp
	$(CXX) $(CXXFLAGS) sequence.cpp
simdCompare.o: simdCompare.cpp simdCompare.hpp
	$(CXX) $(CXXFLAGS) simdCompare.cpp 

run:
	./test
clean:
	$(RM) test *.o

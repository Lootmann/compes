CXX      = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic-errors -Wshadow \
		   -fsanitize=undefined -fsanitize=address -DDEBUG_
TARGET   = a.out
SRC      = solve.cc

run:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: out
out:
	./$(TARGET)

.PHONY: in
in:
	./$(TARGET) < ./in0 > got0

.PHONY: test
test:
	./$(TARGET) < ./in0 > got0
	./$(TARGET) < ./in1 > got1
	./$(TARGET) < ./in2 > got2

.PHONY: submit
submit:
	oj s solve.cc

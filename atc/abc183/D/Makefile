CXX      = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic-errors -Wshadow \
		   -fsanitize=undefined -fsanitize=address -DDEBUG_
TARGET   = a.out
SRC      = solve.cc

run:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: debug
debug:
	$(CXX) $(CXXFLAGS) -g -O0 $(SRC) -o $(TARGET)

.PHONY: out
out:
	./$(TARGET)

.PHONY: in
in:
	./$(TARGET) < in

.PHONY: submit
submit:
	oj s solve.cc

.PHONY: watch
watch:
	find $(SRC) | entr -sc "make run && oj t"

.PHONY: clean
clean:
	rm a.out solve.cc ./test -r

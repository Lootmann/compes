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
	./$(TARGET) < in

.PHONY: submit
submit:
	oj s solve.cc

.PHONY: watch
watch:
	find ./solve.cc | entr -sc "make && oj t"

.PHONY: clean
clean:
	rm a.out solve.cc ./test -r

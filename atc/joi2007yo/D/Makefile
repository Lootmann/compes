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
	./$(TARGET) < in1
	./$(TARGET) < in2

# -g3: debug level 3
# -O0: Optimize level 0 <=> no optimizations
.PHONY: debug
debug:
	$(CXX) $(CXXFLAGS) -g3 -O0 $(SRC) -o $(TARGET)

.PHONY: watch
watch:
	find $(SRC) | entr -sc "make run && oj t"

.PHONY: clean
clean:
	rm a.out solve.cc ./test in out -r

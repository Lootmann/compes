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
	./$(TARGET) < in1 > out1
	./$(TARGET) < in2 > out2
	./$(TARGET) < in3 > out3

.PHONY: test
test:
	./output_checker.out ./in1 ./out1 ./out1
	./output_checker.out ./in2 ./out2 ./out2
	./output_checker.out ./in3 ./out3 ./out3

.PHONY: submit
submit:
	oj s solve.cc

.PHONY: watch
watch:
	find $(SRC) | entr -sc "make run && oj t"

.PHONY: clean
clean:
	rm a.out solve.cc ./test -r

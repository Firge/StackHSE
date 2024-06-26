build_googletest: googletest
	mkdir $@
	cd $@ && cmake ../$< && make && make install

clean_googletest: build_googletest
	rm -rd $<

CC = g++

CFLAGS = -std=c++14 -Wall -Wextra -lgtest -lgtest_main -pthread

# running tests
build_test_example: tests/tests.cpp
	${CC} $< ${CFLAGS} -o test/tests

run_test_example:
	./tests/tests

clean_test_example:
	rm -f ./tests/tests

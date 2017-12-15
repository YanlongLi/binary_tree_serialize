
GTEST_DIR=/usr/src/gtest

run: test
	@./test

test: unitest.cpp tree_serialize.o utils.o libgtest.a
	g++ -std=c++14 -isystem ${GETST_DIR}/include -pthread unitest.cpp \
		tree_serialize.o utils.o libgtest.a \
		-o test

tree_serialize.o: tree_serialize.cpp
	g++ -std=c++14 -c tree_serialize.cpp \
		-o tree_serialize.o

utils.o: utils.cpp
	g++ -std=c++14 -c utils.cpp -o utils.o

libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o

gtest-all.o:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
		-pthread -c ${GTEST_DIR}/src/gtest-all.cc

clean:
	@rm *.o *.a test

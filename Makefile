CXX=g++ -g3 -O0

compile_test:
	$(CXX) test.cpp -o test

test: compile_test
	./test

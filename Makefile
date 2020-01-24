CXX=g++ -g3 -O0

compile_test:
	$(CXX) test.cpp -o test.out

test: compile_test
	./test.out

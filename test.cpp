#include<iostream>

#include"main.cpp"

#define ASSERT_TRUE(expression) assertTrue(expression, __LINE__)

void assertTrue(bool expression, int lineNum) {
  if (!expression) {
    std::cerr << "Failed at " << lineNum << std::endl;
  }
}

int main() {
  matrix<int> empty(0, 0);
  ASSERT_TRUE(empty.m == 0);
  ASSERT_TRUE(empty.n == 0);
}

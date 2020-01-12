#include<iostream>
#include<vector>

#include"main.cpp"

#define ASSERT_TRUE(expression) assertTrue(expression, __LINE__)

void assertTrue(bool expression, int lineNum) {
  if (!expression) {
    std::cerr << "Failed at " << lineNum << std::endl;
  }
}

int main() {

  std::vector<int> v (0);
  std::cout << v[10];

  matrix<int> empty(0, 0);
  ASSERT_TRUE(empty.m == 0);
  ASSERT_TRUE(empty.n == 0);

  matrix<int> zero(3, 5);
  ASSERT_TRUE(zero[0][0] == 0);
  ASSERT_TRUE(zero[2][4] == 0);
}

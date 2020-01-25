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
  matrix<int> empty(0, 0);
  ASSERT_TRUE(empty.m == 0);
  ASSERT_TRUE(empty.n == 0);

  matrix<int> zero(3, 5);
  ASSERT_TRUE(*zero[1][1] == 0);
  for (auto i = zero.begin(); i != zero.end(); ++i) {
      ASSERT_TRUE(*i == 0);
  }

  matrix<int> random(4, 6);
  random.random(1, 5);
  for (auto i = random.begin(); i != random.end(); ++i) {
    ASSERT_TRUE(*i >= 1);
    ASSERT_TRUE(*i <= 5);
  }

  // matrix<int> a(2, 3);
  // matrix<int> b(2, 3);
  // a[0][0] = 5; a[1][1] = 3;
  // b[0][0] = 3;
  // matrix<int> c = a + b;
  // c.print();
}

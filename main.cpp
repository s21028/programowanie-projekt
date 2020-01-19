#include<cstdlib>
#include<iostream>
#include<random>

using std::size_t;

template<typename T>
struct matrix {
  size_t m, n;
  T** values;

  matrix(int, int);
  ~matrix();

  matrix<T>& operator=(const T);
  T* operator[](size_t);

  void random(T min, T max);
  void print();
};

template<typename T>
matrix<T>::matrix(int _m, int _n) {
  m = _m;
  n = _n;

  values = (T**) malloc(sizeof(T) * m);
  for (int i = 0; i < m; i++) {
    values[i] = (T*) malloc(sizeof(T) * n);
  }
}

template<typename T>
T* matrix<T>::operator[](size_t m) {
  return values[m];
}

template<typename T>
matrix<T>::~matrix() {
#ifdef DEBUG
  for (int i = 0; i < m; i++) {
    free(values[i]);
  }

  free(values);
#endif
}

template<typename T>
void matrix<T>::random(T min, T max) {
  std::default_random_engine generator;
  std::uniform_int_distribution<T> distribution(min, max);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      values[i][j] = distribution(generator);
    }
  }
}

template<typename T>
void matrix<T>::print() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << values[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

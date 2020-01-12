#include<cstdlib>

using std::size_t;

template<typename T>
struct matrix {
  size_t m, n;
  T** values;

  matrix(int, int);
  ~matrix();

  matrix<T>& operator=(const T);
  T* operator[](size_t);
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
  for (int i = 0; i < m; i++) {
    free(values[i]);
  }

  free(values);
}

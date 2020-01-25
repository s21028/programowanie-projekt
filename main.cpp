#include<cstdlib>
#include<iostream>
#include<random>

using std::size_t;

template<typename T>
struct row {
  size_t n;

  T* values;

  row(T* _values, size_t _n) : values(_values), n(_n) {}

  T* operator[](size_t);
};

template<typename T>
struct matrix {
  size_t m, n;
  T** values;

  matrix(int, int);
  ~matrix();

  matrix<T>& operator=(const T);
  row<T> operator[](size_t);
  const T* get_const(size_t);
  matrix<T> operator+(const matrix<T>& other);

  void random(T min, T max);
  void print();

  class iterator
  {
  public:
    iterator(matrix<T>& _m, int _i, int _j) : m(_m), cur_m(_i), cur_n(_j) {}
    iterator operator++() {
      cur_n++;
      if (cur_n == m.n) {
        cur_n = 0;
        cur_m++;
      }

      return *this;
    }
    T& operator*() { return m.values[cur_m][cur_n]; }
    T* operator->() { return m.values[cur_m][cur_n]; }
    bool operator==(const iterator& o) { return cur_m == o.cur_m && cur_n == o.cur_n; }
    bool operator!=(const iterator& o) { return cur_m != o.cur_m || cur_n != o.cur_n; }
  private:
    matrix<T>& m;
    int cur_m, cur_n;
  };

  iterator begin() {
    return iterator(*this, 0, 0);
  }
  
  iterator end() {
    return iterator(*this, m, 0);
  }
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
row<T> matrix<T>::operator[](size_t m) {
  row<T> r(values[m], this->n);
  return r;
}

template<typename T>
const T* matrix<T>::get_const(size_t m) {
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

template<typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& other) {
  matrix<T> result(m, n);
  return result;
}

template<typename T>
T* row<T>::operator[](size_t i) {
  return &values[i];
}

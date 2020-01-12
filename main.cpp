template<typename T>
struct matrix {
  int m, n;
  matrix(int, int);
};

template<typename T>
matrix<T>::matrix(int _m, int _n) {
  m = _m;
  n = _n;
}

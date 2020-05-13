/* <sort_indexes> */

template <typename T>
std::vector<int> sort_indexes(const std::vector<T> &v) {
  std::vector<int> idx(v.size());
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&v](int i1, int i2) {return v[i1] < v[i2];});
  return idx;
}

/* <sort_indexes> */
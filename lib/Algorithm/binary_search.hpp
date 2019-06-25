// サーチ条件
template <typename T = int>
bool isOK(T element, T key) {
    if (element >= key) return true;
    else return false;
}

// isOKを満たす最小のキーを求める
template <typename T = int>
int binary_search(vector<T> v, T key) {
  int left = -1;
  int right = (int)v.size();

  while (right - left > 1) {
      int mid = left + (right - left) / 2;

      if (isOK(v[mid], key)) right = mid;
      else left = mid;
  }

  // left  -> isOKを満たさない最大値
  // right -> isOKを満たす最小値
  return right;
}

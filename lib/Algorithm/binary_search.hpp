/**
  二分探索

  引数:
    - T key: 基準になる値

  返り値:
    - isOKを満たす最小のインデックス

  依存ライブラリ:
    - なし
*/
template <typename T = int>
int binary_search(vector<T> v, T key) {
  int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
  int right = (int)v.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は v.size()

  while (right - left > 1) {
      int mid = left + (right - left) / 2;

      if (isOK(v[mid], key)) right = mid;
      else left = mid;
  }

  /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
  return right;
}

// 条件を満たすかどうか
template <typename T = int>
bool isOK(T element, T key) {
    if (element >= key) return true;
    else return false;
}
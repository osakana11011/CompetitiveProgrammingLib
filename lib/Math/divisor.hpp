/**
  約数を列挙する

  引数:
    - int n: nの約数を列挙する
  返り値:
    - nの約数列
  依存ライブラリ:
    - なし
*/
vector<int> divisor(int n) {
  vector<int> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
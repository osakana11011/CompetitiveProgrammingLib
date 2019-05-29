/**
  進数変換

  引数:
    - int x: 変換前の数(10進数)
    - int b: b進数に変換する
  返り値:
    - 変換後の数字列
*/
vector<int> convert_base(int x, int b) {
  vector<int> ret;
  int t = 1, k = abs(b);
  while(x) {
    ret.emplace_back((x * t) % k);
    if(ret.back() < 0) ret.back() += k;
    x -= ret.back() * t;
    x /= k;
    t *= b / k;
  }
  if(ret.empty()) ret.emplace_back(0);
  reverse(begin(ret), end(ret));
  return ret;
}
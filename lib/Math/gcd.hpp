/**
  ユークリッド互除法
  WARNING: a!=0 かつ b!=0 が条件

  引数:
    - int a
    - int b
  返り値:
    - aとbの最大公約数
  依存ライブラリ:
    - なし
  */
int gcd(int a, int b) {
  int greater = max(a, b), less = min(a, b);
  int remainder = greater % less;

  if(remainder == 0) {
    return less;
  } else {
    return gcd(less, remainder);
  }
}
/**
  ユークリッド互除法
  a と b の最小公約数を返す
  a!=0 かつ b!=0 が条件
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
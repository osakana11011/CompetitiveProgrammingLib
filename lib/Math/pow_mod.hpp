/**
  「{base}^{exponent}%mod」 を計算する
 */
ll powMod(ll base, ll exponent, ll mod) {
  assert(exponent >= 0);

  // 指数が0の時、答えばbaseの値に関わらず1になる
  if(exponent == 0) return 1;

  ll res = base, side = 1;
  while(exponent != 1) {
    if(exponent % 2 == 0) {
      // 指数が偶数の時
      // ex) 9^10 => 81^5
      res = (res * res) % mod;
      exponent /= 2;
    } else {
      // 指数が奇数の時
      // ex) 9^9 => 9・9^8
      side = (side * res) % mod;
      exponent--;
    }
  }
  res = (res * side) % mod;
  return res;
}
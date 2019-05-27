/**
  素数判定

  引数:
    - int x: 素数かどうか判定したい数
  返り値:
    - 素数ならtrue, そうでないならfalse
  計算量:
    - O(sqrt(x))
  依存ライブラリ:
    - なし
*/
bool isPrime(int x) {
  for(int i = 2; i * i<= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}
/**
  素数テーブルを取得する (エラストテレスの篩)

  引数:
    - int n: nまでの素数テーブルを求める
  返り値:
    - bool配列の素数テーブル
  計算量:
    - O(N loglogN)
  依存ライブラリ:
    - なし
*/
vector<bool> getPrimeTable(int n) {
  vector<bool> prime(n+1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = 2 * i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
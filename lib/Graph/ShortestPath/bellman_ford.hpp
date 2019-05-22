/**
  ベルマンフォード法
  計算量: O(|V|・|E|)
  */
template <typename T = int>
vector<T> bellmanFord(Graph<T> g, int s) {
  // NOTE: INF同士を足したとしてもオーバーフロー起こさないように2で割っている
  T INF = numeric_limits<T>::max() / 2;

  // 距離情報初期化
  vector<T> d(g.n, INF);
  d[s] = 0;

  // 全ての辺に対して、頂点の数分の更新をかける
  int n = g.n;
  for(int _ = 0; _ < n; _++) {
    for(int from = 0; from < n; from++) {
      for(Edge<T> edge : g.graph[from]) {
        if(d[from] + edge.cost < d[edge.to]) {
          d[edge.to] = d[from] + edge.cost;

          // 負閉路検出
          // WARNING: 不平路を検出した時、d[n-1]にINFを埋め込んで返しているので、返した後の判定注意
          if(from == n-1 && edge.to == n-1) {
            d[n-1] = INF;
            return d;
          }
        }
      }
    }
  }
  return d;
}
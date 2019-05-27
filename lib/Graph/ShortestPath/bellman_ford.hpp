/**
  ベルマンフォード法 (単一始点最短経路問題 / 辺の重みが負数でもOK)
  NOTE: 辺の重みが負数でもOK
  WARNING: 重みが全て正数ならdijkstra法の方が速い

  引数:
    - Graph<T> g: グラフ
    - int s: 出発地点のノード番号
  返り値:
    - 出発地点sからのそれぞれのノードへの距離
  計算量:
    - O(|V|・|E|)
  依存ライブラリ:
    - template.hpp
    - Graph/ShortestPath/common.hpp
*/
template <typename T = int>
vector<T> bellmanFord(Graph<T> g, int s) {
  // 距離情報初期化
  vector<T> d(g.n, INF<T>);
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
            d[n-1] = INF<T>;
            return d;
          }
        }
      }
    }
  }
  return d;
}
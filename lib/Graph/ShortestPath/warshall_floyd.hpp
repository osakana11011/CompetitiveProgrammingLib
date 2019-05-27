/**
  ワーシャルフロイド法 (全点対最短経路問題)

  引数:
    - Graph<T> g: グラフ
  返り値:
    - 全ての対に関する最短経路リスト
      ex) d[from][to]: fromからtoへの最短経路
  計算量:
    - O(V^3)
  依存ライブラリ:
    - template.hpp
    - Graph/ShortestPath/common.hpp
*/
template <typename T = int>
vector<vector<T>> warshallFloyd(Graph<T> g) {
  // 距離情報初期化
  int n = graph.getNodeN();
  vector<vector<T>> d(n, vector<T>(n, INF<T>));
  for(int i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for(int from = 0; from < g.n; from++) {
    for(Edge edge : g.graph[from]) {
      d[from][edge.to] = edge.cost;
    }
  }

  // i → k → jと進むルートについて全探索
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}
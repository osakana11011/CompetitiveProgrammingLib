/**
  ベルマンフォード法
  計算量: O(|V|・|E|)
  */
vector<ll> bellmanFord(Graph g, int s) {
  int n = g.getNodeN();
  vector<Node> graph = g.getGraph();

  // 距離情報初期化
  vector<ll> d(n, INF);
  d[s] = 0;

  // 全ての辺に対して、nodeN回更新を掛ける
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(Edge edge : graph[j].edges) {
        if(d[edge.to] > d[j] + edge.cost) {
          d[edge.to] = d[j] + edge.cost;
          // 負閉路検出
          // nodeN回目のループで、目的地Nへのルートが更新されるなら負閉路
          if(i == n-1 && edge.to == n-1) {
            d[n-1] = INF;
            return d;
          }
        }
      }
    }
  }
  return d;
}
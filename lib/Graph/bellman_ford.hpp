/**
  ベルマンフォード法
  計算量: O(|V|・|E|)
  */
vector<ll> bellmanFord(Graph graph, int s) {
  // 距離情報初期化
  int n = graph.getNodeN();
  vector<ll> d(n, INF);
  d[s] = 0;

  // 全ての辺に対して、nodeN回更新を掛ける
  for(int i = 0; i < n; i++) {
    for(Node node : graph.getNodes()) {
      for(Edge edge : node.edges) {
        if(d[edge.to] > d[node.id] + edge.cost) {
          d[edge.to] = d[node.id] + edge.cost;

          // 負閉路検出
          if(node.id == n-1 && edge.to == n-1) {
            d[n-1] = INF;
            return d;
          }
        }
      }
    }
  }
  return d;
}
/**
  ワーシャルフロイド法
  計算量: O(V^3)
  */
vector<vector<ll>> warshallFloyd(Graph graph) {
  // 距離情報初期化
  int n = graph.getNodeN();
  vector<vector<ll>> d(n, vector<ll>(n, INF));
  for(int i = 0; i < n; i++) {
    d[i][i] = 0;
  }
  for(Node node : graph.getNodes()) {
    for(Edge edge : node.edges) {
      d[node.id][edge.to] = edge.cost;
    }
  }

  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}
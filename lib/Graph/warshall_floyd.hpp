/**
  ワーシャルフロイド法
  計算量: O(V^3)
  */
vector<vector<ll>> warshallFloyd(Graph g) {
  int n = g.getNodeN();
  vector<Node> graph = g.getGraph();

  vector<vector<ll>> d(n, vector<ll>(n, INF));

  for(int i = 0; i < n; i++) {
    d[i][i] = 0;
    for(Edge edge : graph[i].edges) {
      d[i][edge.to] = edge.cost;
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
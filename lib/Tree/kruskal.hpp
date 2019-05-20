ll kruskal(Graph graph) {
  // 辺を全てpriority_queueに突っ込む
  using P = pair<ll, pair<int, int>>;
  priority_queue<P, vector<P>, greater<P>> queue;
  for(Node node : graph.getNodes()) {
    for(Edge edge : node.edges) {
      queue.push(make_pair(edge.cost, make_pair(node.id, edge.to)));
    }
  }

  // 辺を小さい順に見ていき、UnionFindで閉路検出しながら最小全域木を構築
  int n = graph.getNodeN();
  UnionFind uf = UnionFind(n);
  sumTreeCost = 0;
  while(!queue.empty()) {
    P p = queue.top(); queue.pop();
    ll cost = p.first;
    int from = p.second.first, to = p.second.second;
    if(uf.same(a, b)) continue;
    uf.unite(a, b);
    sumTreeCost += cost;
  }
  return sumTreeCost;
}
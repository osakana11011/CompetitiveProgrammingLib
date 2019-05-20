/**
  プリム法
  計算量: O((V+E)logV)
  */
ll prim(Graph graph) {
  // 初期化
  int n = graph.getNodeN();
  bool used[n];
  for(int i = 0; i < n; i++) used[i] = false;

  // 本処理
  vector<Node> nodes = graph.getNodes();
  priority_queue<pll, vector<pll>, greater<pll>> queue;  // cost, to
  queue.push(pll(0, 0));
  ll sumTreeCost = 0;

  while(!queue.empty()) {
    pll p = queue.top(); queue.pop();
    ll cost = p.first;
    int pos = p.second;

    if(used[pos]) continue;
    used[pos] = true;
    sumTreeCost += cost;

    for(Edge edge : nodes[pos].edges)
      queue.push(pll(edge.cost, edge.to));
  }
  return sumTreeCost;
}

vector<ll> dijkstra(Graph g, int s) {
  int n = g.getNodeN();
  vector<Node> graph = g.getGraph();

  // 距離情報初期化
  vector<ll> d(n, INF);
  d[s] = 0;

  // sから探索を始める
  // キューの要素は、(コスト, ノード番号)
  priority_queue<P<ll> , vector<P<ll>> ,greater<P<ll>>> queue;
  queue.push(P<ll>(0, s));
  while(!queue.empty()) {
    P<ll> p=queue.top(); queue.pop();
    ll cost = p.first;
    int pos = p.second;

    if(d[pos] < cost) continue;
    for(int i = 0; i < graph[pos].edges.size(); i++){
      Edge e = graph[pos].edges[i];
      if(cost + e.cost < d[e.to]) {
        d[e.to] = cost + e.cost;
        queue.push(P<ll>(d[e.to], e.to));
      }
    }
  }
  return d;
}
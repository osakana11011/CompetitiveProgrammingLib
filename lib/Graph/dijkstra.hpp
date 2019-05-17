vector<ll> dijkstra(Graph graph, int s) {
  // 距離情報初期化
  int n = graph.getNodeN();
  vector<ll> d(n, INF);
  d[s] = 0;

  // sから探索を始める
  // キューの要素は、(コスト, ノード番号)
  vector<Node> nodes = graph.getNodes();
  priority_queue<P<ll> , vector<P<ll>> ,greater<P<ll>>> queue;
  queue.push(P<ll>(0, s));
  while(!queue.empty()) {
    P<ll> p=queue.top(); queue.pop();
    ll cost = p.first;
    int pos = p.second;

    if(d[pos] < cost) continue;

    for(Edge edge : nodes[pos].edges) {
      if(d[edge.to] > cost + edge.cost) {
        d[edge.to] = cost + edge.cost;
        queue.push(P<ll>(d[edge.to], edge.to));
      }
    }
  }
  return d;
}
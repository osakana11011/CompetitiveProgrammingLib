/**
  ダイクストラ法 (単一始点最短経路問題)
  g: グラフ
  s: 始点
  */
template <typename T = int>
vector<T> dijkstra(Graph<T> g, int s) {
  // 距離情報初期化
  T infT = numeric_limits<T>::max() / 2;
  vector<T> d(g.n, infT);
  d[s] = 0;

  // sから探索を始める
  priority_queue<P<T> , vector<P<T>> ,greater<P<T>>> queue;
  queue.push(make_pair(0, s));

  while(!queue.empty()) {
    P<T> p = queue.top(); queue.pop();
    T nowCost = p.first;
    int pos = p.second;

    if(d[pos] < nowCost) continue;

    for(Edge<T> edge : g.graph[pos]) {
      if(d[edge.to] > d[pos] + edge.cost) {
        d[edge.to] = d[pos] + edge.cost;
        queue.push(make_pair(d[edge.to], edge.to));
      }
    }
  }
  return d;
}
/**
  ダイクストラ法 (単一始点最短経路問題)
  WARNING: 辺の重みに負数がある時は使えない

  引数:
    - Graph<T> g: グラフ
    - int s: 出発地点のノード番号

  返り値:
    - 出発地点sからのそれぞれのノードへの距離

  計算量:
    - (E+V)logV

  依存ライブラリ:
    - template.hpp
    - Graph/ShortestPath/common.hpp
*/
template <typename T = int>
vector<T> dijkstra(Graph<T> g, int s) {
  // 距離情報初期化
  T INF = getINF<T>();
  vector<T> d(g.n, INF);
  d[s] = 0;

  // 優先度付きキューを用いて、次探索するべきノードを求める
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
/**
  プリム法 (最小全域木)

  引数:
    - Graph<T> g: グラフ

  返り値:
    - 最小全域木の総コスト

  依存ライブラリ:
    - template.hpp
    - Graph/ShortestPath/common.hpp

  計算量:
    - O((V+E)logV)
*/
template <typename T = int>
T prim(Graph<T> g) {
  // 初期化
  bool used[g.n];
  for(int i = 0; i < g.n; i++) used[i] = false;

  // 本処理
  priority_queue<P<T>, vector<P<T>>, greater<P<T>>> queue;  // cost, to
  queue.push(make_pair(0, 0));
  T sumTreeCost = 0;

  while(!queue.empty()) {
    P<T> p = queue.top(); queue.pop();
    T cost = p.first;
    int pos = p.second;

    if(used[pos]) continue;  // posが既に木に含まれているならスキップ
    used[pos] = true;
    sumTreeCost += cost;

    for(Edge edge : g.graph[pos]) {
      queue.push(make_pair(edge.cost, edge.to));
    }
  }
  return sumTreeCost;
}

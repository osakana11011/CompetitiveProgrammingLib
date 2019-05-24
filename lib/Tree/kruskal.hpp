/**
  クラスカル法 (最小全域木)

  引数:
    - Graph<T> g: グラフ

  返り値:
    - 最小全域木の総コスト

  依存ライブラリ:
    - template.hpp
    - Graph/ShortestPath/common.hpp
    - Tree/union_find.hpp
*/
template <typename T = int>
T kruskal(Graph<T> g) {
  // 全ての辺をpriority_queueに突っ込む
  using _P = pair<T, P<int>>;  // <辺のコスト, <辺の始点, 辺の終点>>
  priority_queue<_P, vector<_P>, greater<_P>> queue;
  for(int from = 0; from < g.n; from++) {
    for(Edge<T> edge : g.graph[from]) {
      queue.push(make_pair(edge.cost, make_pair(from, edge.to)));
    }
  }

  // 辺を小さい順に見ていき、UnionFindで閉路検出しながら最小全域木を構築
  UnionFind uf = UnionFind(g.n);
  T sumTreeCost = 0;
  while(!queue.empty()) {
    _P p = queue.top(); queue.pop();
    T cost = p.first;
    int from = p.second.first, to = p.second.second;

    if(uf.same(to, from)) continue;
    uf.unite(to, from);
    sumTreeCost += cost;
  }
  return sumTreeCost;
}
struct UnionFind {
  vector<int> parent;

  UnionFind(int N) : parent(N) {
    for(int i = 0; i < N; i++) parent[i] = i;
  }

  /**
    要素xの根を求める
    */
  int root(int x) {
    if(parent[x] == x) return x;
    return parent[x] = root(parent[x]);  // 経路圧縮しつつ根を返す
  }

  /**
    要素xと要素yの木を併合
    */
  void unite(int x, int y) {
    int x_root = root(x);
    int y_root = root(y);
    if(x_root == y_root) return;
    parent[x_root] = y_root;
  }

  /**
    要素xと要素yが同じ木に属しているか
    */
  bool same(int x, int y) {
    int x_root = root(x);
    int y_root = root(y);
    return x_root == y_root;
  }
};
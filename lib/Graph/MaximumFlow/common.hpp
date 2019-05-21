/**
  辺
  to: どこへ辺が出ているか
  rev: 逆向き矢印のインデックス
  cap: 辺に流せる量
  */
template <typename T = int>
struct Edge {
  int to;
  T cap;
  int rev;
  Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
};


/**
  グラフ
  n: 頂点数
  graph: グラフ本体
  T: 辺のcapacityの型
  */
template <typename T = int>
class Graph {
  public :
    int n;
    vector<vector<Edge<T>>> graph;

    Graph(int n) {
      this->n = n;
      this->graph.assign(n, vector<Edge<T>>());
    }

    void addEdge(int from, int to, T cap) {
      this->graph[from].push_back(Edge<T>(to, cap, this->graph[to].size()));
      this->graph[to].push_back(Edge<T>(from, 0, this->graph[from].size() - 1));
    }
};
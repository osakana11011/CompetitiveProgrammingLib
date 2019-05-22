/**
  辺
  to: 辺の行き先
  cost: 辺の重み
  T: 重みの型
*/
template <typename T = int>
struct Edge {
  int to;
  T cost;
  Edge(int to, T cost) : to(to), cost(cost) {}
};

/**
  n: 頂点数
  graph: グラフ本体
*/
template <typename T = int>
class Graph {
  public:
    int n;
    vector<vector<Edge<T>>> graph;

    Graph(int n) {
      this->n = n;
      this->graph.assign(n, vector<Edge<T>>());
    }

    void addEdge(int from, int to, T cost) {
      this->graph[from].push_back(Edge<T>(to, cost));
    }
};
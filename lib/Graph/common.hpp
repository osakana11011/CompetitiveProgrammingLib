#include <vector>
#include <queue>

using namespace std;

// 型
using ll = long long;
template <typename T> using P = pair<T, T>;
// 定数
const ll INF = 1e18;



// 辺
struct Edge {
  int to;
  ll cost;
  Edge(int to, ll cost) : to(to), cost(cost) {}
};

// ノード
struct Node {
  vector<Edge> edges;
  Node() {}
  void addEdge(int to, ll cost) {
    edges.push_back(Edge(to, cost));
  }
};

// グラフ
class Graph {
  private:
    int nodeN;
    vector<Node> graph;
  public:
    Graph(int nodeN) {
      this->nodeN = nodeN;
      for(int i = 0; i < nodeN; i++) {
        graph.push_back(Node());
      }
    }
    /**
      辺を追加する
      */
    void addEdge(int from, int to, ll cost) {
      graph[from].addEdge(to, cost);
    }
    /**
      getter
      */
    int getNodeN() {
      return this->nodeN;
    }
    vector<Node> getGraph() {
      return this->graph;
    }
};
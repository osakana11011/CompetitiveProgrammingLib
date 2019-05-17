#include <vector>
#include <queue>

using namespace std;

/*--- begin ---*/

// 辺
struct Edge {
  int to;
  ll cost;
  Edge(int to, ll cost) : to(to), cost(cost) {}
};

// ノード
struct Node {
  int id;
  vector<Edge> edges;
  Node(int id) : id(id) {}
  void addEdge(int to, ll cost) {
    edges.push_back(Edge(to, cost));
  }
};

// グラフ
class Graph {
  private:
    int nodeN;
    vector<Node> nodes;
  public:
    Graph(int nodeN) {
      this->nodeN = nodeN;
      for(int i = 0; i < nodeN; i++) {
        nodes.push_back(Node(i));
      }
    }
    void addEdge(int from, int to, ll cost) {
      nodes[from].addEdge(to, cost);
    }
    /**
      getter
      */
    int getNodeN() {
      return this->nodeN;
    }
    vector<Node> getNodes() {
      return this->nodes;
    }
};

/*--- end ---*/

// 辺
struct Edge {
  int to;
  ll cap;
  int rev;
  Edge(int to, ll cap, int rev) : to(to), cap(cap), rev(rev) {}
};

// ノード
struct Node {
  int id;
  vector<Edge> edges;
  Node(int id) : id(id) {}
  void addEdge(int to, ll cap, int rev) {
    edges.push_back(Edge(to, cap, rev));
  }
};

struct Graph {
  int nodeN;
  vector<Node> nodes;

  Graph(int nodeN) : nodeN(nodeN) {
    for(int i = 0; i < nodeN; i++) {
      nodes.push_back(Node(i));
    }
  }

  void addEdge(int from, int to, ll cap) {
    nodes[from].addEdge(to, cap, nodes[to].edges.size());
    nodes[to].addEdge(from, 0, nodes[from].edges.size()-1);
  }
};
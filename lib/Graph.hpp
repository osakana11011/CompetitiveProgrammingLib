#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll , ll> P;
const ll INF = 1e18;

// グラフの辺
struct Edge {
  int to;
  int cost;

  Edge(int to, int cost) : to(to), cost(cost) {}
};

// ノード
struct Node {
  vector<Edge> edges;

  Node() {}
  void addEdge(int to, int cost) {
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
    void addEdge(int from, int to, int cost) {
      graph[from].addEdge(to, cost);
    }
    /**
      ダイクストラ法
      s: 始点
      */
    vector<ll> dijkstra(int s) {
      // 距離情報初期化
      vector<ll> d;
      for(int i = 0; i < this->nodeN; i++) {
        d.push_back(INF);
      }
      d[0] = 0;

      // sから探索を始める
      // キューの要素は、(コスト, ノード番号)
      priority_queue< P , vector<P> ,greater<P> > queue;
      queue.push(P(0, s));
      while(!queue.empty()) {
        P p=queue.top(); queue.pop();
        ll pos=p.second, cost=p.first;

        if(d[pos] < cost) continue;
        for(int i = 0; i < this->graph[pos].edges.size(); i++){
          Edge e = this->graph[pos].edges[i];
          if(cost + e.cost < d[e.to]) {
            d[e.to] = cost + e.cost;
            queue.push(P(d[e.to], e.to));
          }
        }
      }
      return d;
    }
};

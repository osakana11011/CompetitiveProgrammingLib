#include <vector>
#include <queue>

using namespace std;

// 型
using ll = long long;
template <typename T> using P = pair<T, T>;

// 定数
const ll INF = 1e18;

// 辺
template <typename T>
struct Edge {
  int to;
  T cost;
  Edge(int to, T cost) : to(to), cost(cost) {}
};

// ノード
template <typename T>
struct Node {
  vector< Edge<T> > edges;
  Node() {}
  void addEdge(int to, T cost) {
    edges.push_back(Edge<T>(to, cost));
  }
};

// グラフ
template <typename T>
class Graph {
  private:
    int nodeN;
    vector< Node<T> > graph;
  public:
    Graph(int nodeN) {
      this->nodeN = nodeN;
      for(int i = 0; i < nodeN; i++) {
        graph.push_back(Node<T>());
      }
    }
    /**
      辺を追加する
      */
    void addEdge(int from, int to, T cost) {
      graph[from].addEdge(to, cost);
    }
    /**
      ダイクストラ法
      s: 始点
      */
    vector<T> dijkstra(int s) {
      // 距離情報初期化
      vector<T> d;
      for(int i = 0; i < this->nodeN; i++) {
        d.push_back(INF);
      }
      d[0] = 0;

      // sから探索を始める
      // キューの要素は、(コスト, ノード番号)
      priority_queue< P<T> , vector< P<T> > ,greater< P<T> > > queue;
      queue.push(P<T>(0, s));
      while(!queue.empty()) {
        P<T> p=queue.top(); queue.pop();
        T cost=p.first;
        int pos=p.second;

        if(d[pos] < cost) continue;
        for(int i = 0; i < this->graph[pos].edges.size(); i++){
          Edge<T> e = this->graph[pos].edges[i];
          if(cost + e.cost < d[e.to]) {
            d[e.to] = cost + e.cost;
            queue.push(P<T>(d[e.to], e.to));
          }
        }
      }
      return d;
    }
};

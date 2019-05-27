/**
  フォード・ファルカーソンのアルゴリズム (有向グラフの最大フローを求める)

  依存ライブラリ:
    - template.hpp
    - Graph/MaximumFlow/common.hpp
*/
template <typename T = int>
class FordFulkerson : public Graph<T> {
  private:
    vector<int> used;
    int timestamp;

    // idx → t と行く適当なフローを計算する
    T dfs(int idx, int t, T commingFlow) {
      if(idx == t) return commingFlow;

      // 一度通った所にtimestampを押すことで、ループしないようにしている
      used[idx] = timestamp;

      for(int i = 0; i < this->graph[idx].size(); i++) {
        Edge<T> edge = this->graph[idx][i];
        if(edge.cap > 0 && used[edge.to] != timestamp) {
          T d = dfs(edge.to, t, min(commingFlow, edge.cap));
          if(d > 0) {
            this->graph[idx][i].cap -= d;
            this->graph[edge.to][edge.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }

  public :
    FordFulkerson(int n) : Graph<T>(n) {
      used.assign(this->n, -1);
    }

    /**
      sからtへの最大フローを求める
    */
    T maxFlow(int s, int t) {
      T flow = 0, k_flow;
      timestamp = 0;

      while((k_flow = dfs(s, t, INF<T>)) > 0) {
        flow += k_flow;
        timestamp++;
      }
      return flow;
    }
};
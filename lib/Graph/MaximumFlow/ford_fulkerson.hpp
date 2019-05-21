/**
  有向グラフの最大フローを求める (フォード・ファルカーソンのアルゴリズム)
  g: グラフ本体
  used: 同じフロー内で循環しないようにtimestampを書いていく
  timestamp: 何個目のフローか
  */
template <typename T = int>
class FordFulkerson : public Graph<T> {
  vector<int> used;
  int timestamp;

  public :
    FordFulkerson(int n) : Graph<T>(n) {
      used.assign(this->n, -1);
    }

    /**
      nodeIdからtまでの1つのフローを求める
      sから流れる量はcommingFlow
      */
    T dfs(int idx, int t, T commingFlow) {
      if(idx == t) return commingFlow;  // toに辿り着いた

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

    /**
      sからtへの最大フローを求める
      */
    T maxFlow(int s, int t) {
      T infT = numeric_limits<T>::max();
      T flow = 0, k_flow;
      timestamp = 0;

      while((k_flow = dfs(s, t, infT)) > 0) {
        flow += k_flow;
        timestamp++;
      }
      return flow;
    }
};
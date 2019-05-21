struct FordFulkerson {
  Graph graph;
  vector<vector<Edge>> tmp_graph;
  vector<int> used;
  int timestamp;

  FordFulkerson(Graph graph) : graph(graph) {
    tmp_graph.resize(graph.nodeN);
    used.assign(graph.nodeN, -1);
  }

  /**
    nodeIdからtまでの1つのフローを求める
    なお、sから流れる量はcommingFlow
    */
  ll dfs(int nodeId, int t, ll commingFlow) {
    if(nodeId == t) return commingFlow;  // tに辿り着いた
    used[nodeId] = timestamp;

    Node node = graph.nodes[nodeId];
    for(int i = 0; i < node.edges.size(); i++) {
      Edge edge = node.edges[i];
      if(edge.cap > 0 && used[edge.to] != timestamp) {
        ll d = dfs(edge.to, t, min(commingFlow, edge.cap));
        if(d > 0) {
          graph.nodes[nodeId].edges[i].cap -= d;
          graph.nodes[edge.to].edges[edge.rev].cap += d;
          return d;
        }
      }
    }

    return 0;
  }

  /**
    sからtへの最大フローを求める
    */
  ll maxFlow(int s, int t) {
    ll flow = 0, k_flow;
    timestamp = 0;

    while((k_flow = dfs(s, t, INF)) > 0) {
      flow += k_flow;
      timestamp++;
    }
    return flow;
  }
};
bool dfs(GRAPH& graph, int node, vector<bool>& visited, int par = -1) {
    // returns if the component is cyclic or not

    bool cyclic = false;
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs(graph, neighbor, visited, node);
        else if (neighbor != par)
            cyclic = true;
    }

    return cyclic;
}
void add_edge(GRAPH& graph, int from, int to, bool isDirected = true) {
    assert(from < graph.size());

    graph[from].push_back(to);
    if (!isDirected) {
        assert(to < graph.size());
        graph[to].push_back(from);
    }
}
int count_components(int n, vector< vector<int> /*[from, to]*/ >& edges) { // time & memory = O(E + V)
    // build a standard graph from edges:
    /// Warning: 1-based by default

    GRAPH graph(n + 1); // O(E + V)
    for (auto& edge : edges)
        add_edge(graph, edge[0], edge[1], false);

    // count:
    int result = 0, cyclic = 0;
    vector<bool> visited(n + 1);
    for (int node = 1; node <= n; ++node) {
        if (!visited[node]) {
            ++result;
            cyclic += dfs(graph, node, visited);
        }
    }

    return result;
}
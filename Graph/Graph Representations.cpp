#include <bits/stdc++.h>
using namespace std;

/// Graph Representations:
const int N = 1000;

// 1- adjacency matrix:
bool adjMatrix[N][N];
int adjMatrixWeighted[N][N]; // weighted representation

// rare but good to know:
vector<int> adjMatrixAll[N][N]; // to keep all edges between eny pair of nodes
map< pair<int, int>, int > adjMatrixMap; // for the sparse graphs: it's better to keep the edges
// map < <from, to>, weight >

// 2- adjacency list:
vector< vector<int> > adjList;
vector< vector< pair<int, int> > > adjListCost; // cost relation
//            pair<to, weight>

// 3- edge list:
struct edge {
    int from, to, w;

    edge(int from, int to, int w) : from(from), to(to), w(w) { }

    bool operator < (const edge& e) {
        return w < e.w; // sort increasingly based on the weight
    }
};
vector<edge> edgeList;

int main()
{
    int n, edges;
    int from, to, cost;

    /// adj matrix input:

    cin >> n >> edges;
    /*
	 	 3 5
	 	 0 3 10
	 	 1 5 2
	 	 3 7 -2
	 	 0 3 2
	 	 2 4 6
	 */

    // must initialize adjMatrixWeighted with 00, to minimize correctly
    for (auto & i : adjMatrixWeighted) {
        for (int & j : i) {
            j = INT_MAX;
        }
    }

    for (int i = 1; i <= edges; ++i) {
        cin >> from >> to >> cost;
        adjMatrixWeighted[from][to] = min(adjMatrixWeighted[from][to], cost); // min cost

        // if undirected:
        adjMatrixWeighted[to][from] = adjMatrixWeighted[from][to];
    }


    /// adj list input:

    /*
		3
		2	1 2
		1	2
		2	0 1
	 */
    cin >> n;
    adjList = vector< vector<int> >(n); // resize
    for (int i = 0; i < n; ++i) {
        int cnt; cin >> cnt;
        while (cnt--) {
            cin >> to;
            adjList[i].push_back(to);
        }
    }

    // with cost:

    /*
		3
		2	1 13	2 4
		1	2 9		3 -4
		2	0 -7	1 8
	 */
    cin >> n;
    adjListCost = vector< vector<pair<int, int>> >(n);
    for (int i = 0; i < n; ++i) {
        int cnt; cin >> cnt;
        while (cnt--) {
            cin >> to >> cost;
            adjListCost[i].push_back({to, cost});
        }
    }

    return 0;
}
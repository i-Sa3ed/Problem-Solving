#include <bits/stdc++.h>
using namespace std;

/// DFS
int n, e; // nodes, edges
vector< vector<int> > adjList;
vector<bool> visited;

vector<int> topsort; // topological sort

void dfs(int node) { // O(e + v) = (edges + vertices)
    visited[node] = true;

    for (int child : adjList[node]) {
        if(!visited[child]) // to avoid the cyclic behavior (consider it as base case)
            dfs(child);
    }

    topsort.push_back(node); // app2
}

// app1
int connected_components() { // O(e + v)
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { // found another isolated component
            dfs(i); // mark its neighbors
            ++res;
        }
    }

    return res;
}

// app3
vector<int> start, finish;
int timer = 0;
bool anyCycle = false;
void dfs_edge_classification(int node) {
    start[node] = timer++;

    for (int child : adjList[node]) {
        if (start[child] == -1) // not visited before => treed edge
            dfs_edge_classification(child);
        else {
            if (finish[child] == -1) // back edge => cycle
                anyCycle = true;
            else if (start[child] < start[node])
                ; // forward edge
            else
                ; // cross edge
        }
    }

    finish[node] = timer++;
}

// app4: Flood Fill
// given a maze, how many cells u could reach?
/*
..X.
.X.X
..X.

...x.
..x..
.x...
x....

....X...
....XXXX
..X.....
.X....XX
..X.X.X.
..X...X.
...X..XX
*/

vector<string> maze;
vector<vector<bool>> vis;

int cnt = 0;
int rows, cols;
bool valid (int r, int c) { return r >= 0 and r < rows and c >= 0 and c < cols; }
void cnt_reachable_cells(int r = 0, int c = 0) {
    if (!valid(r, c) or maze[r][c] == 'X' or vis[r][c])
        return; // invalid position or block position

    vis[r][c] = true;
    ++cnt;

    // try 4 neighbor cells:
    cnt_reachable_cells(r, c - 1);
    cnt_reachable_cells(r, c + 1);
    cnt_reachable_cells(r - 1, c);
    cnt_reachable_cells(r + 1, c);
}




int main()
{
    cin >> n >> e;
    start = vector<int>(n, -1);
    finish = vector<int>(n, -1);

    /// flood fill test:
    cin >> rows >> cols;
    for (int i = 1; i <= rows; ++i) {
        string row; cin >> row;
        maze.push_back(row);
    }

    vis = vector<vector<bool>>(n, vector<bool>(n));

    cnt_reachable_cells();
    cout << cnt << endl;


    return 0;
}
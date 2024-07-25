////////////////// Backtracking ///////////////////
// blueprint:
void Backtracking(state) {
    if found_solution(state)
        mark_solution_found
        return

    for each child_state of state: if valid(child_state):
        do changes

        Backtracking(child_state)

        undo changes
}

/////////////////////// inversions count /////////////////////
// C++ program to Count Inversions in 
// an array using Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 

int _mergeSort(int arr[], int temp[], 
			int left, int right); 
int merge(int arr[], int temp[], 
		int left, int mid, int right); 

/* This function sorts the input 
array and returns the number 
of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
	int temp[array_size]; 
	return _mergeSort(arr, temp, 0, 
					array_size - 1); 
} 

/* An auxiliary recursive function that 
sorts the input array and returns the 
number of inversions in the array. */
int _mergeSort(int arr[], int temp[], 
			int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) 
	{ 
		/* Divide the array into two parts and 
		call _mergeSortAndCountInv() for 
		each of the parts */
		mid = (right + left) / 2; 

		/* Inversion count will be sum of inversions 
		in left-part, right-part and number of 
		inversions in merging */
		inv_count += _mergeSort(arr, temp, 
								left, mid); 
		inv_count += _mergeSort(arr, temp, 
								mid + 1, right); 

		// Merge the two parts 
		inv_count += merge(arr, temp, 
						left, mid + 1, right); 
	} 
	return inv_count; 
} 

/* This funt merges two sorted arrays and 
returns inversion count in the arrays.*/
int merge(int arr[], int temp[], 
		int left, int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	// i is index for left subarray 
	i = left; 

	// j is index for right subarray 
	j = mid; 

	// k is index for resultant merged 
	// subarray 
	k = left; 

	while ((i <= mid - 1) && 
		(j <= right)) 
	{ 
		if (arr[i] <= arr[j]) 
		{ 
			temp[k++] = arr[i++]; 
		} 
		else
		{ 
			temp[k++] = arr[j++]; 

			/* This is tricky -- see above 
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i); 
		} 
	} 

	/* Copy the remaining elements of left 
	subarray (if there are any) to temp*/
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 

	/* Copy the remaining elements of right 
	subarray (if there are any) to temp*/
	while (j <= right) 
		temp[k++] = arr[j++]; 

	/* Copy back the merged elements to 
	original array*/
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 20, 6, 4, 5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int ans = mergeSort(arr, n); 
	cout << " Number of inversions are " << ans; 
	return 0; 
} 

/////////////////// DFS applications ////////////////
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

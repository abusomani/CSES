#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int dist_u[MAXN], dist_v[MAXN];
int N;

void dfs(int node, int parent, int dist[], int d) {
    dist[node] = d;
    for (int nei : graph[node])
        if (nei != parent)
            dfs(nei, node, dist, d + 1);
}


int farthestNode(int dist[]) {
    int idx = 1;
    for (int i = 1; i <= N; i++)
        if (dist[i] > dist[idx]) 
            idx = i;
    return idx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    N = n;

    for (int i = 1; i <= n; i++) graph[i].clear();

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // DFS1: from arbitrary node (1) to find u
    dfs(1, -1, dist_u, 0);
    int u = farthestNode(dist_u);

    // DFS2: from u to find v and fill dist_u[]
    dfs(u, -1, dist_u, 0);
    int v = farthestNode(dist_u);

    // DFS3: from v to fill dist_v[]
    dfs(v, -1, dist_v, 0);


    for (int i = 1; i <= n; i++)
        cout << max(dist_u[i], dist_v[i]) << " ";

    return 0;
}

/*
    Binary Lifting for LCA: https://www.youtube.com/watch?v=dOAxrhAUIhA
    Run a DFS to store depths of node as well as computing the jumps array for binary lifting
    For LCA:
        1. Make sure that the deeper node is first
        2. Compute the depth difference and lift the deeper node to bring at same depth of the other node using Bit manipulation & jumps
        3. Now if both nodes are same then that itself is the LCA
        4. Else we need to start from the maximum depth possible and keep coming down until the ancesstor matches
        5. If the ancestors dont match then we need to lift to those ancestors so that ultimately we come to the immediate children of LCA
    LCA is the parent of the nodes that we stand on.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
const int MX_HEIGHT = 23;
vector<vector<int>> jumps;
vector<vector<int>> graph;
vector<int> depth;

void dfs(int a){
    for(auto c: graph[a]){
        depth[c] = depth[a] + 1;
        jumps[c][0] = a;
        // binary lifting
        for(int h=1; h<MX_HEIGHT; h++)
            jumps[c][h] = jumps[jumps[c][h-1]][h-1];
        dfs(c);
    }
}

int lca(int a, int b){
    // always have depth of `a` deeper
    if(depth[a] < depth[b])
        return lca(b, a);
    
    int depthDiff = depth[a] - depth[b];
    for(int h=0; h<MX_HEIGHT; h++)
        if(depthDiff & (1 << h))
            a = jumps[a][h];
    // same height
    if(a == b)return a;
    for(int h=MX_HEIGHT-1; h>=0; h--){
        if(jumps[a][h] != jumps[b][h]){
            a = jumps[a][h];
            b = jumps[b][h];
        }
    }
    return jumps[a][0]; // 1st level children of the LCA
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q, x, y, a;
    cin>>N>>Q;
    graph = vector<vector<int>>(N+1);
    jumps = vector<vector<int>>(N+1, vector<int>(MX_HEIGHT));
    depth = vector<int>(N+1, 0);
    for(int i=2; i<=N; i++){
        cin>>a;
        graph[a].push_back(i); // i is a's children
    }
    jumps[1][0] = 1; // 1 is parent of itself
    dfs(1);
    while(Q--){
        cin>>x>>y;
        cout<<lca(x, y)<<endl;
    }
    return 0;
}
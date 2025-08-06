/*
    Binary Lifting: https://www.youtube.com/watch?v=oib-XsjFa-M
    Idea is to have parents of nodes stored at various levels in powers of 2 i.e. 1st parent, 2nd parent. 4th parent and so on
    Then finding Kth parent / ancestor is simply the binary representation of K and finding appropriate parent

    for(all nodes)
        up[node][0] = parent[node]

    for(h=1 ... MX_HEIGHT)  // where MX_HEIGHT is LOG(max nodes for skewed trees)
        for(nodes v=0 .. N-1)
            up[v][h] = up[up[v][h-1]][h-1]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int MX_HEIGHT = 23;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q, x, k;
    cin>>N>>Q;
    vector<vector<int>> up(N+1, vector<int>(MX_HEIGHT));
    vector<int> parent(N+1);
    parent[0] = N;
    parent[N] = N;
    for(int i=1; i<N; i++){
        cin>>x;
        parent[i] = x - 1;
    }
    for(int h=0; h<MX_HEIGHT; h++)up[N][h] = N;
    for(int v=0; v<N; v++)up[v][0] = parent[v];
    for(int h=1; h<MX_HEIGHT; h++)
        for(int v=0; v<N; v++)
            up[v][h] = up[ up[v][h-1] ][h-1];
    while(Q--){
        cin>>x>>k;
        int node = x-1;
        for(int h=0; h<MX_HEIGHT; h++){
            if(k & (1 << h))
                node = up[node][h];
        }
        if(node == N)cout<<-1<<endl;
        else cout<<node + 1<<endl;
    }
    return 0;
}
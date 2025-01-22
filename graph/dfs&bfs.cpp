#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int mod = 1000000007;
#define int long long
const int N=1e5+10;
vector<vector<int>> g(N);

vector<int>depth(N);
vector<int>height(N);
void dfs(int v, int par=0)
{
    for (auto child: g[v]) {
        if(child==par) continue;
        depth[child]=depth[v] +1;
        dfs(child,v);
        height[v]=max(height[v],height[child] +1);
    }
}

int vis [N]; 
int level [N];
void bfs(int source){
    queue<int> q; 
    q.push(source);
    vis [source] = 1;

    while(!q.empty()){
        int cur_v = q.front();
        q.pop();

        for (int child : g[cur_v]){ 
            if( !vis [child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v] +1;
            }
        }
    }
}

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 1;
    cin >> n;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin >>x >> y ;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout  << i << " "  << depth[i] << " " <<  height[i] << "\n";
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        cout  << i << " " <<  level[i] << "\n";
    }
}
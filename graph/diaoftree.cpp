#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int mod = 1000000007;
#define int long long
const int N=1e5+10;

vector<vector<int>> g(N);
vector<int>depth(N);

void dfs(int v, int par=0)
{

    for (auto child: g[v]) {
        if(child==par) continue;
        depth[child]=depth[v] +1;
        dfs(child,v);
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
    int mxdepth =-1;
    int mxnode;
    for(int i=1;i<=n;i++){
        if(mxdepth<depth[i]){
            mxdepth=depth[i];
            mxnode=i;
        }
        depth[i]=0; //for calculating depth wrt to max depth in this case
    }

    dfs(mxnode);
    int mxdepth =-1;
    for(int i=1;i<=n;i++){
        if(mxdepth<depth[i]){
            mxdepth=depth[i];
        }
    }
    cout << mxdepth << "\n";

    
}
#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int mod = 1000000007;
const int N=1e5+10;

vector<vector<int>> g(N);
vector<int>subtree_sum(N);
vector<int> val(N);
vector<int> even_ct(N);

void dfs(int vertex, int par=0)
{
    // Take action  on vertex before entering the vertex
    subtree_sum[vertex] +=val[vertex];
    if(vertex%2==0)  even_ct[vertex]++;

    for (auto child: g[vertex]) {
        // take action on child before entering into dfs of child node
        if(child==par) continue;

        dfs(child,vertex);

        // Take action on child after exiting dfs on child node
        subtree_sum[vertex] +=subtree_sum[child];
        even_ct[vertex] += even_ct[child] ;

    }
    // Take action on vertex after exiting the vertex
    
}

// In each query, (q < 10^5), print subtree sum of V and number of even numbers in a subtree of v
void solvequeries(){
    dfs(1);
    int q;
    for(int i=1;i<=13;i++) cout << subtree_sum[i] << " " << even_ct[i] <<"\n" ;
    // cin >> q;
    // while(q--){
    //     int v;
    //     cin >> v ;
    //     cout << subtree_sum[v] << " " << even_ct[v] <<"\n" ;
    // }

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
    for(int i=1;i<=n;i++){
        val[i]=i;
        // cin >> val[i];
    }
    solvequeries();
}
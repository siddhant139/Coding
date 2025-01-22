#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7 ;
const int N=100000;

int dp[N];

// dp using memoization
int fb(int n,vector<int> dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fb(n-1,dp) + fb(n-2,dp);
}

void solve(int testcase){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fb(n,dp);
    return ;
}
// dp using memoization...

// dp using taulation
void solve2(int testcase){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++){
        if(i<2) dp[i]=i;
        else dp[i]=dp[i-1] + dp[i-2] ;
    }
    cout << dp[n];
    return;

}


int main(){
    memset(dp,-1,sizeof(dp));
    int t=1;
    // cin >> t;
    solve(t);  //dp using memoization
    solve2(t); //dp using tabulation

}
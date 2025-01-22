#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7 ;
const int N=100000;
vector<int> a(N);
int dp[N];

// longest_inceasing_subseqence_length by binary [time complexity O(nlogn)]
int lisb(int a[],int n){ // n is the size of array a[]
    vector<int > temp;
    for(int i=0;i<n;i++){
        if(a[i]> temp.back()) temp.push_back(a[i]);
        else {
            int ind=lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[ind]=a[ind];
        }
    }
    return temp.size();
}

// longest_inceasing_subseqence_length [time complexity O(n*n)]
int lis(int i){
    if(dp[i]!=0) return dp[i];
    int ans=1;
    for(int j=0 ; j < i ; j++){
        if(a[i]>a[j]){
            ans=max(ans,lis(j)+1);
        }
    }
    return dp[i]=ans;
}
main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    for(int i=0 ; i < n ; i++){
        cin >> a[i];
    }
    int ans =0;
    for(int j=0 ; j < n ; j++){
        ans=max(ans,lis(j));
    }
    cout << ans;

}
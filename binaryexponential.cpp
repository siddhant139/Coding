
#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7 ;

int binExpRecur(int a, int b){
    if (b==0) return 1;
    long long res = binExpRecur(a, b / 2);
    if (b&1){
        return (a*(res  * res )% M) % M;
    }
    else{
        return (res * res) % M;
    }
}


// x power n
int binExp(int64_t x,int64_t n)
{
    // if a<1e18
    // a=a%M;
    //a=binExp(a,b);
    int64_t ans=1;
    while(n>0)
    {
        if(n&1) ans=ans*x;
        x=x*x;
        n=n>>1;
    }
    return ans;
}


main(){
    int a,b,n;
    //cout << binExpRecur(a,b);
    cin >> n;
    vector<int> primefactor;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            primefactor.push_back(i);
            n/=i;
        }
        if(n>1) primefactor.push_back(n);
    }
    for(int p:primefactor){
        cout << p << " " ;
    }

}
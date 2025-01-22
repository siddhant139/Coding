#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int mod = 1000000007;
#define int long long

// @author: siddhant139

void runCase(int &testcase)
{
    int y, k , x,f=0;
    cin >> x >> y >> k ;
    int d,ans=0,n,m;
    d=x%y;
    d=y-d;
    cout << d << " " << y <<"\n";
    if(d > k) {
        cout << (x+k) << "\n";
        return;
    }
    while(ans!=k){
        d=x%y;
        d=y-d;
        ans+=d;
        if(ans > k) {
            ans-=d;
            cout << x + k-ans << "\n";
            return;
        }
        x+=d;
        // cout << x << "ss\n";
        while(x%y==0){
            x=x/y;
            // cout << x << " " << d << " " << ans << "\n";
        }
        if(x<y) {
            f=1;
            // cout << "sid" << "\n";
            break;
        }
    }
    cout << x << " " << k << " " << ans << "\n";
    if(f==1){
        int p=k-ans;
        d=y-x;
        cout<< d << " " << p << "\n";
        if(p==y) cout << x+1 <<"\n";
        else if(p<y) {
            if(p<d) cout << x+p <<"\n";
            else cout << ((x+p)%y)+1  <<"\n";
        }
        else if(p>y) {
            p-=d;
            p=p%(y-1);
            if(p<d) cout << x+p << "\n";
            else {
                cout <<((x+p)%y)+1 << "\n";
            }
        }
        return;
    }

    cout << x << "\n";
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++)
        runCase(i);
    return 0;
}
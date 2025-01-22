#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int mod = 1000000007;
#define int long long

// @author: siddhant139

void runCase(int &testcase)
{
    int n, k,mx=0,c=0,sm=0,ans=0;
    string s;
    vector <int> v;
    cin >> n >> k;
    cin >>  s;
    for(int i=n-1;i>=0;i--){
        c=0;
        if(s[i]=='1') v.push_back(1);
        else {
            while (s[i]=='0') {
                i--;
                c++;
            }
                // cout << c << "\n";
            if(i==-1) v.insert(v.end(), c, -1); 
            else v.push_back(-c+1);
        }
    }
    int l=v.size()-1;
    int l1=l;
    // cout << l+1 << "\n";
    for(auto e:v) {
        sm+=e*l1;
        l1--;
    }
    // cout << sm << " " << l << "\n";
    
    vector <int> a(l+1);
    for(int i=l;i>=0;i--){
        // cout << v[i] << "\n" ;
        a[l-i]=v[i];
        if(i!=l) mx+=v[i];
    }
    // cout << mx << "*\n";

    for(auto e:a) {
        cout << e << "a\n";
    }

    if(sm < k) {
        cout << -1 << '\n';
        return;
    }
    else if (sm==k) {
        int rep=0;
        for(int i=0;i<=l;i++){
            if(a[0]==-1 || a[0]==0) {
                while(a[i]==-1 || a[i]==0) {
                    // z++;
                    i++;
                }
                i--;
                // continue;
            }
            else if(a[i]!=0) rep++;
        }
        cout << rep << "\n";
        return;
    }
    else {
        int z=0;
        for(int i=1;i<=l;i++){
            if(i==1 && a[1]==-1) {
                while(a[i]==-1 || a[i]==0) {
                    z++;
                    i++;
                }
                continue;
            }
            ans+=mx*(i-z);
            cout << ans << " " << z << "\n";
            if(ans>=k){
                cout << i+1-z << "\n";
                return;
            }
            else {
                ans-=mx*(i-z);
                ans+=a[i]*i;
                mx=mx-a[i];
                if(a[i]==0) z++;
            }
        }
    }
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
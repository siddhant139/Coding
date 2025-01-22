#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int mod = 1000000007;
#define int long long

// @author: siddhant139

void runCase(int &testcase)
{
    int n, L ,m ,ans=0;
    cin >> n >> m>> L;
    vector<int> l(n);
    vector<int> r(n);
    vector<int> x(m);
    vector<int> v(m);
    for (int i=0;i<n;i++) cin >> l[i] >> r[i];
    for (int i=0;i<m;i++) cin >> x[i] >> v[i];

    if(testcase==131) {
        cout << n<< '-' << m << '-' << L << '-' ;
        for (int i=0;i<n;i++) cout <<  l[i] << '-' <<  r[i] << '-';
        for (int i=0;i<m;i++) cout <<  x[i] << '-' <<  v[i] << '-';
        cout << "\n";
        return;
    }
    

    int j=0;
    int s=1;
    for(int i=0;i<n;i++){
        int d;
        d=r[i]-l[i]+2;
        if(s>=d) continue;

        vector<int> t;
        while(j<m && x[j]<l[i] ){
            t.push_back(v[j]);
            j++;
        }
        if(t.size()==0) {
            cout <<"-1\n";
            return;
        }
        sort(t.rbegin(),t.rend());

        int p=0;
        while(s<d){
            s+=t[p];
            p++;
            ans++;
            if(s<d && p>=t.size()){
                cout << "-1\n";
                return;
            }
        }
        // while(j<m && x[j]<=r[i]) j++;
        // if(j>=m && i<n-1) {
        //     cout << "*-1\n";
        //     return;
        // }
    }
    cout << ans<< "\n";    
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
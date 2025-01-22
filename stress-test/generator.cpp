#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int inf = (int64_t)1e+18;
constexpr int mod = 1000000007;

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int64_t rnd(int l = 0, int r = 1E9)
{
    if (l > r)
        swap(l, r);
    return std::uniform_int_distribution<int>(l, r)(rng);
    // return std::uniform_real_distribution<long double>(l, r)(rng);
}


std::string generateRandomString(int n)
{
    std::string alphabet = "ab";
    std::string randomString;
    randomString.reserve(n);

    std::srand(std::time(0)); // Seed the random number generator

    for (int i = 0; i < n; ++i)
    {
        randomString += alphabet[std::rand() % alphabet.size()];
    }
    return randomString;
}

void runCase(int &testCase)
{
    // cout << "#Case " << testCase << ": \n";
    // char a = rnd(0,25)+'A';
    int t = rnd(1, 1);
    cout << t << "\n";
    int n = rnd(1,10);
    cout << n << "\n";
    int m = rnd(1,n);
    cout << m << "\n";
    int k = rnd(1,n);
    cout << k << "\n";

    // int x = rnd(1, 100000000000000000);
    // cout << x << " ";
    // int y = rnd(1, 100000000000000000);
    // cout << y << "\n";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<rnd(10,100) << " ";
    // }
    vector<int> ans;
    for(int i=0;i<m;i++) ans.push_back(rnd(1,10));
    sort(ans.begin(),ans.end());
    for(int i=0;i<m;i++) cout<<ans[i]<<' ';


        // cout<<rnd(-10,-1)<<' '<<rnd(0,10)<<'\n';
    cout<<'\n';
    //  for(int i=0;i<n;i++)
    // {
    //     cout<<rnd(50,200)<< " ";
    // }
    
    vector<int> an;
    for(int i=0;i<k;i++) an.push_back(rnd(1,10));
    sort(an.begin(),an.end());
    for(int i=0;i<k;i++) cout<<an[i]<<' ';

    cout<<'\n';
    // int a = rnd(1, 10);
    // cout << a << "\n";
    // for(int i=0;i<a;i++)
    // {
    //     cout<<rnd(1,n)<<' '<<rnd(1,50)<<'\n';
    // }
    // int b = rnd(1, 10);
    // cout << b << "\n";
    
    // int k = rnd(1, 10);
    // cout << k << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ((char)(rnd(0, 1) + 'A'));
    // vector<int> ans;
    // while(1){
    // for(int i=0;i<n;i++)
    // {
    //     ans.push_back(rnd(1,10));
    // }
    // if(accumulate(ans.begin(),ans.end(),0LL)<=a) break;}
    // for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    // cout << "\n";
}

int32_t main()
{

    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int tests = 1;
    // cin >> tests;
    for (int i = 1; i <= tests; i++)
        runCase(i);

    return 0;
}
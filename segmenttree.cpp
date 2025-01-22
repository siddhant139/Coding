#include <bits/stdc++.h>
using namespace std;

int n;
int a[100100];
int t[400400]; 

void build(int index, int l, int r) {
    if (l == r) {
        t[index] = a[l];
        return;
    } 
    int mid = (l + r) / 2;
    build(index*2, l, mid);
    build(index*2+1, mid+1, r);
    t[index] = t[index*2] + t[index*2+1];
}

void update(int index, int l, int r, int pos, int val) {
    if(pos<l || pos >r) return;
    if (l == r) {
        t[index] = val;
        a[l]=val;
        return;
    } 
    int mid=(l+r)/2;
    update(index*2 , l ,mid , pos, val);
    update(index*2 + 1 ,mid , r , pos, val);
    t[index]=t[2*index] + t[2*index + 1];
}

int query(int index, int l, int r, int lq, int rq) { //here query finds sum from l to r
    if (l > rq || lq >r) return 0;
    if (lq <= l && r <= rq) {
        return t[index];
    }
    int mid = (l+r) / 2;
    return query(index*2,l,mid,lq,rq) + query(index*2+1 , mid+1 ,r, lq,rq );
}


void runCase(int &testcase)
{
    cin >> n ;
    for (int i=0;i<n;i++) {
        cin >> a[i]; 
    }
    build(1,0,n-1);
    int q; //queries
    cin >> q;
    for (int i=0;i<n;i++) {
        int ch; //choice 
        cin >> ch; 
        if(ch==1) {
            int x,v;
            cin >> x >> v;
            update (1,0,n-1,x,v);
        }
        else {
            int l,r;
            cin >> l >> r;
            query(1,0,n-1,l,r);
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
#include <bits/stdc++.h>
using namespace std;

// void merge(int a[],int l,int m,int r){
//     int n1=m-l+1;
//     int n2=r-m;
//     vector<int> L(n1) ,R(n2);
//     for(int j=0;j<n1;j++) L[j]=a[l+j];
//     for(int j=0;j<n2;j++) R[j]=a[m+1+j];
    
//     int i=0 ,j=0 , k=l;
//     while(i<n1 && j<n2){
//         if(R[j]<L[i]) a[k++]=R[j++];
//         else a[k++]=L[i++];
//     }
//     while (i<n1) a[k++]=L[i++];
//     while (j<n2) a[k++]=R[j++];
// }

// void mergesort(int a[],int l,int r){
//     if(l<r){
//         int m=(r+l)/2;
//         mergesort(a,l,m);
//         mergesort(a,m+1,r);
//         merge(a,l,m,r);
//     }
// }

// int main(){
//     int n;
//     cin >> n ;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin >> a[i];
//     }
//     mergesort(a,0,n);
//     for(int i=0;i<n;i++){
//         cout << a[i] << " ";
//     }
// }








void quicksort(int a[],int l,int h){
    if(l<h) {
        int pv=a[h];
        int i=l,j=l,k=h-1;
        while (j<=k){
            if(a[j] < pv) {
                swap(a[i],a[j]);
                i++;
                j++;
            }
            else if(a[j] == pv) {
                j++;
            }
            else if (a[j] > pv) {
                swap(a[j],a[k]);
                k--;
            }
        }
        // for(auto z=0;z<=h;z++ ){
        //     cout << a[z] << " " ;
        // }
        // cout << "\n";
        swap(a[h],a[i]);
        quicksort(a,l,i-1);
        quicksort(a,j,h);
    }
}


int32_t main()
{
    int n;
    cin >> n ;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i]; 
    }
    
    quicksort(a,0,n-1) ;  
    for(auto e : a){
        cout << e << " " ;
    }
    cout << "\n";
    
}
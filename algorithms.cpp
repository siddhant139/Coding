#include<bits/stdc++.h>
using namespace std;

void Algorithms (){

    //UPPER BOUND & LOWER BOUND 
    vector<int> v;
    int x;

    // lower bound return the address of element less than x
    auto l=lower_bound(v.begin(),v.end(),x);
    int indexoflb=l-v.begin();

    // upper bound return the address of element either "equal to x" if not "less than x"
    auto u=upper_bound(v.begin(),v.end(),5);
    int indexofub=u-v.begin();

    int min=*min_element(v.begin(),v.end());
    int max=*max_element(v.begin(),v.end());
    int sum=accumulate(v.begin(),v.end(),0);
    
    auto it=find(v.begin(),v.end(),x);
    if(it !=v.end()) cout << *it << "\n";
    else cout << "Element Not Found \n";


}
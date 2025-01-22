#include<bits/stdc++.h>
// #include <stdio.h>
// #include<iostream>
using namespace std;

void vectorofpairofint(){
    vector<pair<int,int>> vp;
    for (auto &e : vp) cin >> e.first >> e.second ;

    sort(vp.begin(), vp.end()); //sorting in ascending order of first element 

    sort(vp.begin(), vp.end(),[&](pair<int, int> &a, pair<int, int> &b){
        if (a.second == b.second)
            return a.first < b.first; // Sort by first element if second elements are equal
        return a.second < b.second;   // Sort by second element
    });


}


// Method 2 of custom sort
bool customSort(const pair<int, int> &a, const pair<int, int> &b) { // this function need to above and out of the function in which we apply sort fnction 
    if (a.second == b.second)  return a.first < b.first; // Sort by first element if second elements are equal
    return a.second < b.second;   // Sort by second element
}
void Vector() {
int n;
vector<int> v(n,0); // declaring vector of n element and initialize them with 0
for(int i=0;i<n;i++){
    cin >> v[i];
}
for(auto e:v){ // copy of value is passed 
    cout << e << " " ;
}
for(int &e:v){  // actual value is passed 
    cout << e << " " ;
}


sort(v.begin(),v.end()); //ascending order
sort(v.rbegin(),v.rend()); //decending order

//Custom sorting (sort vector of pair of integer) (ascending order)
vector<pair<int,int>> vp;
sort(vp.begin(), vp.end(),[&](pair<int, int> &a, pair<int, int> &b){
        if (a.second == b.second)
            return a.first < b.first; // Sort by first element if second elements are equal
        return a.second < b.second;   // Sort by second element
    });

// Method 2 of custom sort
sort(v.begin(), v.end(), customSort);

// storing the index of the sorted vector of m in v(v is initialised by its index no.)
vector<int> m(n);
sort(v.begin(), v.end(), [&](int i, int j) {
        // if(m[i]==m[j]){
        //     return min(a[i][0],a[i][1]) < min(a[j][0],a[j][1]);
        // }
        return m[i] < m[j];
    });
    

int target;
auto it = find(v.begin(), v.end(), target); // to fina an element in a vector


v.push_back (20);
//{10, 20}
v.pop_back(); // {10}

//Erase function
//{10, 11, 20, 12, 23, 35}
 v.erase (v.begin()+1);

// (10, 20, 12, 23, 35}
v.erase(v.begin() + 2, v.begin() + 4);  // (10, 20, 35} [start, end)

// Insert function
vector<int>v (2, 100); // {100,100}
v.insert(v.begin(), 300);// {300, 100, 100}
v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

vector<int> copy(2,50); //{50,50}
v.insert (v.begin(), copy.begin(), copy.end()); //{50,50,300,10,10,100,100}

}

void Map() {

    map<int, string> m;
    m[1]="abc";
    m[5]="cdc";
    m[3]="acd";
    m[6]="a";
    m[5]="cde";
    int length=m.size();

    for(auto &e: m){
        cout << e.first << e.second << endl;
    }
    m.erase(3);
    auto it =m.find(6);
    m.erase(it);
    if(it==m.end()) cout << "no value\n";
    else cout << (*it).first << " "<< (*it).second ;

}

void Set() {

    set<string> s;
    s.insert("abc");
    s.insert("def");
    s.insert("ghi");
    s.insert("jkl");
    s.insert("mno");
    int length=s.size();

    for(auto &e: s){
        cout << e << "\n";
    }

    auto it =s.find("abc");

    s.erase(it);
    if(it==s.end()) cout << "no value\n";
    else {
        cout << (*it) ;
        s.erase(it);
    }

    set<int> s1;
    s1.insert(50); // Inserts an element
    s1.insert(10); // Insert a duplicate (ignored as set doesn't allow duplicates)
    s1.emplace(60); // Constructs and inserts an element

    s1.erase(10); // Removes an element by value
    s1.erase(s1.begin()); // Removes the first element
    s1.erase(s1.begin(), s1.find(70)); // Removes a range of elements
    s1.clear(); // Removes all elements from the set
    s1.empty(); //returns 1 if set is empty else 0

    // iterators
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " "; // Traversing using iterators
    }

    if (s1.find(50) != s1.end()) { // Searches for an element
        cout << "50 is found in s1" << endl;
    }
    // Count function
    cout << "Count of 50 in s1: " << s1.count(50) << endl; // Returns 0 or 1, as duplicates are not allowed

    auto lb = s1.lower_bound(60); // Returns iterator to first element >= 60
    if (lb != s1.end()) {
        cout << "Lower bound of 60: " << *lb << endl;
    }

    auto ub = s1.upper_bound(60); // Returns iterator to first element > 60
    if (ub != s1.end()) {
        cout << "Upper bound of 60: " << *ub << endl;
    }
}

void MultiSet() {
    // Everything is same as sets
    // only it store duplicate elements also 
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1) ; //erase all 1's

    int cnt=ms.count(1);

    // erase only a single 1 
    ms.erase(ms.find(1));

    //erase 2 element starting from from first 1  

    //Wrong way
    // ms.erase(ms.find(1), ms.find(1)+2); 

    // Correct Way
    // {
        // Advancing the iterator to the 2nd position
        auto start = ms.begin();
        auto end = ms.begin();
        advance(end, 2); // Move `end` forward by 2 positions

        // Erase the range [start, end)
        ms.erase(start, end);
    // }
}

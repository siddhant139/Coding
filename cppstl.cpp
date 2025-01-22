#include<bits/stdc++.h>
// #include <stdio.h>
// #include<iostream>
using namespace std;


// Pairs 
void explainpair() {
pair<int, int> p={1,3};

cout<< p.first << " " << p.second << endl;

pair<int, pair <int, int>> pa={1,{2,3}};

cout<< pa.first <<" "<< pa.second.second << " " << pa.second.first << endl ;

pair<int, int> arr[] = {{1,2},{3,4},{5,6},{7,8}};
cout<< arr[0].first <<" "<< arr[0].second << endl;


}

void explainVector() {



vector<int> v;

v.push_back (1);
v.pop_back();
v.emplace_back(2);

sort(v.begin(),v.end()); //ascending order
sort(v.rbegin(),v.rend()); //decending order
int n;
vector <int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(auto e:a){ // copy of value is passed 
        cout << e << " " ;
    }
    for(int &e:a){  // actual value is passed 
        cout << e << " " ;
    }


vector< pair<int, int> > vec;

v.push_back(1, 2);
v.emplace_back (1, 2);

vector <int> v(5, 100) ;

vector<int> v(5);

vector<int> v1(5, 20); 
vector<int> v2(v1);



vector<int>::iterator it = v.begin();

it++;
cout « *(it) « " ":



vector<int>:: iterator it = v.begin();
it++;
cout << *(it) <<" ":

it = it + 2;
cout <<*(it) << " ";

vector<int>:: iterator it = v.end();
vector<int>:: iterator it = v.rend();
vector<int>::iterator it = v.rbegin():

cout <<  v[0] << " " << v.at(0);
cout << v.back() << " ";


for (vector<in>>::iterator it = v.begin(); it != v.end(); it++) {
    cout<< *(it) <<" "
}

for (auto it = v.begin(); it != v.end(); it++) {
cout << *(it) <<"";
}


//{10, 11, 20, 12, 23, 35}
 v.erase (v.begin()+1);

// (10, 20, 12, 23, 35}
v.erase(v.begin() + 2, v.begin() + 4);  // (10, 20, 35} [start, end)



// Insert function
vector<int>v (2, 100): // {100,100}
v.insert(v.begin(), 300): // {300, 100, 100}
v.insert(v.begin(), + 1, 2, 10); // {300, 10, 10, 100, 100}

vector<int> copy(2,50); //{50,50}
v.insert (v.begin(), copy.begin(), copy.end()); //{50,50,300,10,10,100,100}

//<10, 20}
v.pop_back(); // (10}

//v1 → (10, 20}
// v2 → {30, 40}
v1.swap(v2): // v1 → {30, 40} • v2 →> (10, 20}

v.clear(): // erases the entire vector
cout < v.empty();


}



void explainset() {
    set<string> s;
    int n;
    cin >> n; 
    for(int i=0;i<n;i++){
        string str;
        cin >>str;
        s.insert(str);
    }
    for(auto value :s){
        cout << value << endl;
    }

    //unorderes set
    unordered_set<string> s;
    int n;
    cin >> n; 
    for(int i=0;i<n;i++){
        string str;
        cin >>str;
        s.insert(str);
    }
    int q;
    cin >> q;
    while (q--){
        string st;
        cin >> st;
        if(s.find(st)==s.end()) cout << "no\n";
        else cout << "yes\n";

    }

}


void ExplainMap {
    // Creating and initializing maps
    std::map<int, std::string> m1; // Default constructor, creates an empty map
    std::map<int, std::string> m2 = {{1, "One"}, {2, "Two"}, {3, "Three"}}; // Initializer list constructor
    std::map<int, std::string> m3(m2.begin(), m2.end()); // Range constructor

    // Modifiers
    m1.insert({4, "Four"}); // Inserts a single key-value pair
    m1[5] = "Five"; // Adds a new key-value pair or updates the value if the key exists
    m1.emplace(6, "Six"); // Constructs and inserts a key-value pair
    m1.insert({{7, "Seven"}, {8, "Eight"}}); // Inserts multiple key-value pairs

    m1.erase(5); // Removes an element by key
    m1.erase(m1.begin()); // Removes the first element
    m1.erase(m1.begin(), m1.find(7)); // Removes a range of elements
    m2.clear(); // Removes all elements from the map

    // Capacity
    std::cout << "Size of m1: " << m1.size() << std::endl; // Returns the number of elements
    std::cout << "Is m1 empty? " << (m1.empty() ? "Yes" : "No") << std::endl; // Checks if the map is empty

    // Iterators
    std::cout << "Elements of m1: ";
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        std::cout << "{" << it->first << ": " << it->second << "} "; // Traversing using iterators
    }
    std::cout << std::endl;

    // Lookup
    if (m1.find(4) != m1.end()) { // Searches for a key
        std::cout << "Key 4 found with value: " << m1[4] << std::endl;
    }

    std::cout << "Count of key 4: " << m1.count(4) << std::endl; // Returns 1 if the key exists, otherwise 0

    auto lb = m1.lower_bound(6); // Returns iterator to the first key >= 6
    if (lb != m1.end()) {
        std::cout << "Lower bound of 6: {" << lb->first << ": " << lb->second << "}" << std::endl;
    }

    auto ub = m1.upper_bound(6); // Returns iterator to the first key > 6
    if (ub != m1.end()) {
        std::cout << "Upper bound of 6: {" << ub->first << ": " << ub->second << "}" << std::endl;
    }

    auto range = m1.equal_range(6); // Returns a pair of iterators (lower and upper bounds)
    std::cout << "Equal range of 6: [";
    if (range.first != m1.end()) {
        std::cout << "{" << range.first->first << ": " << range.first->second << "}";
    }
    if (range.second != m1.end()) {
        std::cout << ", {" << range.second->first << ": " << range.second->second << "}";
    }
    std::cout << "]" << std::endl;

    // Observers
    auto comp = m1.key_comp(); // Comparison object for keys
    std::cout << "Comparison (4 < 6): " << (comp(4, 6) ? "true" : "false") << std::endl;

    // Non-member functions
    std::map<int, std::string> m4 = {{9, "Nine"}, {10, "Ten"}};
    m1.swap(m4); // Swaps the contents of m1 and m4
    std::cout << "After swapping, elements of m1: ";
    for (const auto& [key, value] : m1) {
        std::cout << "{" << key << ": " << value << "} ";
    }
    std::cout << std::endl;

    // Relational operators
    std::cout << "Are m1 and m3 equal? " << (m1 == m3 ? "Yes" : "No") << std::endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){

    // Strings
    string s = "example";

    // Returns the sustring begining at k(0-indexing) and length x
    string temp=s.substr(2,2);

    // Returns the first occurance of stustring t;
    // Returns long garbage if not found
    int pos=s.find("hi");

    //Set
    set<int> se={2,5,6,8,3,1,5,8,2};

    //Iterate through set
    for(auto x:se){
        // cout<<x<<endl;
    }

    // Returns either 0 or 1 when called as elements are distinct
    bool is_present = se.count(5);

    //Multiset
    // stores multiple instances of elements
    multiset<int> ms={2,5,6,8,3,1,5,8,2};

    //iterate through
    for(auto x:ms){
        // cout<<x<<endl;
    }

    // Returns count of instances
    int freq = ms.count(2);

    // Erases all instances
    ms.erase(2);

    // If you want to remove only a single instance
    // can be done in following way
    ms.erase(ms.find(5));


    // Bitset
    // Default values of elements is 0
    bitset<10> s;

    // Another initialisation
    bitset<10> bs(string("0110110101")) //Creates Bitset from right to left

    // Returns the number of set bits
    freq = bs.count();

    // AND OR XOR operators can be used on two bitsets
    // bs&s bs|s bs^s


    // Priority Queue
    // Declares Max Priority Queue
    priority_queue<int> q;

    // Operations q.push() q.top() q.pop()

    // Declare a min priority queue
    priority_queue<int,vector<int>,greater<int>> min_q; 

}
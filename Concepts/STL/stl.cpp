#include<bits/stdc++.h>
using namespace std;

void pairDs(){
    // Pair
    pair<int,int> p = {1,2};
    cout << p.first << " " << p.second << endl;
    pair<int,pair<int,int>> p1 = {1,{2,3}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
}

void vectorDs(){
    // Vector
    // only push back
    vector<int> v = {1,2,3,4,5};
    v.push_back(6);
    v.emplace_back(6); //without creating object we can directly push into vector
    cout << v.size() << endl;

    vector<int>v2(5); // By default all the elements are declared to 0
    vector<int>v3(10,5); // 10 elements with value 5
    sort(v.begin(),v.end()); // sort the vector
    reverse(v.begin(),v.end()); // reverse the vector
    cout << v[0] << " " << v.at(0) << endl; // access the first element

    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    for(auto it : v){
        cout << it << " "; // range based for loop
    }

    v.erase(v.begin()); // erase the first element
    v.erase(v.begin(), v.begin() + 2); // erase the first two elements
    v.insert(v.begin(), 10); // insert 10 at the beginning
    v.pop_back(); // erase the last element 
    v.clear(); // clear the vector

    int count = __builtin_popcount(5); // count the number of set bits in binary representation of the given number
    int maxi = *max_element(v.begin(), v.end()); // find the maximum element in the vector
    int mini = *min_element(v.begin(), v.end()); // find the minimum element in the vector
    int sum = accumulate(v.begin(), v.end(), 0); // find the sum of the elements in the vector

}

void ListDs(){
    // List
    // Doubly linked list
    list<int> l = {1,2,3,4,5};
    l.push_back(6);
    l.push_front(0);
    l.pop_back();
    l.pop_front();
    cout << l.size() << endl;
}

void DequeDs(){
    // Deque
    // Double ended queue
    // can insert at front & back pop at front & back
    deque<int> d = {1,2,3,4,5};
    d.push_back(6);
    d.push_front(0);
    d.pop_back();
    d.pop_front();
    cout << d.size() << endl;
}

void SetDs(){
    // Set
    set<int> s = {1,2,3,4,5};
    s.insert(6);
    s.erase(1);
    cout << s.size() << endl;
}

void MapDs(){
    // Map
    map<int,int> m = {{1,2},{2,3},{3,4}};
    m[4] = 5; // insert
    m.erase(1); // erase
    cout << m.size() << endl;
}

void UnorderedSetDs(){
    // Unordered Set
    unordered_set<int> s = {1,2,3,4,5};
    s.insert(6);
    s.erase(1);
    cout << s.size() << endl;
}

void UnorderedMapDs(){
    // Unordered Map
    // Can store duplicate keys
    unordered_map<int,int> m = {{1,2},{2,3},{3,4}};
    m[4] = 5; // insert
    m.erase(1); // erase
    cout <
    < m.size() << endl;
}
void StackDs(){
    // Stack
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // top element
    s.pop(); // pop the top element
}

void QueueDs(){
    // Queue
    // insert at back pop at front
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl; // front element
    q.pop(); // pop the front element
}

void PriorityQueueDs(){
    // Priority Queue
    // implemented using heap data structure
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top() << endl; // top element
    pq.pop(); // pop the top element
}

void MultiSetDs(){
    // MultiSet
    // allows duplicate elements
    // implemented using red-black tree
    multiset<int> s = {1,2,3,4,5};
    s.insert(6);
    s.erase(1);
    cout << s.size() << endl;
}



int main(){
    ListDs();
    
    
    return 0;
}
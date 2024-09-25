#include<bits/stdc++.h>
using namespace std;

//vectors
void vectors(){

    vector<int> v;                  //{}
    v.push_back(1);                 //{1}
    v.emplace_back(2);              //{1,2}  (faster than pb)
    cout<<v.size()<<endl;           //2
    v.pop_back();                   //{1}
    //v1={1,2},v2={3,4} 
    v1.swap(v2);                   //v1={3,4},v2={1,2}
    v.empty()                      //bollean method returns tue if empty
    v.clear()                      //{}

    vector<pair<int,int>> vec;
    vec.push_back({1,2});          //curley brackets needed
    vec.emplace_back(1,2);         //detects automatically no brackets needed

    vector<int> v(5,100);         //{100,100,100,100,100}

    vector<int> v(5);             //initialize with 0 or garbage depends on compiler
    cout<<v[0]<<endl;             // we can always access vectors as we access arrays

    vector<int> v1(5,20);         //{20,20,20,20,20}
    vector<int> v2(v1);           //copy of v1
    v1.push_back(1);              //{20,20,20,20,20,1}

    /*------------"iterator"-------------*/
                                             
    vector<int>::iterator it = v1.begin();    //v.begin() is address of first element of vector
    it++;
    cout<< *(it) <<" ";
    it+=2;
    cout<<*(it)<<" ";

    vector<int>::iterator it = v1.end();     
    /*doesnt give address of last but gives address of oneafter last so we need to do it--
    there are two more rend(),rbegin() which are reversed but we never use it*/
    
    //----------print vector-----------
    //1
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
        cout<<*(it)<<endl;
    }
    //2
    for(auto it=v1.begin();it!=v1.end();it++){
        cout<<*(it)++<<endl;
    }
    //3(preferred)
    for(auto it : v1){
        cout<<it<<endl;
    }

    //--------------deletion in vector-------------

    //v = 10,20,12,23
    v.erase(v.begin()+1);             //10,12,23
    //v=10,20,12,23,25
    v.erase(v.begin()+1,v.begin()+3); //10,23,25

    //--------------insert-----------

    vector<int> v(2,100);            //100,100
    v.insert(v.begin(),300);         //300,100,100
    v.insert(v.begin()+1,2,10);      //300,10,10,100,100

    vector<int> copy(2,50);         //50,50
    v.insert(v.begin(),copy.begin(),copy.end()); //50,50,300,10,10,100,100


}

//sets
void sets(){
    //always SORTED AND UNIQUE
    set<int> s;
    s.insert(1);//1
    s.insert(2);//1,2
    s.insert(5);//1,2,5
    s.insert(2);//1,2,5
    s.insert(3);//1,2,3,5

    auto it = s.find(3);  //this method will give iterator address of 3 to it
    auto it = s.find(10); //because 10 is not there it will give address of st.end() means 1 address after last element
    s.erase(5);           //deletes 5 and maintains the sorted order
    int cnt = s.count    //gives 1 if exist, else 0
    
    //1,2,3,4,5
    auto it1=s.find(2);
    auto it2=s.find(4);
    s.erase(it1,it2); //1,4,5

    auto it = s.lower_bound(2);
    auto it = s.upper_bound(3);
}

//unordered sets O(1)
void unorderedsets(){
    unordered_set<int> st;
    //always UNIQUE but not sorted
    //better complexity always
}

//multisets
void multisets(){
    //always SORTED but not unique
    multiset<int> ms;
    ms.insert(1);//1
    ms.insert(1);//1,1
    ms.insert(1);//1,1,1

    ms.erase(1);//all 1s erased
    ms.erase(ms.find(1));//only one 1 erased
    ms.erased(ms.find(1),ms.find(1)+2);//in this range 1s are deleted and rest remains
}

//lists
void lists(){
    list<int> ls;
    //everything is same as vector but in list front operations are also done in very less time
    //in compare to vector
    ls.push_back(2);        //2
    ls.emplace_back(3);     //2,3
    ls.pop_front(5);        //5,2,3
    ls.emplace_front(6);    //6,5,2,3
}

//deques
void deques(){
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);
    dq.pop_back();
    dq.pop_front();
    dq.front();
    dq.back();
    //exactly same to list and vectors
}

//pairs
void pairs(){

    pair<int,int> p = {1,2};
    cout << p.first << " " << p.second<<endl;

    pair<int,pair<int,int>> p1 = {1,{2,3}};
    cout << p1.first <<" "<< p1.second.first << " "<< p1.second.second<<endl;

    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    cout<<arr[1].second<<endl;

}

//stacks(LIFO)
void stacks(){
    //understandable
    stack<int> st;
    st.push(1);
    st.push(2);
    st.emplace(3);
    st.size();
    st.top();
    st.pop();
    st.empty();
    st.swap();
}

//queues(FIFO)
void queues(){
    //understandable
    queue<int> q;
    q.push(1);
    q.emplace(2);
    q.front();
    q.back();
    q.empty();
    q.size();
    q.pop();
}

//priorityqueues
void priorityqueues(){
    priority_queue<int> pq;
    //max stays at top(MAX HEAP)
    pq.push(5);     //5
    pq.push(2);     //5,2
    pq.push(8);     //8,5,2
    pq.emplace(10); //10,8,5,2
    pq.top();       //10
    pq.pop();
    pq.top();      //8
    //min stays at the top(MIN HEAP)
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(5);     //5
    pq.push(2);     //2,5
    pq.push(8);     //2,5,8
    pq.emplace(10); //2.5.8.10
    pq.top();       //2

}

//maps
void maps(){
    //any two variables for (key,value)
    //key is always unique and always in sorted order
    map<int,int> mpp;
    map<int,pair<int,int>> mpp;
    map<int,long> mpp;
    
    map<int,pair<int,int>> mpp;
    mpp[{2,3}]=4;       //({2,3},4)


    map<int,int> mpp;
    mpp[1]=2            //(1,2)
    mpp.insert({2,4});  //(1,2),(2,4)
    mpp.emplace({3,1}); //(1,2),(2,4),(3,1)

    cout<<mpp[1]<<endl; //2
    cout<<mpp[5]<<endl; //0
    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    auto it = mpp.find(3);      //will find the key,if there is no value at this key will give mpp.end() means one address after last
    cout<<*(it).second<<endl;  //will give the value at key 3

    auto it=mpp.upper_bound();
    auto it=mpp.lower_bound();

}

//multimaps
void multimaps(){
    //same as map just key can be duplicated not always unique means(1,2) and (1,3) both exists
}

//unorderedmaps O(1)
void unorderedmaps(){
    //keys are not sorted but they are unique and less complexity
}

int main(){
    return 0;
}
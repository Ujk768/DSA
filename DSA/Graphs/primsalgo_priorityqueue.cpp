#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int N,m;
    cin>>N>>m;
    vector<pair<int,int>>adj[10];
    
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    int parent[10];
    int key[10];
    int mstSet[10];

    for(int i=0;i<N;i++){
        key[i]=INT_MAX,mstSet[i]=false;
    }
    //minimal priority queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    //instead of iterating on key[i] and finding the minimal we store key[i] and index in priority queue
    // store the key[i] and index in prioroty queue
    //initially only key[0]=0 rest all are infinty
    key[0]=0;
    parent[0]=0;
    //{index ,value}
    pq.push({0,0});
    
    for(int count=0;count<N-1;count++){
        int u=pq.top().second;
        //pop from que coz its taken
        pq.pop();
        mstSet[u]=true;

        for(auto it: adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && weight<key[v]){
                parent[v]=u;
                pq.push({key[v],v});
                key[v]=weight;
            }
        }
    }

}

//t.c:n+e+logn O(nlogn) s.c: adj list + 3 arrays
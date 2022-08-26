#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/**
 * @brief 
 * in the prev shortest path alo the fist from the src to 
 * dest was found using using a noral queue ds but in that
 * case the edge weihts were always unit hence a normal 
 * queue worked
 * 
 * we need to sue a priority queue of (dist,node)
 * priority queue should be a min priority  queue such that 
 * the node with min distance should be at the top
 * 
 * we need a disatcne array with size == no of nodes initillzed 
 * to infinity
 * 
 * for every node we check the dist we can reach from the 
 * src node to the given node and update the dist vector
 * 
 *  instead of priority queue we can use a set data structure
 *
 * when priority queue is empty then we can say we have checked with
 * all the nodes
 * 
 * t.c: O(n+e)logn
 * s.c: adjlist +dist arr+prioioty queue
 */

int main(){
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1]; //1 based indexing
    
    int a,b,wt;
    //storing weighted graph 
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a,wt));
    }
    cin>>source;
    //djakstras algo starts
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> pq;//in pair (dist,node)
    vector<int>distTo(n+1,INT_MAX);//1 based indec=xing initalized all to int max
    distTo[source]=0;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        vector<pair<int,int>::iterator it;
        for(auto it: g[prev]){
            int next=it.first;
            int nextDist=it.second;
            if(distTo[next]>dist+nextDist){
                distTo[next]=distTo[prev]+nextDist;
                pq.push(make_pair(distTo(next),next));
            }
        }
        
    }
    cout<< " dist from src: "<< source <<"are:"
}




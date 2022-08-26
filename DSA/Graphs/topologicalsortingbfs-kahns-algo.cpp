#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/**
 * @brief 
 * 
 * 1. make an array with indegree of all the nodes 
 * 2. traverse through the array and push the nodes 
 * having indegree 0 in the ds
 * 3. use bfs algo
 * 4. take out a node from the queue => part of the topo sort
 * check adj nodes of the removed node and reduce the indegree of them by 1
 * and check if any of them have indegree 0
 * when node has indegree 0 put in the queue ds
 *  
 * t.c O(n+e) s.c O(n+n)
 * 
 */

vector<int>topoSort(int N,vector<int>adj[]){
    queue<int>q;
    vector<int>indegree(N,0);
    //creating indegree array
    for(int i=0;i<N;i++){
        for(auto it: adj[i]){
            //each adj node is a node coming
            // to that node hence we increase the indegree
            indegree[it]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            //if indegree is 0 then we push node into queue
            if(indegree[it]==0) q.push(it);
        }
    }
    return topo;
}
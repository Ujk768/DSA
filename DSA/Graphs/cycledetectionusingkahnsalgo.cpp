#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

/**
 * @brief 
 * topological sort is only possible for dag only
 * so now we generate a topological sort and if we cant
 * generate then we can say that its acyclic
 * 
 */

bool isCyclic(int N, vector<int>adj[]){
    queue<int>q;
    vector<int> indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        //node thats deleted everytime its a part of the topological sort
        q.pop();
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    //topological sort generated henc no cycle
    if(cnt==N) return false;
    return true;
}
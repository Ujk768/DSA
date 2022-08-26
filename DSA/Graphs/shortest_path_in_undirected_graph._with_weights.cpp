#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

/**
 * @brief 
 * 1. take a distance array of size N and all is marked as infinity
 * 2. take a queue ds and put src node in it and mark dist 0 as 0
 * 3. queue is always going to store the nodes
 * 4. take the top element of the queue out of the node
 * node 0 add the dist 0
 * check the adj nodes of that and add
 * from src the adj nodes willl be at a dist of 1 so we replace
 * their values from the dist array
 *5. in the next node we check the nodes adj to that particular
 *node and add the node with minimal distance to the node by checking 
 the distance array  

bfs iterates nodes parallely that are in the same level
 t.c:O(n+e) s.c:O(n+n)
 * 
 */

void bfs(vector<int>adj[],int N, int src){
    int dist[N];
    for(int i=0;i<N;i++){
        dist[i]=INT_MAX;
    }
        queue<int>q;
        dist[src]=0;
        q.push(src);

        while(q.empty()==false){
            int node=q.front();
            q.pop();
            //get noed from que and take it out
            for(auto it: adj[node]){
                //traverse through all its adj nodes and add in q if its 
                //dis is less than the dist in dist arr
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
    for(int i=0;i<N;i++) cout<<dist[i]<<"";
}
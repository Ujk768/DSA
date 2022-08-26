#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#define INF INT_MAX
using namespace std;

/**
 * @brief 
 * 
 * Dag with weight
 * 
 * in weighted graph we have to make the adj list using pair
 * 
 * 1. find topo sort for the dag
 * 2. dfs 
 * declare a stack and do 
 * do dfs for each adj node and mark it as visited
 * when the dfs call is finished store it in the stack
 * 
 * at the end stack will contain the topo sort
 * 
 * 3. create another distance array of size=no of nodes which is initialized with infinity
 * 
 * take first element from the stack
 * first check that the dist of that node is not infinity which signifies you have reached there for the first time
 * 
* once all adj noeds are done we move to the next node in stack and check
the distance to its adj noeds but this time adding the prev node weight
 * 
 * at every adj node we check if the dist to that adj node
 *  is lower than the existing distance in the vector if so update with min 
 *
 * t.c O(n+e)*2
 * s.c:O(2N)
 *     
 */

void findTopoSort(int node,int vis[],stack<int>&st, vector<pair<int,int>>adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it.first]){
        findTopoSort(it.first,vis,st,adj);
        }
    }
    st.push(node);

}


void shortestPath(int src, int N, vector<pair<int,int>>adj[]){
    int vis[N]={0};
    stack<int>st;
    int dist[N];
    for(int i=0;i<N;i++){
        dist[i]=1e9;
    }
    dist[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        //node has been reached previously
        if(dist[node]!=INF){
            for(auto it: adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        if (dist[i]==1e9) cout<<"INF"; 
        else cout<< dist[i]<<"";
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});

    }
    shortestPath(0,n,adj);
}







 
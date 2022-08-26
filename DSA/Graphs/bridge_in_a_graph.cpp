#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/**
 * @brief 
 * bridge in a graph is those edges on whose removal the graph is broken into two or more number of components
 * 
 * 
 * runa  dfs and assign each node with a numbe which states when its been reahced.
 * after that iterate on the adj node of each node to check if there is a way to reach that node faster
 * 
 *  if low[it]>tin[node]
 * 
 *  if the adj nodes is already visited then it can be reached by other paths hence itsnot a bridge
 *  if you can find lower time to reach that node from the adj then its not a bridge
 * 
 * if the adj nodes lowest time is greater than the time at which the node was inserted then its a bridge
 * 
 * 
 */
void dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>low,int &timer,vector<int>adj[]){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,node,vis,tin,low,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                cout<<node<<""<<it<<endl; 
            }
        }else{
            low[node]=min(low[node],tin[it]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[10];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ///time it arrives
    vector<int>tin(n,-1);
    //low vector
    vector<int>low(n,-1);
    //visited array
    vector<int>vis(n,0);
    int timer=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,tin,low,timer,adj);
        }
    }
}
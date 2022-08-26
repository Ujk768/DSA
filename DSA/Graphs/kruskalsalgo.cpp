#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


/**
 * @brief 
 * store the graph in a linear data structutre wrt to its weight
 * 
 * greedily pick up the shortest edge
 * 
 * using the disjoint set ds we check if two nodes belong to the same component if so then 
 * 
 * t.c: O(mlogm *3)+O(n*O(4*alpha))
 * 
 * t.c:(O mlog m)
 * 
 * s.c: O(m*3)+O(m)+O(n)+O(n)=O(n)
 * 
 */

struct  node{
    int u;
    int v; 
    int wt;
    node(int first,int second, int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

bool comp(node a, node b){
    return a.wt<b.wt;
}

int findPar(int u, vector<int>&parent){
    if(u==parent[u]) return u;
    return findPar(parent[u],parent);
}

void unionn(int u, int v, vector<int>&parent, vector<int>&rank){
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(rank[u]<rank[v]) parent[u]=v;
    else if(rank[v]<rank[u]) parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++; 
    }
}


int main(){
    int N,m;
    cin>>N>>m;
    vector<node>edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }

    sort(edges.begin(),edges.end(),comp);

    vector<int>parent;
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    vector<int>Rank(N,0);

    int cost=0;
    vector<pair<int,int>>mst;
    for(auto it:edges){
        if(findPar(it.v,parent)!=findPar(it.u,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    cout<<cost<<endl;
    



}
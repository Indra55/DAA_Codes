#include<bits/stdc++.h>

#define int long long
using namespace std;

int find(int u,vector<int>& parent){
    if(parent[u]==u) return u;
    return parent[u]=find(parent[u],parent);
}

void unite(int u,int v,vector<int>& parent,vector<int>& rank){
    int pu=find(u,parent);
    int pv=find(v,parent);
    if(pu==pv) return;

    if(rank[pu]<rank[pv]){
        parent[pu]=pv;
    }else if(rank[pu]>rank[pv]){
        parent[pv]=pu;
    }else{
        parent[pv]=pu;
        rank[pu]++;
    }
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);

int v = 4; 
vector<vector<int>> edges = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
};

sort(edges.begin(),edges.end(),[](auto& a,auto&b){
    return a[2]<b[2];
});

vector<int> parent(v),rank(v,0);
for(int i=0;i<v;i++) parent[i]=i;
    vector<vector<int>> mst;
    int totalw=0;

    for(auto& edge : edges){
        int u=edge[0],v=edge[1],w=edge[2];
        if(find(u,parent)!=find(v,parent)){
            mst.push_back(edge);
            totalw+=w;
            unite(u,v,parent,rank);
        }
    }


cout<<"Edges in mst are \n";
for(auto& edge:mst){
    cout << edge[0] << " - " << edge[1] << " : " << edge[2] << "\n";
    }
    cout << "Total weight of MST = " << totalw << "\n";


return 0;
}
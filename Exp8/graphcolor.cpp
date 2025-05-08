#include<bits/stdc++.h>

#define int long long
using namespace std;

bool safe(int v,vector<vector<int>>& graph,vector<int>& color,int c){
    for(int i=0;i<graph.size();i++){
        if(graph[v][i] && color[i]==c) return false;
    }
    return true;
}

bool graphcoloring(vector<vector<int>>& graph, int m, vector<int>& color,int v){
    if(v==graph.size()){
        for(int i=0;i<graph.size();i++){
            cout<<color[i]<<endl;
    }
    return true;
    }
    for(int i=1;i<=m;i++){
        if(safe(v,graph,color,i)){
        color[v]=i;
        if(graphcoloring(graph,m,color,v+1)) return true;
        color[v]=0;
        }
    }
    return false;
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
vector<vector<int>> graph={
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

vector<int> color(graph.size(),0);
int m=3,v=0;
if(!graphcoloring(graph,m,color,v)) cout<<"Solution does not exist.\n";
cout.flush();
return 0;
}

int kn(vector<int>& wt,vector<int>& val,int W){
    vector<int> dp(W+1,0);

    for(int i=0;i<wt.size();i++){
        for(int j=W;j>=wt[i];j--){
            dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
        }
    }
    return dp[W];

}
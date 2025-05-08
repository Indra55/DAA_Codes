#include<bits/stdc++.h>

#define INF 1000000000
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(NULL);
int v=4;
vector<vector<int>> dist = {
    {0,   5,  INF, 10},
    {INF, 0,   3,  INF},
    {INF, INF, 0,   1},
    {INF, INF, INF, 0}
};

for(int k=0;k<v;k++){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][k]<INF  && dist[k][j]<INF) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}

cout<<"Shortest path matrix is \n";
for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        if(dist[i][j]==INF) cout<<"INF"<<"\t";
        else cout<<dist[i][j]<<"\t";
    }
    cout << "\n";
}
return 0;
}
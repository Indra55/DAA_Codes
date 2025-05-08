#include<bits/stdc++.h>

#define int long long
using namespace std;

int coinchange(vector<int>& coins,int amt){
    vector<int> dp(amt+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=amt;i++){
        for(int c:coins){
            if(i-c>=0 && dp[i-c]!=INT_MAX) 
            dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    return dp[amt]==INT_MAX? -1:dp[amt];
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
vector<int> coins={1,5,7};
int ans=coinchange(coins,10);
cout<<ans;
return 0;
}
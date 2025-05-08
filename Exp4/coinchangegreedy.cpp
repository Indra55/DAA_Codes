#include<bits/stdc++.h>

#define int long long
using namespace std;

void coinchange(vector<int>& a,int n){
    sort(a.rbegin(),a.rend());
    vector<int> res;
    for(int i=0;i<a.size();i++){
        while(n>=a[i]){
            n-=a[i];
            res.push_back(a[i]);
        }
    }

    if(n==0){
        cout<<"Number of coins used are "<<res.size()<<" and the Coins used are: ";
        for(int i=0;i<res.size();i++) cout<<res[i]<<" "; 
    }else{
        cout<<"nah bro not possible";
    }
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);

vector<int> coins = {1, 5, 10, 25};  
int amount = 63;   

coinchange(coins, amount);
return 0;
}
#include<bits/stdc++.h>

#define int long long
using namespace std;

int power(int a,int n){
    if(n==0) return 1;

    int half=power(a,n/2);

    if(n%2==0) return half*half;
    else return a*half*half;
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
int a=124;
int n=22;

cout<<power(a,n);
return 0;
}
#include<bits/stdc++.h>

#define int long long
using namespace std;

pair<int,int> findmaxmin(vector<int>& a,int l,int h){
    if(l==h) return {a[l],a[h]}; //base case ek element
    if(h==l+1){ // base case 2 element
    if(a[l]<a[h]){
        return {a[l],a[h]};
    }else{
        return {a[h],a[l]};
    }
}

    int m=(l+h)/2;
    pair<int,int> left=findmaxmin(a,l,m);
    pair<int,int> right=findmaxmin(a,m+1,h);

    int finmin=min(left.first,right.first);
    int finmax=max(left.second,right.second);

    return {finmin,finmax}; 
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
vector<int> arr = {3, 5, 1, 8, 2, 9, 0, 4};

pair<int, int> result = findmaxmin(arr, 0, arr.size() - 1);

cout << "Minimum: " << result.first << "\n";
cout << "Maximum: " << result.second << "\n";

return 0;
}
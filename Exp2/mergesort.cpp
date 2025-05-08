#include<bits/stdc++.h>

#define int long long
using namespace std;

void merge(vector<int> &a,int l, int r,int m){
    vector<int> temp;
    int i=l;
    int j=m+1;

    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            temp.push_back(a[i++]);
        }else{
            temp.push_back(a[j++]);
        }
    }
    while(i<=m){
        temp.push_back(a[i++]);
    }
    while(j<=r){
        temp.push_back(a[j++]);
    }

    for(int k=0;k<temp.size();k++){
        a[k+l]=temp[k];
    }
}

void mergesort(vector<int> &a,int l,int r){
    if(l>=r) return;

    int m=l+(r-l)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,r,m);
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Original array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergesort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
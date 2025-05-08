#include<bits/stdc++.h>

#define int long long
using namespace std;

int partition(int a[],int l,int h){
    int p=a[h];
    int i=l-1;

    for(int j=l;j<h;j++){
        if(a[j]<=p){
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[h]);
    return I+1;
}

void quicksort(int a[],int l,int h){
    if(l<=h){
        int p=partitaion(a,lhr);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
return 0;
}
#include<bits/stdc++.h>

#define int long long
using namespace std;
#define d 256

void rabinKarp(string text, string pattern, int q){
int n=text.length();
int m=pattern.length();
int h=1;
int t=0;
int p=0;
for (int i = 0; i < m - 1; i++) h = (h * d) % q;

for(int i=0;i<m;i++){
t=(t*d+text[i])%q;
p=(p*d+pattern[i])%q;
}

for(int i=0;i<=n-m;i++){
    if(p==t){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]) break;
        }
        if(j==m) cout<<"Patter found at index "<<i<<endl;

        
    }
    else if(i<n-m){
        t=(d*(t-text[i]*h)+text[i+m])%q;
        if(t<0) t=t+q;
    }
}
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
string text = "abedabcabcabc";
string pattern = "abc";
int q = 101; 

rabinKarp(text, pattern, q);
return 0;
}
#include<bits/stdc++.h>

using namespace std;
int lcs(string x, string y){
    int n=x.size(),m=y.size(); 
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]) dp[i][j]= 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
string str1, str2;
cout << "Enter first string: ";
cout.flush();
cin >> str1;
cout << "Enter second string: ";
cout.flush();
cin >> str2;

int result = lcs(str1, str2);
cout << "Length of LCS: " << result << "\n";
return 0;
 }
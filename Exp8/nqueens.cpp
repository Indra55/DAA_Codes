// #include <iostream>
// using namespace std;

// int board[10], n;

// bool isSafe(int row, int col) {
//     for (int i = 0; i < row; i++) {
//         if (board[i] == col || abs(board[i] - col) == abs(i - row))
//             return false;
//     }
//     return true;
// }

// bool solve(int row) {
//     if (row == n) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i] == j) cout << "Q ";
//                 else cout << ". ";
//             }
//             cout << "\n";
//         }
//         return true; // found one solution
//     }

//     for (int col = 0; col < n; col++) {
//         if (isSafe(row, col)) {
//             board[row] = col;
//             if (solve(row + 1)) return true;
//         }
//     }

//     return false;
// }

// int main() {
//     cout << "Enter number of queens: ";
//     cin >> n;
//     if (!solve(0)) cout << "No solution exists.\n";
//     return 0;
// }


#include<bits/stdc++.h>

#define int long long
using namespace std;

int board[10],n;

bool safe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row)) return false;
    }
    return true;
}

bool solve(int row){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i]==j) cout<<"Q ";
                else cout<<"X ";
            }
            cout<<endl;
        }
        return true;
    }

    for(int col=0;col<n;col++){
        if(safe(row,col)){
            board[row]=col;
            if(solve(row+1)) return true;
        }
    }
    return false;
}

int32_t main(){
ios::sync_with_stdio(false), cin.tie(NULL);
cout << "Enter number of queens: \n";
cin >> n;
if (!solve(0)) cout << "No solution exists.\n";
return 0;

}
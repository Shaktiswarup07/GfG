//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(int row, int col, vector<string>&board){
        int p=row,q=col,n=board.size();
        while(p>=0 && q>=0){
            if(board[p][q]=='Q') return false;
            p--;
            q--;
        }
        p=row;q=col;
        while(p>=0 && q< n){
            if(board[p][q]=='Q') return false;
            p--;
            q++;
        }
        p=row;q=col;
        while(p>=0){
            if(board[p][q]=='Q') return false;
            p--;
        }
        return true;
    }
    void Solve(int row, vector<string>&board, vector<int>&ds, vector<vector<int>>&ans,int n){
        if(row==n){
            ans.push_back(ds);
            return;
        }
        for(int col=0 ; col<n ; col++){
            if(isPossible(row,col,board)){
                board[row][col]='Q';
                ds.push_back(col+1);
                Solve(row+1,board,ds,ans,n);
                ds.pop_back();
                board[row][col]='.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<string>board;
        for(int i = 0 ; i < n ; i++){
            string s;
            for(int j = 0 ; j< n; j++){
                s+='.';
            }
            board.push_back(s);
        }
        vector<int>ds;
        vector<vector<int>>ans;
        Solve(0,board,ds,ans,n);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
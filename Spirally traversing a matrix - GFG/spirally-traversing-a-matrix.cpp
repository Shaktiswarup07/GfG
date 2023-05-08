//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        int el=r*c;
        int row = 0,col = 0;
        vector<int>v;
        int i=0,j=0,k=r,l=c;
        while(true){
            while(col<c){
                v.push_back(mat[row][col]);
                col++;
            }
            if(v.size()==el) break;
            c--;
            i++;
            col--;
            row++;
            while(row<r){
                v.push_back(mat[row][col]);
                row++;
            }
            if(v.size()==el) break;
            r--;
            row--;
            col--;
            while(col>=j){
                v.push_back(mat[row][col]);
                col--;                
            }
            if(v.size()==el) break;
            col++;
            j++;
            row--;
            while(row>=i){
                v.push_back(mat[row][col]);
                row--;
            }
            col++;
            row++;
            if(v.size()==el) break;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
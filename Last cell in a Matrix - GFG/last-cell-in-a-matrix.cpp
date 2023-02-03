//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i=0,j=0;
        char dir='R';
        int x,y;
        // for(i = 0 ; i < R ; i++){
            // for( j = 0; j < C ; j++){
            while(true){
                if(i<0 || j<0 || i>=R || j>=C) break;
                x=i;y=j;
                if(matrix[i][j]==0){
                    if(dir=='R') j++;
                    else if(dir=='L') j--;
                    else if(dir=='U') i--;
                    else if(dir=='D') i++;
                }
                else{
                    matrix[i][j]=0;
                    if(dir=='R'){
                        dir='D';
                        i++;
                    }
                    else if(dir=='U'){
                        dir='R';
                        j++;
                    }
                    else if(dir=='D'){
                        dir='L';
                        j--;
                    }
                    else if(dir=='L'){
                        dir='U';
                        i--;
                    }
                }
            }
            return {x,y};
                
            // }
        // }
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
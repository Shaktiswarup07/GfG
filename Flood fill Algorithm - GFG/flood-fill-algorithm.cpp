//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // void dfs(int node, int V, vector<int>adj[],vector<int>&dfss,vector<bool>&vis){
    //     dfss.push_back(node);
    //     vis[node]=1;
    //     for(int i=0;i<adj[node].size();i++){
    //         if(vis[adj[node][i]]==0){
    //             dfss(adj[node][i], V, adj, dfss, vis);
    //         }
    //     }
    // }
    void dfs(int sr,int sc, vector<vector<int>> &ans, vector<vector<int>> &image,vector<vector<bool>> &vis,int newc,int inic){
        
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=newc;
        vis[sr][sc]=1;
        if(sc-1>=0 && ans[sr][sc-1]==inic && vis[sr][sc-1]==0){
            // vis[sr][sc-1]=1;
            // ans[sr][sc-1]=newc;
            dfs(sr,sc-1,ans,image,vis,newc,inic);
        }
        if(sr-1>=0 && ans[sr-1][sc]==inic && vis[sr-1][sc]==0){
            // vis[sr-1][sc]=1;
            // ans[sr-1][sc]=newc;
            dfs(sr-1,sc,ans,image,vis,newc,inic);
        }
        if(sc+1<m && ans[sr][sc+1]==inic && vis[sr][sc+1]==0){
            // vis[sr][sc+1]=1;
            // ans[sr][sc+1]=newc;
            dfs(sr,sc+1,ans,image,vis,newc,inic);
        }
        if(sr+1<n && ans[sr+1][sc]==inic && vis[sr+1][sc]==0){
            // vis[sr+1][sc]=1;
            // ans[sr+1][sc]=newc;
            dfs(sr+1,sc,ans,image,vis,newc,inic);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        // starting dfs with coordinate (sr,sc);
        int n=image.size();
        int m=image[0].size();
        int iniColor = image [sr][sc];
        vector<vector<int>> ans = image;
        vector<vector<bool>> vis( n , vector<bool> (m, 0));
        dfs(sr,sc,ans,image,vis,newColor,iniColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
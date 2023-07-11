//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		bool f=1;
 		int ci=0,ri=1;
 		vector<int>v;
 		int row=0,col=0;
 		int count=0;
 		int p=n,q=m;
 		while(count!=p*q){
 		    while(col<m){
 		        v.push_back(a[row][col]);
 		        count++;
 		        col++;
 		    }
 		    if(count==p*q) break;
 		    m--;
 		    col--;
 		    row++;
 		    while(row<n){
 		        v.push_back(a[row][col]);
 		        row++;
 		        count++;
 		    }
 		    if(count==p*q) break;
 		    n--;
 		    row--;
 		    col--;
 		    while(col>=ci){
 		        v.push_back(a[row][col]);
 		        col--;
 		        count++;
 		    }
 		    if(count==p*q) break;
 		    col++;
 		    ci++;
 		    row--;
 		    while(row>=ri){
 		        v.push_back(a[row][col]);
 		        row--;
 		        count++;
 		    }
 		    row++;
 		    col++;
 		    ri++;
 		    
 		}
 		return v[k-1];
 		
 		    
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int>mp;
      int cnt=0;
      for(int i = 0 ; i < N ; i++){
          mp[arr[i]]++;
      }
      map<int,int>m;
      int maxi=INT_MIN;
      for(int i = 0 ; i < N ; ){
          if(mp[arr[i]]){
              int k=arr[i];
              while(mp[k]){
                  cnt++;
                  mp[k]=0;
                  k++;
              }
              cnt+=m[k];
              maxi=max(maxi,cnt);
              m[arr[i]]=cnt;
              cnt=0;
              i++;
          }
          else{
              
              i++;
          }
      }
      
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
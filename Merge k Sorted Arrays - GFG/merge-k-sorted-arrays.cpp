//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    //FUNCTION TO MERGE 2 SORTED ARRAYS:
    vector<int> Merge(vector<int>v1,vector<int>v2){
        vector<int>v;
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]){
                v.push_back(v1[i]);
                i++;
            }
            else{
                v.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            v.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            v.push_back(v2[j]);
            j++;
        }
        return v;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans;
        for(int i = 0 ; i < K ; i++){
            vector<int>v1=arr[i];
            // vector<int>v2=arr[i+1];
            ans=Merge(ans,v1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
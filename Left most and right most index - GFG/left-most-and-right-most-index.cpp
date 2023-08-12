//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int findLastMostIdx(vector<long long> arr, long long x){
        int s=0,e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==x){
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid]>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int findFirstMostIdx(vector<long long> arr, long long x){
        int s=0,e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==x){
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid]>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        return {findFirstMostIdx(v,x), findLastMostIdx(v,x)};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    void NSLindex(long long heights[],long long n,vector<long long>&v){

        stack < pair < long long , long long > > st;

        for(long long i = 0 ; i < n ; i++){
            if(st.size()==0){
                v.push_back(-1);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                v.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size()==0) v.push_back(-1);
                else v.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
    }
    void NSRindex(long long heights[],long long n,vector<long long>&v){
        // int n=heights.size();
        stack < pair < long long , long long > > st;

        for(long long i = n-1 ; i >= 0 ; i--){
            if(st.size()==0){
                v.push_back(n);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                v.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=heights[i]){
                while(st.size()>0 && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.size()==0) v.push_back(n);
                else v.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(v.begin(),v.end());
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long>ans(n);
        vector<long long>v1,v2;
        NSLindex(arr,n,v1);
        NSRindex(arr,n,v2);
        for(long long i=0;i<n;i++){
            ans[i]=arr[i]*(v2[i]-v1[i]-1);
        }
        return *max_element(ans.begin(),ans.end());
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
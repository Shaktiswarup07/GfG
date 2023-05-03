//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> v,v1;
            set<int>s;
            int i=0,j=0;
            while(i<n1 && j<n2){
                if(A[i]==B[j]){
                    
                    v.push_back(A[i]);
                    i++;j++;
                }
                else if(A[i]<B[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            i=0;j=0;
            int n=v.size();
            while(i<n && j<n3){
                if(v[i]==C[j]){
                    s.insert(v[i]);
                    // v1.push_back(v[i]);
                    i++;j++;
                }
                else if(v[i]<C[j]){
                    i++;
                }
                else j++;
            }
            for(auto i:s){
                v1.push_back(i);
            }
            return v1;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends
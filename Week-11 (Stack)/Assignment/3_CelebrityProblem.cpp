//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        
        //push all person
        for(int i=0; i<n;i++){
            st.push(i);
        }
        
        //discard method
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b]){
                //a is celebrity and discard it
                st.push(b);
            }
            else{
                //b is celebrity and discard it
                st.push(a);
            }
        }
        
        //verify last element at stack
        int celeb = st.top();
        st.pop();
        //check all rows
        for(int i=0; i<n;i++){
            if(M[celeb][i] != 0){
                return -1;
            }
        }
        
        
        for(int i=0; i<n;i++){
            if(celeb == i) continue;
            if(M[i][celeb] != 1){
                return -1;
            }
        }
        
        return celeb;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1);
    int total_sum = 0;
    for(int i=1; i<n+1; ++i){
        cin>>v[i];
        total_sum+=v[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(total_sum+1,0));
        
    // dp[i][s] is true if there are numbers in a[1..i] summing upto s else false
    // dp[i][s] = dp[i-1][s] || dp[i-1][s-a[i]]
    // so dp is of size n*max_sum == n*(total_sum)
    // need to calculate all dp[i][j] => O(n*total_sum)
    // to return is dp[n][tot_sum/2]
    dp[1][0] = 1; dp[1][v[1]] = 1;
    for(int i=2; i<=n; ++i){
        for(int s=0; s<=total_sum; ++s){
            dp[i][s] = dp[i-1][s];
            if(dp[i][s]==0 && s-v[i]>=0)
                dp[i][s] = dp[i-1][s-v[i]];
//                cout<<dp[i][s]<<" ";
        }
//            cout<<endl;
    }
    int flag =0;
    for(int s =0; s<=total_sum; ++s){
        if(dp[n][s]==1 && ((2*s-total_sum)%360==0) ){
            flag=1;
            cout<<"YES"<<endl;
            break;
        }
    }
    if(flag==0)
        cout<<"NO"<<endl;
    
    return 0;
}

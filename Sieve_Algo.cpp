#include<bits/stdc++.h>
using namespace std;
void sieve(vector<int>&dp) { 
    for(int i = 2; i<=1e7; i++) {
        if(dp[i]==1){
            for(int j = 2*i; j<=1e7; j+=i)
                dp[j] = -1;     
        }
    }
    dp[0]=dp[1]=-1;   
}
int main() {

    vector<int> dp(1e7+1,1);
    sieve(dp);
    int n;
    cin >> n;
        if(dp[n]!=-1) 
            cout << "It is a Prime Number" << endl;
        else
            cout << " It is not a Prime Number" << endl;

    return 0;
}
// TC O(n(log(log(n))))
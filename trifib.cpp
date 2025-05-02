#include<iostream>
#include<vector>
using namespace std;
int trifib(int n ,  vector<int> &dp)
{
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = trifib(n-1,dp) + trifib(n-2,dp)+trifib(n-3,dp);

}
int main()
{
    int n =  25;
    vector<int> dp(n+1,-1);
    int ans = trifib(n,dp);
    cout << ans;
    return 0;
}
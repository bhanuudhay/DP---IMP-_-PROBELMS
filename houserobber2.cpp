#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[101];
int solve(vector<int> &arr, int i , int n)
{
    if(i>=n) return 0;
    if(dp[i] != -1) return dp[i];
    int steal = arr[i] + solve(arr,i+2,n);
    int skip =  solve(arr,i+1,n);

    return dp[i] = max(steal , skip);
}
int main()
{
    vector<int> arr = {1,2,3};
    int n =  arr.size();
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0],arr[1]);
    memset(dp,-1,sizeof(dp));
    int first = solve(arr,0,n-1);
    memset(dp,-1,sizeof(dp));
    int second  = solve(arr,1,n);
    int ans =  max(first , second);
    cout << ans ;
    return 0;  
}
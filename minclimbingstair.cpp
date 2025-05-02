#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr = {1,100,1,1,1,100,1,1,100,1};
    int n =  arr.size();
    vector<int> dp(n+1);
    dp[0] = dp[1] = 0;
    for(int i = 2 ; i<= n ;i++)
    {
        dp[i] = min(dp[i-1]+arr[i-1] , dp[i-2]+arr[i-2]);
    }
    cout << dp[n];
    return 0;
}
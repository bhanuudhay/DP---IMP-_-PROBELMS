#include<iostream>
#include<vector>
#include<string>
using namespace std;
int solve(string s)
{
    int n = s.length();
    if(n == 0 || s[0] == '0') return 0;
    vector<int> dp(n+1);
    dp[0]= dp[1] = 1;
    for(int i = 2 ; i <= n ;i++)
    {
        if(s[i-1] != '0')
        {
          dp[i] += dp[i-1];
        }
        int num = stoi(s.substr(i-2,2));
        if(num >= 10 && num <=26)
        {
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}
int main()
{
    string s = "06";
    int res = solve(s);
    cout << res;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t[1001][1001];
int mod = 1e9 + 7;
int solve(string s1, string s2, int n , int m)
{
    for(int i = 0 ;i <= n ;i++)
    {
        for(int j = 0 ; j<= m ;j++)
        {
            if(j == 0)
            {
                t[i][j] = 1;
            }
            else if(i == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i<= n ;i++)
    {
        for(int j = 1 ; j<= m ;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                t[i][j] = (t[i-1][j-1] + t[i-1][j]) %mod;
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][m];
}
int main()
{
    string s1 = "babgbag";
    string s2 = "bag";
    int n  =  s1.length();
    int m = s2.length();
    cout << solve(s1,s2,n,m);
}
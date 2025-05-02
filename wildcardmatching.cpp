#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
int t[2001][2001];
int solve(string s, string p , int n, int m)
{
    for(int i = 0 ;i <= n ;i++)
    {
        for(int j = 0 ; j <= n ;j++)
        {
            if(j == 0)
            {
                t[i][j] = (i == 0) ? 1 : 0;
            }
            else if(i == 0)
            {
                t[i][j] = p[j-1] == '*' ? t[i][j-1] : 0;
            }
        }
    }
    for(int i = 1 ; i<= n ;i++)
    {
        for(int j = 1 ; j <=m ; j++)
        {
            if(s[i-1] == p[j-1] || p[j-1] == '?')
            {
                t[i][j] = t[i-1][j-1];
            }
            else if(p[j-1] == '*')
            {
                t[i][j] = t[i-1][j] || t[i][j-1];
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return t[n][m];
}
int main()
{
    string s = "cb";
    string p = "?a";
    int n = s.length();
    int m = p.length();
    cout << solve(s,p,n,m);
}
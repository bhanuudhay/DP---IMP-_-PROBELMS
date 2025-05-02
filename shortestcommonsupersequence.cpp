#include<iostream>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(string s1,string s2, int n, int m)
{
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ;j++)
        {
            t[i][j] = 0;
        }
    }
    for(int i = 1 ; i<= n ; i++)
    {
        for(int j = 1; j <= m ;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
int main()
{
    string s1  = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.length();
    int m = s2.length();
    cout << n+m - solve(s1,s2,n,m);
}
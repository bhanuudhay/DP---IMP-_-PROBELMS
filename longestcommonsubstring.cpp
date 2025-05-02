#include<iostream>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(string s1,string s2 , int n , int m)
{
    int res = 0;
    for(int i = 0 ; i<=n ;i++)
    {
        for(int j = 0 ; j<= m ;j++)
        {
            t[i][j] = 0;
        }
    }
    for(int i = 1; i<= n ;i++)
    {
        for(int j =1 ; j <= m ;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
                res = max(res, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return  res;
}
int main()
{
    string s1 = "abc";
    string s2 = "acb";
    int n =  s1.length();
    int m = s2.length();
    cout << solve(s1,s2,n,m);
}
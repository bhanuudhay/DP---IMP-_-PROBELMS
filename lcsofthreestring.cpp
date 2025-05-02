#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t[21][21][21];
int solve(string s1 ,string s2 ,string s3 , int n , int m , int o)
{
    for(int i = 0 ; i <= n ;i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            for(int k = 0 ; k <= o ; k++)
            {
                t[i][j][k] = 0;
            }
        }
    }
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            for(int k = 1 ; k <= o ; k++)
            {
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                {
                    t[i][j][k] = 1 + t[i-1][j-1][k-1];
                }
                else 
                {
                    t[i][j][k] = max({t[i-1][j][k] , t[i][j-1][k] , t[i][j][k-1]});
                }
            }
        }
    }
    return t[n][m][o];
}
int main()
{
    string s1 =  "abcd" , s2 = "efgh" , s3 = "ijkl";
    int n = s1.length() ,  m  =  s2.length() , o  = s3.length();
    cout << solve(s1,s2,s3,n,m,o);
}
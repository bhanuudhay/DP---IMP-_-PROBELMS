#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t[501][501];
int solve(string s1, string s2, int n , int m)
{
    for(int i = 0  ;i<= n; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
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
    string s1 = "leetcode";
    string s2 = "etco";
    int n =  s1.length();
    int m =  s2.length();
    int ans =  solve(s1,s2,n,m);
    cout << n+m - 2*ans;
}
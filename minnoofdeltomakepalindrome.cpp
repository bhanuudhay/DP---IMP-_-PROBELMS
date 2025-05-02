#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(string s1, string rev, int n, int m)
{
    for(int i = 0 ; i<= n ;i++)
    {
        for(int j = 0 ; j  <= m ;j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if(s1[i-1] == rev[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] ,t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
int main()
{
    string s1 =  "aba";
    int n =  s1.length();
    string rev =  s1;
    reverse(rev.begin() , rev.end());
    int m =  rev.length();
    cout << n - solve(s1,rev,n,m);
}
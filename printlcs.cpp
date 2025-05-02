#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t[1001][1001];
string solve(string s1, string s2, int n , int m)
{
    for(int i = 0 ; i<= n ;i++)
    {
        for(int j = 0 ; j<= m; j++)
        {
            if(i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if( s1[i-1] == s2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }

    string res = "";
    int i = n , j = m;
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if( t[i-1][j] > t[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin() , res.end());
    return res;
}
int main()
{
    string s1 = "ababa";
    string s2 = "cbbcad";
    int n = s1.length();
    int m = s2.length();
    string ans =  solve(s1,s2,n,m);
    cout << ans;
}
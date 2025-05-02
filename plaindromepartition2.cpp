#include <bits/stdc++.h>
using namespace std;
int t[2001][2001];
bool isPalindrome(string &s , int i, int j)
{
    while(i<j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string &s, int i , int j)
{
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];
    int min = INT_MAX;
    if(isPalindrome(s,i,j)) return 0;
    for(int k = i ; k < j ;k++)
    {
        int left , right;
        if(t[i][k] != -1) 
        {
            left = t[i][k];
        }
        else
        {
            left = solve(s,i,k);
            t[i][k] = left;
        }

        if(t[k+1][j] != -1)
        {
            right = t[k+1][j];
        }
        else
        {
            right = solve(s,k+1,j);
            t[k+1][j] = right;
        }
        int temp = left + right + 1;
        if(temp<min)
        {
            min = temp;
        }
    }
    return t[i][j] = min;
}
int main()
{
    string s = "aab";
    int n = s.length();
    memset(t,-1,sizeof(t));
    int ans = solve(s,0,n-1);
    cout << ans;
}
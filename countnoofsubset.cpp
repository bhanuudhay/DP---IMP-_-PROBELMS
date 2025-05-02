#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int t[1001][1001];
int mod = 1e9 + 7;
int solve(vector<int>&arr, int k , int n)
{
    for(int i = 0  ; i <= n ;i++)
    {
        for(int j = 0 ; j<= k ;j++)
        {
            if(j == 0)
            {
                t[i][j] = 1;
            }
            else if(i ==0)
            {
                t[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= k ;j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % mod;
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][k];
}
int main()
{
    vector<int> arr = {1, 1, 4, 5};
    int k = accumulate(arr.begin(),arr.end(),0);
    int n = arr.size();
    cout << solve(arr,k,n);
}
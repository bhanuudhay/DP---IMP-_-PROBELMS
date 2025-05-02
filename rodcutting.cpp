#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(vector<int> &arr , int sum , int n)
{
    for(int i = 0 ; i<=n ; i++)
    {
        for(int j = 0 ; j<= sum ; j++)
        {
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }
    for(int i = 1 ; i<= n ;i++)
    {
        for(int j = 1 ; j<= sum ;j++)
        {
            if(i <= j)
            {
                t[i][j] = max(arr[i-1] + t[i][j-i] , t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    vector<int> price  = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    cout << solve(price,n,n);
}
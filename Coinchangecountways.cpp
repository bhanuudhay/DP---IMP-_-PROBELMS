#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(vector<int> &arr, int sum , int n)
{
    for(int i = 0 ; i<= n ;i++)
    {
        for(int j = 0 ; j<= sum ;j++)
        {
            if(j == 0)
            {
                t[i][j] = 1;
            }
            else if(i == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i <= n ;i++)
    {
        for(int j = 0 ; j <= sum ; j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = t[i][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    int sum = 3;
    vector<int> arr ={5, 10};
    int n = arr.size();
    cout << solve(arr,sum,n);
}
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include <climits>
using namespace std;
int t[1001][1001];
int solve(vector<int>&arr, int sum , int n)
{
    for(int i = 0 ; i <= n ;i++)
    {
        for(int j = 0 ; j <= sum ;j++)
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
    for(int i =1 ; i<= n ;i++)
    {
        for(int j = 1 ; j<= sum ;j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    int diff = INT_MAX;
    for(int j = sum/2 ; j>= 0 ; j--)
    {
        if(t[n][j])
        {
            diff = sum - 2 *j;
            break;
        }
    }
    return diff;
}
int main()
{
    vector<int> arr = {1, 4};
    int n = arr.size();
    int sum =  accumulate(arr.begin() ,arr.end(),0);
    cout << solve(arr,sum,n);
}
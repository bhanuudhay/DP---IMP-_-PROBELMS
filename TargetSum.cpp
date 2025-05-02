#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(vector<int>& arr, int target , int n)
{
    for(int i = 0 ; i<= n; i++)
    {
        for(int j= 0 ; j<= target ; j++)
        {
            if(j == 0)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j<= target ; j++)
        {
            if(arr[i-1] <= j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][target];
}
int main()
{
    int k = 3;
    vector<int> arr = {1,1,1,1,1};
    int n = arr.size();
    int sum = accumulate(arr.begin() , arr.end() ,0);
    if((sum-k)%2!=0 || sum < k) return 0;
    int target = (sum-k)/2;
    int ans = solve(arr,target,n);
    cout << ans;
}
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int t[101][101];
int solve(vector<int>& arr, int i, int j)
{
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];
    int min = INT_MAX;
    for(int k = i ; k < j ; k++)
    {
        int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];

        if(temp < min)
        {
            min = temp;
        }
    }
    return t[i][j] = min;
}
int main()
{
    vector<int> arr = {3, 4};
    int n = arr.size();
    memset(t,-1,sizeof(t));
    int ans = solve(arr,1,n-1);
    cout << ans;
}
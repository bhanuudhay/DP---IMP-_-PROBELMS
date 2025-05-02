#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int t[101];
int solve(vector<int> &arr , int i , int n )
{
    if(i>=n) return 0;
    if(t[i] != -1) return t[i];

    int steal =  arr[i] + solve(arr,i+2,n);
    int skip =  solve(arr,i+1,n);

    return t[i] = max(steal,skip);
}
int main()
{
    vector<int> arr = {1,2,3,1};
    memset(t,-1,sizeof(t));
    int n =  arr.size();
    if(n == 0) return 0;
    int ans = solve(arr,0,n);
    cout << ans;
    return 0;
}
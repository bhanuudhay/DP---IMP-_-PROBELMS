#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t[1001][1001];
int solve(int W , vector<int>& val , vector<int>& wt , int n)
{
    for(int i = 0 ; i<= n ;i++)
    {
        for(int j = 0 ; j<= W ; j++)
        {
            t[i][j] = 0;
        }
    }
    for(int i = 1 ; i<= n ;i++)
    {
        for(int j = 1 ; j <= W ; j++)
        {
            if(wt[i-1] <= j)
            {
                t[i][j] = max(val[i-1]
                      + t[i-1][j-wt[i-1]] , t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];

}
int main()
{
    int W = 5;
    vector<int> val = {10,40,30,50};
    vector<int> wt = {5,4,2,3};
    int n = wt.size();

    int ans = solve(W,val,wt,n);
    cout << ans;
}
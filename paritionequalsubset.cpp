#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int t[1001][1001];
int solve(vector<int>& arr ,int sum , int n)
{
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                t[i][j]=1;
            }
            else if(i==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
            {
                t[i][j]  = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    vector<int> arr = {1, 3, 5};
    int sum = accumulate(arr.begin() ,arr.end(),0);
    int n = arr.size();
    if(sum%2!=0)
    {
        cout << "false";
        return 0;
    }
    else
    {
        cout <<  solve(arr,sum,n);
    }
       
}
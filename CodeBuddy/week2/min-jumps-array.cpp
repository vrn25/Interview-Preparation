// Problem for week 1 codebuddy IEEE: https://www.interviewbit.com/problems/min-jumps-array/
#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>&A, int idx, int n, int dp[]){
	
	if(idx==n){
		dp[n] = 0;
		return 0;
	}

	if(dp[idx]!=-1)
		return dp[idx];

	int mini = 50000;
	for(int i=idx+1;i<=min(idx+A[idx],n);i++){
		mini = min(mini, fun(A,i,n,dp));
	}
	dp[idx] = mini+1;
	return dp[idx];
}


int main(){
	vector<int>A = {};
	int n = A.size()-1;
	int dp[n+1];
	memset(dp,-1,sizeof(dp));
	int r = fun(A,0,n,dp);
	if(r>50000)
		cout<<"-1";
	else
		cout<<r;
}
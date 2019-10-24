// Problem for week 2 codebuddy web club: https://www.interviewbit.com/problems/stairs/
int stairs(int A, int dp[]){
    if(A==1){
        dp[1] = 1;
        return dp[1];
    }
    if(A==2){
        dp[2] = 2;
        return dp[2];
    }
    if(dp[A]!=-1)
        return dp[A];

    dp[A] = stairs(A-1, dp) + stairs(A-2, dp);
    return dp[A];
}
int Solution::climbStairs(int A) {
    int dp[A+1];
    memset(dp, -1, sizeof(dp));
    return stairs(A,dp);
}

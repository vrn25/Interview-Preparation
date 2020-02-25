// Link to problem: https://www.interviewbit.com/problems/ways-to-decode/
int Solution::numDecodings(string A) {
    if(A[0]=='0')
        return 0;
    int dp[A.size()];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<A.size();i++){
        if(A[i]=='0'){
            if(A[i-1] != '1' && A[i-1] != '2')
                return 0;
        }
        if(A[i]!='0')
            dp[i] += dp[i-1];
        if(A[i-1]!='0' && stoi(A.substr(i-1, 2)) <= 26){
            if(i==1)
                dp[i] += 1;
            else
                dp[i] += dp[i-2];
        }
    }
    return dp[A.size()-1];
}
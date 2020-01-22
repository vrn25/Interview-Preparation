/* Problem: https://www.interviewbit.com/problems/different-bits-sum-pairwise/ */
int Solution::cntBits(vector<int> &A) {
    long long count = 0;
    long long M = 1000000007;
    for(int i=0;i<31;i++){
        long long ones = 0, zeros = 0;
        for(int j=0;j<A.size();j++){
            if(A[j] & (1<<i))
                ones++;
            else
                zeros++;
        }
        count += ones * zeros;
    }
    return (count * 2) % M;
}

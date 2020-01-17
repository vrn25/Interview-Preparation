int Solution::maxArea(vector<int> &A) {
    int a = 0, b = A.size()-1, ar;
    int max = 0;
    while(b > a){
        if(A[a] < A[b]){
            ar = (b-a) * A[a];
            a += 1;
        }
        else{
            ar = (b-a) * A[b];
            b -= 1;
        }
        if(ar > max)
            max = ar;
    }
    return max;
}

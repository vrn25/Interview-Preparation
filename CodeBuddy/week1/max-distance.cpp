// Problem for week 1 codebuddy web club: https://www.interviewbit.com/problems/max-distance/
int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>>v;
    int n = A.size();
    for(int i=0;i<n;i++){
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    int largest, max_diff;
    largest = v[n-1].second;
    max_diff = 0;
    for(int i=n-2;i>=0;i--){
        if(largest-v[i].second > max_diff)
            max_diff = largest-v[i].second;
        if(v[i].second > largest)
            largest = v[i].second;
    }
    return max_diff;
}
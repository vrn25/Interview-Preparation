// Problem for week 1 codebuddy IEEE: https://www.interviewbit.com/problems/largest-number/
bool comp(string a, string b){
    string f1 = a+b;
    string f2 = b+a;
    return f1>f2?1:0;
}

string Solution::largestNumber(const vector<int> &A) {
    if(!accumulate(A.begin(),A.end(),0))
        return "0";
    vector<string>v;
    for(int i=0;i<A.size();i++)
        v.push_back(to_string(A[i]));
    sort(v.begin(),v.end(),comp);
    string ans;
    for(int i=0;i<A.size();i++)
        ans += v[i];
    return ans;
}


int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int>v(n);
    v[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        int mini = v[i+1];
        int flag = 0;
        for(int j=i+1;j<=min(i+A[i],n-1);j++){
            flag = 1;
            if(v[j]<mini)
                mini = v[j];
        }
        if(!flag)
            v[i] = 50001;
        else
            v[i] = mini+1;
    }
    if(v[0]>50000)
        return -1;
    else
        return v[0];
}

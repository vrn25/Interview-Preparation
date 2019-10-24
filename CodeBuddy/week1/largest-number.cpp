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
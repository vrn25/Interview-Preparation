// Problem: https://www.interviewbit.com/problems/4-sum/ 
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>>v;
    sort(A.begin(), A.end());
    for(int i=0;i<A.size();i++){
        if(i!=0 && A[i] == A[i-1])
            continue;
        for(int j=i+1;j<A.size();j++){
            if(A[j] == A[j-1] && j!=i+1)
                continue;
            int p1 = j+1, p2 = A.size() - 1;
            int target = B - A[i] - A[j];
            while(p2 > p1){
                int res = A[p1] + A[p2];
                if(res < target)
                    p1++;
                else if(res > target)
                    p2--;
                else{
                    if(A[p1] == A[p1-1] && p1!=j+1){
                        p1++;
                        continue;
                    }
                    vector<int>a = {A[i], A[j], A[p1], A[p2]};
                    v.push_back(a);
                    p1++;
                }
            }
        }
    }
    return v;
}
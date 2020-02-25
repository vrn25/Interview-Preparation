// https://www.interviewbit.com/problems/longest-palindromic-substring/

//  TC: O(n*n), SC: O(1) Solution, Status: Accepted:
string Solution::longestPalindrome(string A) {
    int n = A.size();
    int ptr1 = 0, ptr2 = 0;
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        int p1 = i-1, p2 = i+1;
        int size = 1;
        if(i>0 && i<n-1){
            while(p1>=0 && p2<n){
                if(A[p1]==A[p2]){
                    size += 2;
                    p1--;p2++;
                }
                else
                    break;
            }
        }
        if(size > max){
            max = size;
            ptr1 = p1+1;
            ptr2 = p2-1;
        }
    }

    for(int i=0;i<n-1;i++){
        if(A[i]!=A[i+1])
            continue;
        int size = 2;
        int p1 = i-1, p2 = i+2;
        if(i>0 && i<n-1){
            while(p1>=0 && p2<n){
                if(A[p1]==A[p2]){
                    size += 2;
                    p1--;p2++;
                }
                else
                    break;
            }
        }
        if(size > max){
            max = size;
            ptr1 = p1+1;
            ptr2 = p2-1;
        }
    }
    return A.substr(ptr1, ptr2-ptr1+1);
}

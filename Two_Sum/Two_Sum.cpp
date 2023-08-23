void merger(vector<int>& A, vector<int>& B, vector<int>& C, int n1, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (B[i] < C[j]) A[k++] = B[i++];
        else A[k++] = C[j++];
    }
    while (i < n1) A[k++] = B[i++];
    while (j < n2) A[k++] = C[j++];
}

bool binsearch(vector<int>& A,int n,int q,int& place)
    {
        int first = 0,last = n -1;
        int mid = (first + last)/2;
        while(first <= last)
            {
                if(A[mid] == q) 
                    {
                        place = mid;
                        return true;
                    }
                else if(A[mid] > q) last = mid - 1;
                else first = mid + 1;
                mid = (first + last)/2;
            }
        return false;
    }

void mergesort(vector<int>& nums, int n) {
    if (n <= 1) return;
    
    int mid = n / 2;
    vector<int> B1(mid);
    vector<int> B2(n - mid);

    for (int i = 0; i < mid; i++) {
        B1[i] = nums[i];
    }
    for (int i = mid; i < n; i++) {
        B2[i - mid] = nums[i];
    }

    mergesort(B1, mid);
    mergesort(B2, n - mid);
    merger(nums, B1, B2, mid, n - mid);
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> source;
        for(int i = 0;i < n;i++) source.push_back(nums[i]);
        mergesort(nums,n);
        int ans;
        vector<int> A;
        vector<int> B;
        for(int i = 0;i < n;i++)
            {
                if(binsearch(nums,n,target - nums[i],ans))
                    {
                        if(A.size() == 2) break;
                        A.push_back(i);
                        if(A.size() == 2) break;
                        if(i == ans) continue;
                        A.push_back(ans);
                        break;
                    }
            }
        for(int i = 0;i < n;i++)
            {
                if(nums[A[0]] == source[i])
                    {
                        B.push_back(i);
                        break;
                    }
            }
        for(int i = 0;i < n;i++)
            {
                if(i == B[0]) continue;
                if(source[i] == nums[A[1]]) 
                    {
                        B.push_back(i);
                        break;
                    }
            }
        return B;
    }
};

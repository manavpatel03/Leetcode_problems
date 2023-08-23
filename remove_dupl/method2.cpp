#include<set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    set<int> S;
    S.insert(nums[0]);
    int n = nums.size(),check = nums[0];
    for(int i = 1;i < n;i++) S.insert(nums[i]);
    vector<int> V;
    for(int i : S)
        {
            V.push_back(i);
        }
    nums.clear();
    nums.shrink_to_fit();
    nums = V;
        return V.size();
    }
};

// much better in terms of time, but space use was not optimal

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int check = nums[0],count = 1;
        for(int i = 1;i < nums.size();i++)
            {
                if(nums[i] == check)
                    {
                        nums.erase(nums.begin() + i);
                        i--;
                    }
                else
                    {
                        check = nums[i];
                        count++;
                    }
            }
        return count;
    }
};

// erase is a O(n) method, leading to longer time

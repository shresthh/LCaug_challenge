class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for( auto n : nums){
            n = abs(n);
            if(nums[n-1] > 0) nums[n-1] *= -1;
            else v.push_back(n);
        }
        return v;
    }
};

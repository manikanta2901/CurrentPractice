class Solution {
private:
    vector<vector<int>> allSubsets;

    void getSubsets(int index,vector<int>&answer,vector<int>&nums){
        if(index >= nums.size()){
            allSubsets.push_back(answer);
            return;
        }
        //pick
        answer.push_back(nums[index]);
        getSubsets(index + 1,answer,nums);
        answer.pop_back();

        //Not pick
        getSubsets(index + 1,answer, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>answer;
        getSubsets(0,answer,nums);
        return allSubsets;
    }
};
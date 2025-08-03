class Solution {
public:
    vector<vector<int>> permutations;

    void getAnswer(vector<int>&nums,int index){
        if(index >= nums.size()){
            permutations.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[index],nums[i]);
            getAnswer(nums,index + 1);
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        getAnswer(nums,0);
        return permutations;
    }
};
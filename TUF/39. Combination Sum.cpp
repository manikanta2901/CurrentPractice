class Solution {
public:
    vector<vector<int>> combinations;

    void getSum(vector<int>&nums,vector<int>&answer,int target,int sum ,int index){
        if(sum == target){
            combinations.push_back(answer);
            return;
        }
        if(index >= nums.size()){
            return;
        }
        //pick
        if(sum + nums[index] <= target){
            answer.push_back(nums[index]);
            sum += nums[index];
            getSum(nums,answer,target,sum,index);
            answer.pop_back();
            sum -= nums[index];
        }

        // notPick
        getSum(nums,answer,target,sum, index + 1);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>answer;
        getSum(candidates,answer,target,0,0);
        return combinations;
    }
};
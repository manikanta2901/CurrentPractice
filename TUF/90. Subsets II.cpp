class Solution {
public:
    vector<vector<int>> allSubsets;

    void getSubset(vector<int>& nums,vector<int>& answer,int index){
        if(index >= nums.size()){
            allSubsets.push_back(answer);
            return;
        }
        // pick
        answer.push_back(nums[index]);
        getSubset(nums,answer,index + 1);
        answer.pop_back();

        // Skip duplicates
        int notDuplicate = index + 1;
        while(notDuplicate < nums.size() && nums[index] == nums[notDuplicate]){
            notDuplicate++;
        }   
        // not pick
        getSubset(nums,answer,notDuplicate);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>answer;
        getSubset(nums,answer,0);
        return allSubsets;
    }
};
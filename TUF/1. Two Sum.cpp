class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int,int> fre;
        for(int i = 0; i < nums.size(); i++){
            int required = target - nums[i];
            if(fre.find(required) != fre.end()){
                answer.push_back(i);
                answer.push_back(fre[required]);
            }
            fre[nums[i]] = i;
        }
        return answer;
    }
};

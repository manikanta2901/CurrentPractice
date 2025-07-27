class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int element1 = 0,element2 = 0;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < size; i++){
            if(element1 == nums[i]){
                count1++;
            }else if(element2 == nums[i]){
                count2++;
            }else if(count1 == 0){
                element1 = nums[i];
                count1++;
            }else if(count2 == 0){
                element2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        if(count1 == 0 && count2 == 0){
            return {};
        }   
        vector<int>answer;
        count1 = 0,count2 = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == element1){
                count1++;
            }else if(nums[i] == element2){
                count2++;
            }
        }


        if(count1 > (size / 3)){
            answer.push_back(element1);
        }
        if(count2 > (size / 3)){
            answer.push_back(element2);
        }
        return answer;
    }
};
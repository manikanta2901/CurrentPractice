class Solution {
public:
    int majorityElement(vector<int>& nums){
        int count = 0;
        int element = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(count == 0){
                element = nums[i];
            }
            if(element == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return element;
    }
};
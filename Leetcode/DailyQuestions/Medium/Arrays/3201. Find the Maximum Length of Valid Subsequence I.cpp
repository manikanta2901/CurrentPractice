class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        int alternative = 0;
        int current = -1;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] % 2 == 0){
                even++;
                if(current == -1 || current == 1){
                    alternative++;
                }
            }else{
                odd++;
                if(current == -1 || current == 0){
                    alternative++;
                }
            }
            current = nums[i] % 2;
        }
        return max({odd,even,alternative});
    }
};
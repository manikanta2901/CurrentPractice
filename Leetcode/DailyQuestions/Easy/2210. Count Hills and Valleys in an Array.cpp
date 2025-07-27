class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0,i = 1;
        int size = nums.size();
        
        for(int i = 1; i < size - 1; i++){
            int pos = i;
            if(nums[i - 1] == nums[i]){
                pos = i - 1;
                while(i < size - 1 && (nums[i] == nums[i -1])){
                    i++;
                }
                i--;
                // cout << pos << " " << nums[pos] << endl;
            }if(pos >= 1 && nums[pos - 1] < nums[i] && nums[i] > nums[i + 1]){
                // cout << pos << " pos" << endl;
                // cout << i << " " << nums[i] << endl;
                count++;
            }if(pos >= 1 && nums[pos - 1] > nums[i] && nums[i] < nums[i + 1]){
                // cout << pos << " pos" << endl;
                // cout << i << " " << nums[i] << endl;
                count++;
            }
        }
        return count;
    }
};
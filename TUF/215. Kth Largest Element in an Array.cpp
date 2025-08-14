class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>store;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            store.push(nums[i]);
            if(store.size() > k){
                // cout << store.top() << endl;
                store.pop();
            }
        }
        return store.top();
    }
};
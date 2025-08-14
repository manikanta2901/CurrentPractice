class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>answer;
        map<int,int>fre;
        priority_queue<pair<int,int>> store;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            fre[nums[i]]++;
        }

        for(auto& [num,count] : fre){
            store.push({count,num});
        }

        while(!store.empty()){
            int val = store.top().second;
            store.pop();
            if(answer.size() < k){
                answer.push_back(val);
            }
        }
        return answer;
    }
};
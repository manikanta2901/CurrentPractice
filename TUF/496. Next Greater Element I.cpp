// Do the next Greater element on num2 and store answers in a map
// Now iterate through the second array and push the answers in a vector
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        stack<int>store;
        unordered_map<int,int> nextGreaterElementMap;
        for(int i = n - 1; i >= 0; i--){
            while(!store.empty() && store.top() <= nums2[i]){
                store.pop();
            }
            if(store.empty()){
                nextGreaterElementMap[nums2[i]] = -1;
            }else{
                nextGreaterElementMap[nums2[i]] = store.top();
            }
            store.push(nums2[i]);
        }
        vector<int>answer;
        for(int i = 0; i < m; i++){
            answer.push_back(nextGreaterElementMap[nums1[i]]);
        }
        return answer;
    }
};
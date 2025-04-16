class Solution {
    int getGoodPairs(unordered_map<int,int>fre){
        int answer = 0;
        for(auto it : fre){
            int num = it.second;
            if(num >= 2){
                answer += ((num * (num - 1)) / 2);
            }
        }
        return answer;
    }
public:
    long long countGood(vector<int>& nums, int k) {
        int size = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int>fre;
        int answer = 0;
        int count = 0;
        int one = 0;
        while(r < size){
            fre[nums[r]]++;
            count = getGoodPairs(fre);
            while(count >= k && l < size){
                answer += (size - r);
                fre[nums[l]]--;
                count = getGoodPairs(fre);
                l++;
            }
            r++;
        }
        return answer;
    }
};

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long size = nums.size();
        long long l = 0;
        long long r = 0;
        unordered_map<int,int>fre;
        long long answer = 0;
        long long count = 0;
        while(r < size){
            count += fre[nums[r]];
            fre[nums[r]]++;
            while(count >= k){
                answer += (size - r);
                fre[nums[l]]--;
                count -= fre[nums[l]];
                l++;
            }
            r++;
        }
        return answer;
    }
};
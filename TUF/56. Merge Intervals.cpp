class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        int size = intervals.size();
        sort(intervals.begin(),intervals.end());
        int startTime = intervals[0][0],endTime = intervals[0][1]; 
        for(int i = 1; i < size; i++){
            if(startTime  <= intervals[i][0] && intervals[i][0] <= endTime){
                if(endTime <= intervals[i][1]){
                    endTime = intervals[i][1];
                }
            }else{
                answer.push_back({startTime,endTime});
                startTime = intervals[i][0];
                endTime = intervals[i][1];
            }
        }
        answer.push_back({startTime,endTime});
        return answer;
    }
};
class Solution {
public:
   std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
       int n = intervals.size();
      
       std::sort(intervals.begin(), intervals.end());

       std::vector<std::vector<int>> result;
       result.push_back(intervals[0]);

       for (int i = 1; i < n; i++) {
           std::vector<int>& lastInterval = result.back();

           if (lastInterval[1] >= intervals[i][0]) {
               lastInterval[1] = std::max(lastInterval[1], intervals[i][1]);
           } else {
               result.push_back(intervals[i]);
           }
       }
       return result;
   }
};

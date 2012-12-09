/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// credit: http://blog.csdn.net/zhiyu27/article/details/8192302
class Solution {
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      vector<Interval> result;
      // has add newInterval
      bool flag = false;
      for(int i = 0;i < intervals.size(); ++ i){
        // [1, 2], [4, 5]
        if(intervals[i].end < newInterval.start){
          result.push_back(intervals[i]);
          continue;
        }
        // [7, 8], [4, 5]
        if(intervals[i].start > newInterval.end){
          if(!flag)
            result.push_back(newInterval);
          flag = true;
          result.push_back(intervals[i]);
          continue;
        }
        // [3, 4], [4, 5] // [3, 5], [4, 5] // [3, 6], [4, 5]
        if(intervals[i].start < newInterval.start){
          newInterval.start = intervals[i].start;
        }
        // [3, 6], [4, 5] // [5, 6], [4, 5]
        if(intervals[i].end > newInterval.end){
          newInterval.end = intervals[i].end;
          result.push_back(newInterval);
          flag = true;
        }
        // [4, 5]
      }
      if(!flag)
        result.push_back(newInterval);
      return result;
    }
};

/*
 * struct Interval {
 * int start;
 * int end;
 * Interval() : start(0), end(0) {}
 * Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// O(n logn)
struct comp {
  bool operator() (const Interval &a, const Interval &b) {
    return a.start < b.start;
  }
};

vector<Interval> merge(vector<Interval> &intervals) {
  vector<Interval> result;
  if (intervals.empty())
    return result;
  sort(intervals.begin(), intervals.end(), comp());
  result.push_back(intervals[0]);
  for (int i = 1; i < intervals.size(); i ++) {
    if (result.back().end >= intervals[i].start)
      result.back().end = max(result.back().end, intervals[i].end);
    else
      result.push_back(intervals[i]);
  }
  return result;
}

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        result = []
        for i in range(len(intervals)):
            if not len(result):
                result.append(intervals[i])
            elif len(result) and result[-1][1] < intervals[i][0]:
                result.append(intervals[i])
            else:
                result[-1][1] = max(result[-1][1],intervals[i][1])
        
        return result
  
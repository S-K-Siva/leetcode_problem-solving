class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = end = 0
        count = 0
        result = 0
        d = dict()
        while start <= end and end < len(s):
            try:
                if d[s[end]]:
                    if s[end] == s[start]:
                        start += 1
                        end += 1
                    else:
                        result = max(result,count)
                        start += 1
                        end = start + 1
                        count = 1
                        d = dict()
                        d[s[start]] = 1
            except:
                
                d[s[end]] = 1
                count += 1
                result = max(result,count)
                end += 1
        return result

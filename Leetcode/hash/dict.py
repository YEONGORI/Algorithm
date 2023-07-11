class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = dict()
        for i in nums:
            if (i in dic):
                dic[i] += 1
            else:
                dic[i] = 1

        MAX = 0
        M_KEY = 0
        for k, v in dic.items():
            if v > MAX:
                MAX = v
                M_KEY = k
        return M_KEY

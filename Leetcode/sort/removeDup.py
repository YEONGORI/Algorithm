class Solution:
    def removeDuplicates1(self, nums: list[int]) -> int:
        newList = list()
        for i in nums:
            if i not in newList: newList.append(i)
        nums = newList.copy()
        return len(nums)

    def removeDuplicates2(self, nums: list[int]) -> int:
        newList = list(set(nums))
        newList.sort()
        nums = newList.copy()
        return len(nums)
    
    def removeDuplicates3(self, nums: list[int]) -> int:
        newList = list()
        for i in nums:
            if newList.count(i) < 2:
                newList.append(i)
        nums = newList.copy()
        return len(nums)
    
Solution.removeDuplicates3(Solution, [0,0,1,1,1,1,2,3,3])
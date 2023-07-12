class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        l_max = r_max = -1
        ans = left = 0
        right = n - 1

        while (left <= right):
            if (height[left] <= height[right]):
                l_max = max(height[left], l_max)
                ans += abs(l_max - height[left])
                left += 1
            else:
                r_max = max(height[right], r_max)
                ans += abs(r_max - height[right])
                right -= 1

        return ans


Solution.trap(Solution, [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])

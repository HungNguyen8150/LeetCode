from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        prev2 = 0  # dp[i-2]
        prev1 = 0  # dp[i-1]
        
        for c in cost:
            curr = c + min(prev1, prev2)
            prev2 = prev1
            prev1 = curr
        
        return min(prev1, prev2)

from typing import List

class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        sumA = sum(aliceSizes)
        sumB = sum(bobSizes)
        
        diff = (sumA - sumB) // 2
        
        setB = set(bobSizes)
        
        for x in aliceSizes:
            y = x - diff
            if y in setB:
                return [x, y]

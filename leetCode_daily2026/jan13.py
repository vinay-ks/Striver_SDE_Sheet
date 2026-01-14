
# Link: https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13

from typing import List

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        # Total area
        total_area = sum(l * l for _, _, l in squares)
        half = total_area / 2.0

        # Binary search bounds
        low = min(y for _, y, _ in squares)
        high = max(y + l for _, y, l in squares)

        # Function to compute area below horizontal line Y
        def area_below(Y: float) -> float:
            area = 0.0
            for _, y, l in squares:
                if Y <= y:
                    continue
                elif Y >= y + l:
                    area += l * l
                else:
                    area += (Y - y) * l
            return area

        # Binary search for Y
        for _ in range(60):  # sufficient for 1e-5 precision
            mid = (low + high) / 2.0
            if area_below(mid) < half:
                low = mid
            else:
                high = mid

        return low

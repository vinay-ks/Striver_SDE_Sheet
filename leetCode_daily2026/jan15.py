# https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/submissions/1885955741/?envType=daily-question&envId=2026-01-15


class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: list[int], vBars: list[int]) -> int:
        def max_gap(bars):
            if not bars:
                return 1
            bars.sort()
            max_streak = cur = 1
            for i in range(1, len(bars)):
                if bars[i] == bars[i-1] + 1:
                    cur += 1
                else:
                    cur = 1
                max_streak = max(max_streak, cur)
            return max_streak + 1  # gap size

        h = max_gap(hBars)
        v = max_gap(vBars)
        side = min(h, v)
        return side * side

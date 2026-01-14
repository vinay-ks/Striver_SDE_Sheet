
# Link: https://leetcode.com/problems/separate-squares-ii/submissions/1885033866/?envType=daily-question&envId=2026-01-14

from typing import List

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        events = []
        xs = set()

        for x, y, l in squares:
            x1, x2 = x, x + l
            events.append((y, 1, x1, x2))
            events.append((y + l, -1, x1, x2))
            xs.add(x1)
            xs.add(x2)

        xs = sorted(xs)
        x_id = {v: i for i, v in enumerate(xs)}

        events.sort()
        n = len(xs)

        count = [0] * (4 * n)
        length = [0] * (4 * n)

        def push_up(node, l, r):
            if count[node] > 0:
                length[node] = xs[r] - xs[l]
            elif l + 1 == r:
                length[node] = 0
            else:
                length[node] = length[node * 2] + length[node * 2 + 1]

        def update(node, l, r, ql, qr, val):
            if qr <= l or r <= ql:
                return
            if ql <= l and r <= qr:
                count[node] += val
                push_up(node, l, r)
                return
            mid = (l + r) // 2
            update(node * 2, l, mid, ql, qr, val)
            update(node * 2 + 1, mid, r, ql, qr, val)
            push_up(node, l, r)

        # -------- First pass: total area --------
        total_area = 0
        prev_y = events[0][0]

        for y, typ, x1, x2 in events:
            dy = y - prev_y
            if dy > 0:
                total_area += length[1] * dy
            update(1, 0, n - 1, x_id[x1], x_id[x2], typ)
            prev_y = y

        half = total_area / 2

        # -------- Second pass: find split --------
        count = [0] * (4 * n)
        length = [0] * (4 * n)

        curr_area = 0
        prev_y = events[0][0]

        for y, typ, x1, x2 in events:
            dy = y - prev_y
            if dy > 0:
                slab = length[1] * dy
                if curr_area + slab >= half:
                    return prev_y + (half - curr_area) / length[1]
                curr_area += slab
            update(1, 0, n - 1, x_id[x1], x_id[x2], typ)
            prev_y = y

        return 0.0


# Link: https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-03

def numOfWays(self, n: int) -> int:
    MOD = 10**9 + 7

    # Base case: n = 1
    two = 6      # ABA patterns
    three = 6    # ABC patterns

    for _ in range(2, n + 1):
        new_two = (two * 3 + three * 2) % MOD
        new_three = (two * 2 + three * 2) % MOD
        two, three = new_two, new_three

    return (two + three) % MOD

# https://leetcode.com/problems/set-matrix-zeroes/
from typing import List

def setZeroes(self, matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    n = len(matrix)
    m = len(matrix[0])

    col0 = False

    for i in range(n):
        if matrix[i][0] == 0:
            col0 = True
            break
    
    for i in range(1, m):
        if matrix[0][i] == 0:
            matrix[0][0] = 0
            break
    
    for i in range(1, n):
        for j in range(1, m):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    
    for i in range(1, n):
        for j in range(1, m):
            if matrix[i][0] == 0 or matrix[0][j] == 0:
                matrix[i][j] = 0
    
    if matrix[0][0] == 0:
        for i in range(m):
            matrix[0][i] = 0
    
    if col0:
        for i in range(n):
            matrix[i][0] = 0

if __name__ == "__main__":
    test_cases = [
        ([[1, 1, 1], [1, 0, 1], [1, 1, 1]], [[1, 0, 1], [0, 0, 0], [1, 0, 1]]),
        ([[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]], [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]])
    ]

    for i, (matrix, expected) in enumerate(test_cases):
        # Deep copy input matrix to preserve original for printing if needed
        input_matrix = [row[:] for row in matrix]
        
        # Call function (passing None for self since it's used as a standalone function here)
        setZeroes(None, input_matrix)
        
        if input_matrix == expected:
            print(f"Test Case {i + 1}: Passed")
        else:
            print(f"Test Case {i + 1}: Failed")
            print(f"  Expected: {expected}")
            print(f"  Got:      {input_matrix}")

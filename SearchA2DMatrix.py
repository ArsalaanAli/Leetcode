class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l = 0
        r = len(matrix)-1
        while l<=r:
            m = (l+r)//2
            if matrix[m][0] == target:
                return True
            if matrix[m][0] > target:
                r = m-1
            else:
                l = m+1
        row = r
        l = 0
        r = len(matrix[row])-1
        while l<=r:
            m = (l+r)//2
            if matrix[row][m] == target:
                return True
            if matrix[row][m] > target:
                r = m-1
            else:
                l = m+1
        return False

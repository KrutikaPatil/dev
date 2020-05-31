class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        n = len(matrix[0])
        # implement 1 D bin search
        if n == 2:
            pass
        
        else:
        # 2D binary search
            row_index = int(m/2)
            col_index = int(n/2)
            current = matrix[row_index][col_index]
            if target > current:
                col_index_increase = 0
                #col_index_increase = int( n - col_index ) / 2)
                col_index += col_index_increase


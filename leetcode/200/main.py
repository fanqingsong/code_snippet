from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row = len(grid)
        col = len(grid[0])

        visited = [[False] * col] * row
        cnt = 0

        def dfs(i, j):
            if i not in range(row):
                return

            if j not in range(col):
                return

            if visited[i][j]:
                return

            if grid[i][j] == '1':
                visited[i][j] = True
                dfs(i, j - 1)
                dfs(i, j + 1)
                dfs(i - 1, j)
                dfs(i + 1, j)

        for i in range(row):
            for j in range(col):
                if visited[i][j]:
                    continue

                # mark the pool elements, and count pool number
                if grid[i][j] == '1':
                    cnt += 1
                    dfs(i, j)

        return cnt



if __name__ == "__main__":
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"]
    ]

    ret = Solution().numIslands(grid)
    print(ret)




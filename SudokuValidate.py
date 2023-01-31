class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        check = set()
        for y in range(9):
            for x in range(9):
                cell = board[y][x]
                if cell == '.':
                    continue
                r = f'{cell} {y} row'
                c = f'{cell} {x} col'
                s = f'{cell} {(y//3)*3 + (x//3)} square'
                if r in check or c in check or s in check:
                    print(r, c, s)
                    return False
                else:
                    check.add(r)
                    check.add(c)
                    check.add(s)
        return True

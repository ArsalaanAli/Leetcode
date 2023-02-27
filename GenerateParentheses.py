class Solution:
    def recurse(self, cur, op, close, done):
        if op == 0 and close == 0:
            done.add(cur)
            return
        if op < close:
            self.recurse(cur+")", op, close-1, done)
        if op > 0:
            self.recurse(cur+"(", op-1, close, done)
    def generateParenthesis(self, n: int) -> List[str]:
        ans = set()
        self.recurse("", n, n, ans)
        return list(ans)
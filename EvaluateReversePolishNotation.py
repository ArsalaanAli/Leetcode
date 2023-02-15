class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t == "+":
                b = stack.pop()
                a = stack.pop()
                stack.append(a+b)
            elif t == "-":
                b = stack.pop()
                a = stack.pop()
                stack.append(a-b)
            elif t == "*":
                b = stack.pop()
                a = stack.pop()
                stack.append(a*b)
            elif t == "/":
                b = stack.pop()
                a = stack.pop()
                stack.append(int(a/b))
            else:
                num = int(t)
                stack.append(num)
        return stack[-1]

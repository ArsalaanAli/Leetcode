class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits)-1
        while True:

            digits[i] += 1
            if digits[i] == 10:
                if i == 0:
                    digits[i] = 1
                    digits.append(0)
                    return digits
                digits[i] = 0
                i-=1
                continue
            return digits

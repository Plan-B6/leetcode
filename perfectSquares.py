class Solution:
    def numSquares(self, n):
        import math

        bound = int(math.sqrt(n))

        if int(math.sqrt(n) + 0.5) ** 2 == n:
            return 1


        isThree = True
        for i in range(0, bound + 1):
            if i > 0:
                x = math.sqrt(n - i ** 2)
                if math.isclose(x, float(math.floor(x))):
                    return 2

            if isThree and i < int(math.sqrt(bound) + 1):
                x = (n / 4 ** i - 7) / 8
                if math.isclose(x, float(math.floor(x))):
                    isThree = False


        return 3 if isThree else 4

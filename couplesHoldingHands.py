class Solution:

    def pair_value(self, val):
        return (val + 1 if val % 2 == 0 else val - 1)
        if (val % 2 == 0):
            return val + 1
        else:
            return val - 1

    def minSwapsCouples(self, row):
        wrong = []
        for index in range(0, len(row), 2):
            i = row[index]
            j = row[index + 1]
            if abs(i - j) != 1 or (i % 2 == 0 and j < i) or (j % 2 == 0 and i < j):
                wrong.append([i, j])

        length = len(wrong)
        if not length:
            return 0

        swaps = 0

        for index, pair in enumerate(wrong):
            if pair[1] == self.pair_value(pair[0]):
                continue
            pos = index
            correct_val = self.pair_value(pair[0])
            while wrong[pos][1] != self.pair_value(wrong[pos][0]):
                correct_val = self.pair_value(wrong[pos][0])
                for index, pair in enumerate(wrong):
                    if pair[0] == correct_val:
                        found = index, 0
                        break
                    if pair[1] == correct_val:
                        found = index, 1
                        break
                wrong[pos][1], wrong[found[0]][found[1]] = wrong[found[0]][found[1]], wrong[pos][1]
                pos = found[0]
                swaps += 1

        return swaps

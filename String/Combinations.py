def combine(n, k):
    result = []
    combo = []

    def backtrack(start):
        if len(combo) == k:
            result.append(combo.copy())
            return
        
        # Prune: ensure enough numbers remain
        for num in range(start, n - (k - len(combo)) + 2):
            combo.append(num)
            backtrack(num + 1)
            combo.pop()

    backtrack(1)
    return result


# Example usage:
print(combine(4, 2))   # [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
print(combine(1, 1))   # [[1]]

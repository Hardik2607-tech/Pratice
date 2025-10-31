def generateParenthesis(n):
    res = []

    def backtrack(current, open_count, close_count):
        # Base case: if the current string is complete
        if len(current) == 2 * n:
            res.append(current)
            return

        # Add '(' if we still have some left
        if open_count < n:
            backtrack(current + "(", open_count + 1, close_count)

        # Add ')' if we have more '(' than ')'
        if close_count < open_count:
            backtrack(current + ")", open_count, close_count + 1)

    backtrack("", 0, 0)
    return res


# Example usage:
print(generateParenthesis(3))

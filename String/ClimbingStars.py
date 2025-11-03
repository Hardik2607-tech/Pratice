def climbStairs(n: int) -> int:
    """
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps.
    Return the number of distinct ways to climb to the top.
    """
    # Base cases
    if n <= 2:
        return n

    # Initialize for the first two steps
    first, second = 1, 2

    # Dynamic programming iteration
    for i in range(3, n + 1):
        first, second = second, first + second

    return second


# ---------------------------
# Test Cases
# ---------------------------
if __name__ == "__main__":
    # Example 1
    n = 2
    print(f"Input: n = {n}")
    print(f"Output: {climbStairs(n)}\n")  # Expected: 2

    # Example 2
    n = 3
    print(f"Input: n = {n}")
    print(f"Output: {climbStairs(n)}\n")  # Expected: 3

    # Additional tests
    n = 4
    print(f"Input: n = {n}")
    print(f"Output: {climbStairs(n)}\n")  # Expected: 5

    n = 5
    print(f"Input: n = {n}")
    print(f"Output: {climbStairs(n)}\n")  # Expected: 8

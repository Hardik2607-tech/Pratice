def convert(s: str, numRows: int) -> str:
    # Base case: if numRows == 1 or string too short, no zigzag
    if numRows == 1 or numRows >= len(s):
        return s

    rows = [''] * numRows
    cur_row = 0
    going_down = False

    for c in s:
        rows[cur_row] += c
        # Change direction at the top or bottom
        if cur_row == 0 or cur_row == numRows - 1:
            going_down = not going_down
        cur_row += 1 if going_down else -1

    return ''.join(rows)


# --- Example Usage ---
if __name__ == "__main__":
    print(convert("PAYPALISHIRING", 3))  # Output: "PAHNAPLSIIGYIR"
    print(convert("PAYPALISHIRING", 4))  # Output: "PINALSIGYAHRPI"
    print(convert("A", 1))               # Output: "A"

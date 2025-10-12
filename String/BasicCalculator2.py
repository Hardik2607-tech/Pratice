# 227. Basic Calculator II
# Given a string s representing an expression, evaluate it and return its value.
# Integer division should truncate toward zero.

def calculate(s: str) -> int:
    stack = []
    num = 0
    sign = '+'
    s = s.replace(' ', '')  # Remove all spaces
    
    for i, ch in enumerate(s):
        if ch.isdigit():
            num = num * 10 + int(ch)
        
        # Process if it's an operator or the last character
        if not ch.isdigit() or i == len(s) - 1:
            if sign == '+':
                stack.append(num)
            elif sign == '-':
                stack.append(-num)
            elif sign == '*':
                stack[-1] *= num
            elif sign == '/':
                # Truncate toward zero
                stack[-1] = int(stack[-1] / num)
            
            sign = ch
            num = 0
    
    return sum(stack)


# -------------------------
# Example Test Cases
# -------------------------
if __name__ == "__main__":
    print(calculate("3+2*2"))        # Output: 7
    print(calculate(" 3/2 "))        # Output: 1
    print(calculate(" 3+5 / 2 "))    # Output: 5
    print(calculate("14-3/2"))       # Output: 13
    print(calculate("100"))          # Output: 100
    print(calculate("0-2147483647")) # Output: -2147483647

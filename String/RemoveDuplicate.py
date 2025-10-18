from collections import Counter

def removeDuplicateLetters(s: str) -> str:
    counter = Counter(s)      # Count how many times each char appears
    stack = []                # Use stack to build result
    seen = set()              # Track chars already in stack

    for c in s:
        counter[c] -= 1       # Decrease remaining count of c
        if c in seen:         # Skip if already in result
            continue
        
        # Ensure lexicographical order by removing larger chars
        # that will appear again later
        while stack and c < stack[-1] and counter[stack[-1]] > 0:
            seen.remove(stack.pop())
        
        stack.append(c)
        seen.add(c)
    
    return ''.join(stack)


# 🧪 Example Tests
print(removeDuplicateLetters("bcabc"))      # Output: "abc"
print(removeDuplicateLetters("cbacdcbc"))   # Output: "acdb"

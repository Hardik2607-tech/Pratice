from collections import deque
from typing import List

def num_matching_subseq(s: str, words: List[str]) -> int:
    # 26 queues, one for each lowercase letter.
    waiting = {chr(ord('a') + i): deque() for i in range(26)}

    # Initialize: put (word, next_index) into the queue for its first char.
    for w in words:
        if not w:  # empty word is a subsequence by definition (count it)
            # If empty words are not part of input per problem, this is harmless.
            # But here we treat them as subsequences.
            waiting['#'] = waiting.get('#', deque())
            waiting['#'].append((w, 0))
            continue
        waiting[w[0]].append((w, 0))

    count = 0
    for ch in s:
        q = waiting[ch]
        # Process current size only — new items appended to this queue (for same char)
        # should wait until later occurrences of ch in s.
        k = len(q)
        for _ in range(k):
            word, idx = q.popleft()
            idx += 1  # we matched ch at position idx
            if idx == len(word):
                count += 1
            else:
                # push to queue for the next required character
                next_char = word[idx]
                waiting[next_char].append((word, idx))
    return count

# Example runs
if __name__ == "__main__":
    print(num_matching_subseq("abcde", ["a","bb","acd","ace"]))        # -> 3
    print(num_matching_subseq("dsahjpjauf", ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]))  # -> 2

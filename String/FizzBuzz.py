from typing import List

def fizzBuzz(n: int) -> List[str]:
    answer = []
    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            answer.append("FizzBuzz")
        elif i % 3 == 0:
            answer.append("Fizz")
        elif i % 5 == 0:
            answer.append("Buzz")
        else:
            answer.append(str(i))
    return answer

# Example usage
print(fizzBuzz(3))   # ["1","2","Fizz"]
print(fizzBuzz(5))   # ["1","2","Fizz","4","Buzz"]
print(fizzBuzz(15))  # ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

from typing import List

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        # Step 1: Sort the array
        nums.sort()
        count = 0
        n = len(nums)
        
        # Step 2: Fix the largest side nums[k]
        for k in range(n - 1, 1, -1):
            i, j = 0, k - 1
            
            # Step 3: Use two pointers to find valid pairs
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    # If nums[i] + nums[j] > nums[k], 
                    # then all pairs from i to j-1 with j are valid
                    count += j - i
                    j -= 1
                else:
                    i += 1
        
        return count


# -----------------------
# Example Test Cases
# -----------------------

if __name__ == "__main__":
    sol = Solution()
    
    nums1 = [2, 2, 3, 4]
    print("Input:", nums1)
    print("Output:", sol.triangleNumber(nums1))  # Expected: 3
    
    nums2 = [4, 2, 3, 4]
    print("\nInput:", nums2)
    print("Output:", sol.triangleNumber(nums2))  # Expected: 4
    
    nums3 = [1, 1, 1, 1]
    print("\nInput:", nums3)
    print("Output:", sol.triangleNumber(nums3))  # Expected: 4

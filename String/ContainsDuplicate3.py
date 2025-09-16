def containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff):
    if valueDiff < 0 or indexDiff <= 0:
        return False

    buckets = {}
    width = valueDiff + 1  # bucket size

    for i, num in enumerate(nums):
        # Find bucket ID
        bucket_id = num // width
        if num < 0:
            bucket_id -= 1

        # Case 1: same bucket → guaranteed difference ≤ valueDiff
        if bucket_id in buckets:
            return True

        # Case 2: check neighboring buckets
        if (bucket_id - 1 in buckets and abs(num - buckets[bucket_id - 1]) <= valueDiff):
            return True
        if (bucket_id + 1 in buckets and abs(num - buckets[bucket_id + 1]) <= valueDiff):
            return True

        # Insert current number into its bucket
        buckets[bucket_id] = num

        # Maintain sliding window of size indexDiff
        if i >= indexDiff:
            old_bucket_id = nums[i - indexDiff] // width
            if nums[i - indexDiff] < 0:
                old_bucket_id -= 1
            del buckets[old_bucket_id]

    return False


# -----------------------
# Example test cases
# -----------------------
if __name__ == "__main__":
    print(containsNearbyAlmostDuplicate([1, 2, 3, 1], 3, 0))       # True
    print(containsNearbyAlmostDuplicate([1, 5, 9, 1, 5, 9], 2, 3)) # False
    print(containsNearbyAlmostDuplicate([1, 2, 3, 1, 2, 3], 2, 0)) # True

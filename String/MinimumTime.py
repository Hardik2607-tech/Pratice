from typing import List

def findMinDifference(timePoints: List[str]) -> int:
    # Pigeonhole: duplicates guarantee 0 because there are only 1440 unique minutes
    if len(timePoints) > 1440:
        return 0

    minutes = []
    for t in timePoints:
        h, m = map(int, t.split(":"))
        minutes.append(h * 60 + m)

    minutes.sort()

    # Adjacent differences
    min_diff = min(minutes[i] - minutes[i-1] for i in range(1, len(minutes)))
    # Wrap-around difference (across midnight)
    min_diff = min(min_diff, 1440 - (minutes[-1] - minutes[0]))
    return min_diff

# quick tests
if __name__ == "__main__":
    print(findMinDifference(["23:59","00:00"]))           # 1
    print(findMinDifference(["00:00","23:59","00:00"]))   # 0

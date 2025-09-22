def isPathCrossing(path: str) -> bool:
    x, y = 0, 0
    visited = {(0, 0)}  # starting point

    for direction in path:
        if direction == 'N':
            y += 1
        elif direction == 'S':
            y -= 1
        elif direction == 'E':
            x += 1
        elif direction == 'W':
            x -= 1

        if (x, y) in visited:
            return True
        visited.add((x, y))

    return False


# ------------------
# Testcases
# ------------------
print(isPathCrossing("NES"))     # False
print(isPathCrossing("NESWW"))   # True
print(isPathCrossing("N"))       # False
print(isPathCrossing("NS"))      # True (back to origin)
print(isPathCrossing("NENWWS"))  # True

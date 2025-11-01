from collections import defaultdict

def calcEquation(equations, values, queries):
    graph = defaultdict(dict)

    # Build the graph
    for (a, b), val in zip(equations, values):
        graph[a][b] = val
        graph[b][a] = 1 / val

    def dfs(start, end, visited):
        if start not in graph or end not in graph:
            return -1.0
        if start == end:
            return 1.0

        visited.add(start)
        for neighbor, value in graph[start].items():
            if neighbor in visited:
                continue
            result = dfs(neighbor, end, visited)
            if result != -1.0:
                return result * value
        return -1.0

    results = []
    for x, y in queries:
        results.append(dfs(x, y, set()))

    return results


# Example usage:
equations = [["a", "b"], ["b", "c"]]
values = [2.0, 3.0]
queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]

print(calcEquation(equations, values, queries))

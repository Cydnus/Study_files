# import sys
# sys.stdin = open("input.txt", "r")


def bfs(graph, start):
    que = []
    que.append(start)
    dist = [-1 for _ in range(len(graph))]
    dist[start] = 0
    while que:
        front = que.pop(0)

        for n in graph[front]:
            if dist[n] == -1:
                dist[n] = dist[front] + 1
                que.append(n)
    return sum(dist)


if __name__ == "__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        lst = list(map(int, input().split()))

        node = lst[0]
        lst = lst[1:]
        graph_matrix = [
            [i for i in lst[j : j + node]] for j in range(0, node**2, node)
        ]
        graph = [[i for i in range(len(row)) if row[i] == 1] for row in graph_matrix]

        result = [bfs(graph, i) for i in range(node)]

        print(f"#{test_case} {min(result)}")

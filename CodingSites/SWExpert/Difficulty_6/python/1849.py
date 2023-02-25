
class Tree:
    def __init__(self, i):
        self.data = [ -1 for _ in range(i)]
        self.dist = [0 for _ in range(i)]
        self.size = i

    def find_root(self, i):
        node = self.data[i]
        if node < 0 :
            return i
        else :
            return self.find_root(node)

    def find_root_dist(self, i):
        node = self.data[i]
        if node < 0 :
            return self.dist[i]
        else :
            return self.find_root_dist(node) + self.dist[i]
    
    def union(self, a, b, w):
        root_a = self.find_root(a)
        root_b = self.find_root(b)
        
        if root_a != root_b :
            if self.data[root_a] < self.data[root_b]:
                self.data[root_a] += self.data[root_b]
                self.data[root_b] = root_a
                dist = self.find_root_dist(a)
                self.dist[b] = dist - w 
            else:
                self.data[root_b] += self.data[root_a]
                self.data[root_a] = root_b
                dist = self.find_root_dist(b)
                self.dist[a] = dist + w

            self.size -= 1


T = int(input())

for test_case in range(1,T+1):
    
    node, work_cnt = map(int, input().split())
    answer = ""

    tree = Tree(node)

    for _ in range(work_cnt):

        work = input().split()
        a = int(work[1])-1
        b = int(work[2])-1
        if work[0] == "!":
            w = int(work[3])
            tree.union(a,b,w)
        elif work[0] == "?":
            if tree.find_root(a) == tree.find_root(b) :
                answer += f"{tree.find_root_dist(a) - tree.find_root_dist(b)} "
            else :
                answer += "UNKNOWN "

    print(f"#{test_case} {answer}")
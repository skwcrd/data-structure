# The node class.
class Node:
    def __init__(self, name = '', h = 0.0):
        self.name = name
        self.h = h

    def __repr__(self):
        return self.name + ', h: ' + str(self.h)

    def __name__(self):
        return self.name

# The linked-list node class.
class LinkNode:
    def __init__(self, node = Node()):
        self.root = node
        self.parent = None
        self.c = 0.0

    def __repr__(self):
        return self.path()
        # return 'path: ' + self.path() + ', h: ' + str(self.getH()) + ', c: ' + str(self.getC()) + ', f: ' + str(self.getF())

    def __name__(self):
        return self.path()

    # Linked node method.
    def connect(self, node = Node(), c = 0.0):
        if self.parent is None:
            self.parent = LinkNode(node)
            self.c = c
        else:
            self.parent.connect(node, c)

    # Copy object to new instance.
    def copy(self):
        tmp = LinkNode(self.root)
        next = self.parent
        prev = self.parent

        tmp.connect(next.root, self.c)

        while next.parent is not None:
            curr = next.parent
            next = next.parent
            tmp.connect(next.root, prev.c)
            prev = curr

        return tmp

    # Searching node in linked-list.
    def hasIn(self, node = Node()):
        if self.root == node:
            return True
        else:
            if self.parent is None:
                return False
            else:
                return self.parent.hasIn(node)

    # Get last node in linked-list.
    def getNodeLast(self):
        if self.parent is None:
            return self.root
        else:
            return self.parent.getNodeLast()

    # Get H value.
    def getH(self):
        if self.parent is None:
            return self.root.h
        else:
            return self.parent.getH()

    # Get C value.
    def getC(self):
        c = self.c

        if self.parent is not None:
            c += self.parent.getC()

        return c

    # Get F value.
    def getF(self):
        return self.getH() + self.getC()

    # Get path node in linked-list.
    def path(self):
        data = self.root.name

        if self.parent is not None:
            data += ' -> '
            data += self.parent.path()

        return data

# The A* searching algorithm method.
def search(graphs = {}, start = Node(), end = Node()):
    graph = {}
    keys = None
    res = None
    result = None
    queues = list()

    graph = graphs.get(start)
    keys = graph.keys()

    for key in keys:
        tmp = LinkNode(start)
        tmp.connect(key, graph.get(key))
        queues.append(tmp)

    for queue in queues:
        if res is None:
            res = queue

        if queue.getF() < res.getF():
            res = queue

    queues.remove(res)

    cp = LinkNode()

    while len(queues) != 0:
        last = res.getNodeLast()

        while last == end:
            if result is None:
                result = res

            if res.getF() < result.getF():
                result = res

            res = None

            for queue in queues:
                if res is None:
                    res = queue

                if queue.getF() < res.getF():
                    res = queue

            queues.remove(res)
            last = res.getNodeLast()

        graph = graphs.get(last)
        keys = graph.keys()

        for key in keys:
            if res.hasIn(key):
                continue
            else:
                cp = res.copy()
                cp.connect(key, graph.get(key))
                queues.append(cp)

        res = None

        for queue in queues:
            if res is None:
                res = queue

            if queue.getF() < res.getF():
                res = queue

        queues.remove(res)

    return result

# Node object for test.
a = Node('Node A', 21.86)
b = Node('Node B', 36.34)
c = Node('Node C', 10.79)
d = Node('Node D', 17.59)
e = Node('Node E', 42.11)
f = Node('Node F', 24.95)
g = Node('Node G', 18.79)
h = Node('Node H', 26.63)
i = Node('Node I', 0.0)
j = Node('Node J', 36.84)
k = Node('Node K', 16.15)
l = Node('Node L', 14.54)
m = Node('Node M', 26.16)
n = Node('Node N', 10.40)
o = Node('Node O', 28.44)
p = Node('Node P', 31.97)
q = Node('Node Q', 18.42)

# Graph mapping node for test.
graphs = {
    a: { d: 7.27, f: 3.09 },
    b: { e: 15.58 },
    c: { i: 10.79, k: 20.22, l: 3.75 , n: 6.93, p: 18.78 },
    d: { a: 7.27, n: 10.92 },
    e: { b: 15.58, j: 8.32 },
    f: { a: 3.09, h: 7.72 },
    g: { m: 7.37 },
    h: { f: 7.72, j: 12.68, n: 22.77 },
    i: { c: 10.79, k: 16.15, n: 10.40, q: 18.42 },
    j: { e: 8.32, h: 12.68, p: 10.0 },
    k: { c: 20.22, i: 16.15, q: 33.45 },
    l: { c: 3.75, o: 13.89 },
    m: { g: 7.37, o: 2.27 },
    n: { c: 6.93, d: 10.92, h: 22.77, i: 10.40 },
    o: { l: 13.89, m: 2.27 },
    p: { c: 18.78, j: 10.0 },
    q: { i: 18.42, k: 33.45 }
}

# Start searching path from start node to end node object.
result_path = search(graphs, j, i)

# Show path result.
print('result : ', result_path)
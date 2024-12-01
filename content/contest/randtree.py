import random

def rand_tree(N, directed = False):
    prufer_sequence = [random.randint(1, N) for _ in  range(N - 2)]
    degrees_needed = {v: 1 for v in range(1, N + 1)}
    for v in prufer_sequence:
        degrees_needed[v] += 1
    g = {v: set() for v in range(1, N + 1)}
    
    # creates tree according to generated prufer sequence
    ones = [v for v in range(1, N + 1) if degrees_needed[v] == 1]
    for v in prufer_sequence:
        u = ones.pop()
        add_edge(g, u, v, directed)
        degrees_needed[u] -= 1
        degrees_needed[v] -= 1
        if degrees_needed[v] == 1:
            ones.append(v)
            
    # adds last edge
    add_edge(g, ones[0], ones[1], directed)
    return g

def add_edge(g, u, v, directed = False):
    g[u].add(v)
    if not directed:
        g[v].add(u)
        

import random

def generate_test():
    n = random.randint(100, 100)
    l = random.randint(1, n)
    r = random.randint(l, n)
    
    # Generate permutation
    p = list(range(1, n + 1))
    random.shuffle(p)
    
    # Create modified array
    a = p.copy()
    for i in range(l-1, r):  # 0-indexed
        a[i] += 1
    
    print(f"Test case: n={n}, l={l}, r={r}")
    print(f"Permutation p: {p}")
    print(f"Modified array a: {a}")
    print(f"Sum(p[1..n]): {sum(p)}")
    print(f"Sum(a[1..n]): {sum(a)}")
    print(f"Difference (should be r-l+1={r-l+1}): {sum(a) - sum(p)}")
    print()
    
    # Simulate interaction
    print("=== Simulating your algorithm ===")
    print(f"Input: 1")
    print(f"Input: {n}")
    print(f"Output: 1 1 {n}")
    print(f"Input: {sum(p)}")
    print(f"Output: 2 1 {n}")
    print(f"Input: {sum(a)}")
    
    d = sum(a) - sum(p)
    print(f"Calculated d = {d}")
    
    # Binary search simulation
    i, j = 1, n
    found_l = 1
    iteration = 0
    
    while i <= j:
        iteration += 1
        m = (i + j) // 2
        p_m = p[m-1]  # 0-indexed
        a_m = a[m-1]
        
        print(f"\nIteration {iteration}: i={i}, j={j}, m={m}")
        print(f"Output: 1 {m} {m}")
        print(f"Input: {p_m}")
        print(f"Output: 2 {m} {m}")
        print(f"Input: {a_m}")
        
        if a_m > p_m:
            found_l = m
            j = m - 1
            print(f"a[{m}] > p[{m}], so found_l={found_l}, j={j}")
        else:
            i = m + 1
            print(f"a[{m}] <= p[{m}], so i={i}")
    
    found_r = found_l + d - 1
    print(f"\nFinal answer: l={found_l}, r={found_r}")
    print(f"Correct answer: l={l}, r={r}")
    print(f"RESULT: {'✓ CORRECT' if found_l == l and found_r == r else '✗ WRONG'}")
    print("="*50)

# Generate multiple test cases
for _ in range(3):
    generate_test()
    print("\n")
import sys
import time
import numpy as np

def benchmark_op(row, col, op, iters):
    min_ = -100000.0
    max_ = 100000.0
    op_times = []
    for _ in range(iters):
        a = np.random.uniform(min_, max_, size=(row, col))
        b = np.random.uniform(min_, max_, size=(row, col))
        if op == '+': # add
            start = time.time()
            c = np.add(a, b)
            op_times.append(time.time() - start)
        elif op == '*': # multiply
            start = time.time()
            c = np.multiply(a, b)
            op_times.append(time.time() - start)
        elif op == '-': # subtract
            start = time.time()
            c = np.subtract(a, b)
            op_times.append(time.time() - start)
        elif op == '/': # divide
            start = time.time()
            c = np.divide(a, b)
            op_times.append(time.time() - start)
        elif op == '.': # dot product
            start = time.time()
            c = np.dot(a, b)
            op_times.append(time.time() - start)
    return np.mean(op_times)

if __name__ == "__main__":
    row = int(sys.argv[1])
    col = int(sys.argv[2])
    iters = int(sys.argv[3])
    ops = ['+', '*', '-', '/', '.']
    print("---------------------------------------")
    print("numpy results:\n")
    for op in ops:
        op_time = benchmark_op(row, col, op, iters)
        print(f"op: {op}\ntime taken: {op_time:.7f} secs\n")
    print("---------------------------------------")

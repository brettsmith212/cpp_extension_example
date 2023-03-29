import time
import fibonacci_recursive

def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

n = 40

start_time = time.time()
c_result = fibonacci_recursive.fib(n)
c_time = time.time() - start_time

start_time = time.time()
py_result = fib(n)
py_time = time.time() - start_time

print(f"C++ result: {c_result}, time: {c_time}")
print(f"Python result: {py_result}, time: {py_time}")
print("C++ extension is", py_time / c_time, "times faster than pure Python.")


import time  # 导入时间模块

def fibonacci(n):
    fib_sequence = [0, 1]  # 初始化斐波那契数列的前两项
    while len(fib_sequence) < n:  # 当数列的长度小于n时
        fib_sequence.append(fib_sequence[-1] + fib_sequence[-2])  # 添加新的一项，该项是数列最后两项的和
    return fib_sequence  # 返回斐波那契数列

N = 10  # 定义要打印的斐波那契数列的项数

start_time = time.time()  # 获取当前时间（以秒为单位）
print(fibonacci(N))  # 打印斐波那契数列的前N项
end_time = time.time()  # 获取当前时间（以秒为单位）

print("运行时间：", end_time - start_time, "秒")  # 打印函数的运行时间

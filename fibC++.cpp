#include<iostream>
#include<vector>
#include<chrono>

int main() {
    int N;
    std::cout << "请输入一个整数N: ";  // 提示用户输入一个整数N
    std::cin >> N;  // 从标准输入读取整数N

    std::vector<int> fib_sequence{ 0, 1 };  // 初始化斐波那契数列的前两项

    auto start = std::chrono::high_resolution_clock::now();  // 获取当前时间

    while (fib_sequence.size() < N) {  // 当数列的长度小于N时
        fib_sequence.push_back(fib_sequence[fib_sequence.size() - 1] + fib_sequence[fib_sequence.size() - 2]);  // 添加新的一项，该项是数列最后两项的和
    }

    auto stop = std::chrono::high_resolution_clock::now();  // 获取当前时间

    std::cout << "斐波那契数列的前" << N << "项是：";  // 打印提示信息
    for (int i = 0; i < N; i++) {  // 遍历斐波那契数列的前N项
        std::cout << fib_sequence[i] << " ";  // 打印每一项
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);  // 计算运行时间

    std::cout << "\n运行时间： " << duration.count() << "微秒" << std::endl;  // 打印运行时间

    return 0;  // 程序正常结束
}

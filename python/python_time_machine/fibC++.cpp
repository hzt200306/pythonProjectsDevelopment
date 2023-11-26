#include<iostream>
#include<vector>

int main() {
    // 请求输入斐波那契数列的项数
    int N;
    std::cout << "请输入一个数字N: ";
    std::cin >> N;

    // 创建一个向量来存储斐波那契数列
    std::vector<int> fib_sequence{0, 1};

    // 循环计算斐波那契数列直到我们有足够的项数
    while (fib_sequence.size() < N) {
        fib_sequence.push_back(fib_sequence[fib_sequence.size() - 1] + fib_sequence[fib_sequence.size() - 2]);
    }

    // 打印斐波那契数列
    std::cout << "斐波那契数列的前" << N << "项是：";
    for (int i = 0; i < N; i++) {
        std::cout << fib_sequence[i] << " ";
    }

    return 0;
}

#include<iostream>
#include<vector>

int main() {
    int N;
    std::cout << "请输入一个整数N: ";
    std::cin >> N;

    std::vector<int> fib_sequence{0, 1};

    while (fib_sequence.size() < N) {
        fib_sequence.push_back(fib_sequence[fib_sequence.size() - 1] + fib_sequence[fib_sequence.size() - 2]);
    }

    std::cout << "斐波那契数列的前" << N << "项是：";
    for (int i = 0; i < N; i++) {
        std::cout << fib_sequence[i] << " ";
    }

    return 0;
}

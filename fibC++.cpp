#include<iostream>
#include<vector>

int main() {
    int N;
    std::cout << "������һ������N: ";
    std::cin >> N;

    std::vector<int> fib_sequence{0, 1};

    while (fib_sequence.size() < N) {
        fib_sequence.push_back(fib_sequence[fib_sequence.size() - 1] + fib_sequence[fib_sequence.size() - 2]);
    }

    std::cout << "쳲��������е�ǰ" << N << "���ǣ�";
    for (int i = 0; i < N; i++) {
        std::cout << fib_sequence[i] << " ";
    }

    return 0;
}

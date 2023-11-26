#include<iostream>
#include<vector>

int main() {
    // ��������쳲��������е�����
    int N;
    std::cout << "������һ������N: ";
    std::cin >> N;

    // ����һ���������洢쳲���������
    std::vector<int> fib_sequence{0, 1};

    // ѭ������쳲���������ֱ���������㹻������
    while (fib_sequence.size() < N) {
        fib_sequence.push_back(fib_sequence[fib_sequence.size() - 1] + fib_sequence[fib_sequence.size() - 2]);
    }

    // ��ӡ쳲���������
    std::cout << "쳲��������е�ǰ" << N << "���ǣ�";
    for (int i = 0; i < N; i++) {
        std::cout << fib_sequence[i] << " ";
    }

    return 0;
}

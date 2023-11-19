#include<iostream>
#include<vector>
#include<chrono>

int main() {
    int N;
    std::cout << "������һ������N: ";  // ��ʾ�û�����һ������N
    std::cin >> N;  // �ӱ�׼�����ȡ����N

    std::vector<int> fib_sequence{ 0, 1 };  // ��ʼ��쳲��������е�ǰ����

    auto start = std::chrono::high_resolution_clock::now();  // ��ȡ��ǰʱ��

    while (fib_sequence.size() < N) {  // �����еĳ���С��Nʱ
        fib_sequence.push_back(fib_sequence[fib_sequence.size() - 1] + fib_sequence[fib_sequence.size() - 2]);  // ����µ�һ������������������ĺ�
    }

    auto stop = std::chrono::high_resolution_clock::now();  // ��ȡ��ǰʱ��

    std::cout << "쳲��������е�ǰ" << N << "���ǣ�";  // ��ӡ��ʾ��Ϣ
    for (int i = 0; i < N; i++) {  // ����쳲��������е�ǰN��
        std::cout << fib_sequence[i] << " ";  // ��ӡÿһ��
    }

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);  // ��������ʱ��

    std::cout << "\n����ʱ�䣺 " << duration.count() << "΢��" << std::endl;  // ��ӡ����ʱ��

    return 0;  // ������������
}

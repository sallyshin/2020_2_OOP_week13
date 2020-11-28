#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>
template <typename ForwardIterator, typename Compare> 
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {
			if (comp(*cur, *prev)) { 
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}
	}
}

class compGreater { // ��������
public:
	bool operator()(int num1, int num2) {
		return num1 > num2;
	}
 };

class compLess { // ��������
public:
	bool operator()(int num1, int num2) {
		return num1 < num2;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "�������� ����" << std::endl;
	compLess compLess; //Functor ����
	bubble_sort(values.begin(), values.end(), compLess);
	//��� ����Ʈ
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	std::cout << "�������� ����" << std::endl;
	compGreater compGreater; //Functor ����
	bubble_sort(values.begin(), values.end(), compGreater);
	//��� ����Ʈ
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	//getchar();
}
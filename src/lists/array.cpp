//
// Created by William Henderson on 2024-07-07.
//

#include <iostream>

template<class T, std::size_t N>
struct Array {
private:
	using value_type = T;
	using size_type = std::size_t;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;

	void error() const {
		throw std::out_of_range{"array out of range"};
	}

	value_type data[N];

public:
	constexpr bool empty() {
		return N == 0;
	}
	constexpr size_type size() {
		return N;
	}
	constexpr size_type max_size() {
		return N;
	}
	const_reference at(size_type pos) {
		if (pos >= size()) {
			this->error();
		}
		return data[pos];
	}
	reference operator[](size_type pos) {
		return data[pos];
	}
	const_reference operator[](size_type pos) const {
		return data[pos];
	}
	value_type front() {
		return data[0];
	}
	value_type back() {
		return data[N-1];
	}
	pointer begin() {
		return data;
	}
	pointer end() {
		return begin() + N;
	}
	const_pointer begin() const {
		return data;
	}
	const_pointer end() const {
		return begin() + N;
	}
	void print() {
		std::cout << "{ ";
		for (int i = 0; i < size(); i++) {
			std::cout << at(i);
		}
		std::cout << " }";
	}
};
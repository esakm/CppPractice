#pragma once


template <class K, class V> class Dictionary {

private:
	const int MAGIC_NUMBER = 70529;
	std::vector<T>* buckets;

	Dictionary() {
		array_size = 1;
		buckets = new std::vector<V>(1);
	}
};
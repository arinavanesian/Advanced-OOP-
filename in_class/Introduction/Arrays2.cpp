#include <iostream>
#include <array>
#include <algorithm> // For std::swap

// Function prototypes
void print1D(int a[], int size);
void flip(int a[], int size);
void flip_ptr(int a[], int size);
void shift(int a[], int size, int offset);
int* search_bin(int sorted[], int size, const int& lookup_value);

int main() {
    std::array<int, 5> a = {1, 2, 3, 4, 5}; // Use std::array with explicit initialization
    print1D(a.data(), a.size());

    flip(a.data(), a.size());
    print1D(a.data(), a.size());

    flip_ptr(a.data(), a.size());
    print1D(a.data(), a.size());

    int x = 2;
    int* p = search_bin(a.data(), a.size(), x + 2);
    if (p) {
        std::cout << (p - a.data()) << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    shift(a.data(), a.size(), 8);
    print1D(a.data(), a.size());

    return 0;
}

void print1D(int a[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void flip(int a[], int size) {
    for (int i = 0; i < size / 2; i++) {
        std::swap(a[i], a[size - i - 1]);
    }
}

void flip_ptr(int a[], int size) {
    for (int* left = a, *right = a + size - 1; left < right; left++, right--) {
        std::swap(*left, *right);
    }
}

void shift(int a[], int size, int offset) {
    offset %= size;

    flip_ptr(a, offset);
    flip_ptr(a + offset, size - offset);
    flip_ptr(a, size);
}

int* search_bin(int sorted[], int size, const int& lookup_value) {
    if (size == 0) {
        return nullptr;
    }

    int half_size = size / 2;
    if (lookup_value == sorted[half_size]) {
        return sorted + half_size;
    } else if (lookup_value < sorted[half_size]) {
        return search_bin(sorted, half_size, lookup_value);
    } else {
        return search_bin(sorted + half_size + 1, size - half_size - 1, lookup_value);
    }
}
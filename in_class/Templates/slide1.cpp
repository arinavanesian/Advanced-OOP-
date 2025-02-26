#include <iostream>

template <typename T>
void print(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...); 
    // Recursive call with remaining arguments
}

int main() {
    print(1, 2.5, "Hello", 'c');
    return 0;
}

#include <iostream>
template <typename T>
void print(T t) {
    std::cout << t << std::endl;
}
#include <iostream>
template <typename T>
class Printer {
public:
    static void print(T value) {
        std::cout << "Generic: " << value << std::endl;
    }
};

    
// Specialized version for `std::string`
template <>
class Printer<std::string> {
public:
    static void print(std::string value) {
        std::cout << "String specialization: " << value << std::endl;
    }
};    
int main() {
    Printer<int>::print(10);
    Printer<std::string>::print("Hello");
    return 0;
}

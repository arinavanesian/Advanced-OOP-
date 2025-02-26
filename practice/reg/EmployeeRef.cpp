#include <iostream>

int main() {
    std::cout<<"\n Storing the address of the variable\n"<<std::endl;
    int original = 100;
    int* original_ref = &original; // Store the address of original

    std::cout << "Original: " << original << std::endl;
    std::cout << "Pointer Reference: " << *original_ref << std::endl; // Dereference to get value

    int new_value = 200;
    *original_ref = new_value; // Modify original using pointer

    std::cout << "Original: " << original << std::endl; // Changes to 200
    std::cout << "New Value: " << new_value << std::endl;
    std::cout << "Pointer Reference: " << *original_ref << std::endl; // Also 200
    std::cout<<"\n Creating a copy of the variable\n"<<std::endl;
    int origin = 100;
    int origin_ref = origin; // This creates a copy, not a reference.

    std::cout << "Original: " << origin << std::endl;
    std::cout << "Reference (copy): " << origin_ref << std::endl;

    int new_val = 200;
    origin_ref = new_value; // This only changes original_ref, not original.

    std::cout << "Original: " << origin << std::endl; // Remains 100
    std::cout << "New Value: " << new_val << std::endl;
    std::cout << "Reference (copy): " << origin_ref << std::endl; // Becomes 200

    return 0;
}

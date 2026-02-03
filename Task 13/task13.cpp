#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>

/* TASK 1: Create and Use unique_ptr */
std::unique_ptr<int> create_unique(int value) {
    return std::make_unique<int>(value);
}

/* TASK 2: Transfer Ownership with unique_ptr */
std::unique_ptr<int> add_hundred(std::unique_ptr<int> ptr) {
    if(ptr) *ptr += 100;
    return ptr;
}

/* TASK 3: Create Dynamic Array with unique_ptr */
std::unique_ptr<double[]> create_array(std::size_t size) {
    auto arr = std::make_unique<double[]>(size);
    for(std::size_t i = 0; i < size; ++i)
        arr[i] = i * 2.5;
    return arr;
}

/* TASK 4: Shared Ownership with shared_ptr */
std::vector<std::shared_ptr<int>> create_shared(int value) {
    auto ptr = std::make_shared<int>(value);
    return {ptr, ptr, ptr};
}

/* TASK 5: Custom strlen Implementation */
int my_string_length(const char* str) {
    const char* ptr = str;
    while(*ptr) ++ptr;
    return ptr - str;
}

/* TASK 6: Custom strcpy Implementation */
void my_string_copy(char* destination, const char* source) {
    while(*source) {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';
}

/* TASK 7: Custom strcat Implementation */
void my_string_concat(char* destination, const char* source) {
    while(*destination) ++destination; // move to end of destination
    while(*source) {
        *destination = *source;
        ++destination;
        ++source;
    }
    *destination = '\0';
}

/* TASK 8: Count Words in C-String */
int count_words(const char* str) {
    int count = 0;
    bool in_word = false;
    while(*str) {
        if(*str != ' ' && !in_word) {
            in_word = true;
            ++count;
        } else if(*str == ' ') {
            in_word = false;
        }
        ++str;
    }
    return count;
}

/* MAIN FUNCTION  */
int main() {
    // TASK 1
    std::cout << "TASK 1: Create unique_ptr\n";
    auto u_ptr = create_unique(42);
    std::cout << "Value: " << *u_ptr << "\n\n";

    // TASK 2
    std::cout << "TASK 2: Transfer Ownership\n";
    auto moved_ptr = add_hundred(std::move(u_ptr));
    std::cout << "Value after adding 100: " << *moved_ptr << "\n\n";

    // TASK 3
    std::cout << "TASK 3: Create Dynamic Array\n";
    auto arr = create_array(4);
    for(int i = 0; i < 4; ++i) std::cout << arr[i] << " ";
    std::cout << "\n\n";

    // TASK 4
    std::cout << "TASK 4: Shared Ownership\n";
    auto shared_vec = create_shared(99);
    for(auto& sptr : shared_vec) std::cout << *sptr << " ";
    std::cout << "\nUse count: " << shared_vec[0].use_count() << "\n\n";

    // TASK 5
    std::cout << "TASK 5: Custom strlen\n";
    const char* test_str = "Hello World";
    std::cout << "Length: " << my_string_length(test_str) << "\n\n";

    // TASK 6
    std::cout << "TASK 6: Custom strcpy\n";
    char dest1[50];
    my_string_copy(dest1, "Copy this string");
    std::cout << "Copied: " << dest1 << "\n\n";

    // TASK 7
    std::cout << "TASK 7: Custom strcat\n";
    char dest2[50] = "Hello";
    my_string_concat(dest2, " World");
    std::cout << "Concatenated: " << dest2 << "\n\n";

    // TASK 8
    std::cout << "TASK 8: Count Words\n";
    const char* sentence = "Hello  World  in C++";
    std::cout << "Word count: " << count_words(sentence) << "\n";

    return 0;
}

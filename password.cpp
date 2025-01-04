#include <iostream>
#include <ctime>

int main() {
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!#$%&()*+";

    std::cout << "Welcome to the C++ Password Generator!" << std::endl;

    int nr_letters, nr_symbols, nr_numbers;
    std::cout << "How many letters would you like in your password?" << std::endl;
    std::cin >> nr_letters;
    std::cout << "How many symbols would you like?" << std::endl;
    std::cin >> nr_symbols;
    std::cout << "How many numbers would you like?" << std::endl;
    std::cin >> nr_numbers;

    const int max_password_length = 100;
    char password[max_password_length];
    int password_length = 0;

    srand(time(0));

    for (int i = 0; i < nr_letters; ++i) {
        password[password_length++] = letters[rand() % 52];
    }
    for (int i = 0; i < nr_numbers; ++i) {
        password[password_length++] = numbers[rand() % 10];
    }
    for (int i = 0; i < nr_symbols; ++i) {
        password[password_length++] = symbols[rand() % 10];
    }

    // Shuffle the password array
    for (int i = 0; i < password_length; ++i) {
        int random_index = rand() % password_length;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    std::cout << "Your password is: ";
    for (int i = 0; i < password_length; ++i) {
        std::cout << password[i];
    }
    std::cout << std::endl;

    return 0;
}

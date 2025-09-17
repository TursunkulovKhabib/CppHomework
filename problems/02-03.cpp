#include <iostream>

int main() {

    std::cout << "Input a character with ASCII-code from 32 to 127" << std::endl;

    char x;

    std::cin >> x;

    switch(x) {
        case 'A' ... 'Z':
            std::cout << "Сapital letter" << std::endl;
            break;
        case 'a' ... 'z':
            std::cout << "Lowercase letters" << std::endl;
            break;
        case '0' ... '9':
            std::cout << "Digit" << std::endl;
            break;
        case ',':
            std::cout << "Punctuation mark" << std::endl;
            break;
        case '.':
            std::cout << "Punctuation mark" << std::endl;
            break;
        case '?':
            std::cout << "Punctuation mark" << std::endl;
            break;
        case '!':
            std::cout << "Punctuation mark" << std::endl;
            break;
        case '"':
            std::cout << "Punctuation mark" << std::endl;
            break;
        case ';':
            std::cout << "Punctuation mark" << std::endl;
            break;
        case ':':
            std::cout << "Punctuation mark" << std::endl;
            break;
        default:
            std::cout << "Other types" << std::endl;
            break;
    }

    return 0;
}

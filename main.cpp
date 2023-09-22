#include <iostream>
#include "FloatCell.h"

int main() {
    FloatCell variable;
    float n;
    std::cout << "enter a number" << std::endl;
    std::cin >> n;

    variable.setValue(n);

    std::cout << "the value is: " << variable.getValue();

}
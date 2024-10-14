//
// Created by MaxPlays on 13/10/2024.
//

#include <vector>

int main() {
    std::vector<int> base {1, 2, 3, 4};
    std::vector<int> base2 {5, 6, 7, 8};

    base2 = base;

    base2.push_back(10);

    return 0;
}

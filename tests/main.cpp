#include <iostream>
namespace alpha {
    int i = 4;
}
namespace beta {
    int i = alpha::i + 1;
}

int main() {
    try {
        throw "5";
    } catch (int e) {
        using namespace alpha;
        std::cout << "Exception! " << "Error code " << e << " (" << i << ")" << std::endl;
    } catch (char const* e) {
        using namespace beta;
        std::cout << "Exception! " << "Error code " << e << " (" << i << ")" << std::endl;
    }
}
#include <iostream>

void swapby_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapby_ptr(int *a, int *b) {
    if (a == nullptr || b == nullptr) return; // Null safety check
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x = 5, y = 10;

    std::cout << "Original values: x = " << x << ", y = " << y << "\n";

    // Testing Pass by Reference
    swapby_ref(x, y);
    std::cout << "After swapby_ref: x = " << x << ", y = " << y << "\n";

    // Testing Pass by Pointer (must pass memory addresses using &)
    swapby_ptr(&x, &y);
    std::cout << "After swapby_ptr: x = " << x << ", y = " << y << "\n";

    return 0;
}
#include "lightning_matrix.h"

int main() {
    unsigned long long a = rorq(10, 16);
    unsigned long long b = rolq(10, 48);
    int result = a == b;
    a++;
}

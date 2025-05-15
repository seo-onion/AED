#include <iostream>
#include <xxhash.h>
#include <cstring>

int main() {
    const char* data = "Hello, World!";
    size_t len = strlen(data);

    // Calcular el hash
    unsigned long long hash = XXH64(data, len, 0);

    std::cout << "Hash: " << hash << std::endl;
    
    return 0;
}

#include <iostream>
#include <random>
#include <string>
#include <vector>

// Function to generate random UInt16 number
std::uint16_t generateRandomNumber() {
    static std::mt19937 generator(std::random_device{}()); // Initialize Mersenne Twister PRNG
    std::uniform_int_distribution<std::uint16_t> distribution(0, 65535); // Range: 0-65535
    return distribution(generator);
}

// Function to generate random UInt32 number
std::uint32_t generateRandomNumber32() {
    static std::mt19937 generator(std::random_device{}); // Initialize Mersenne Twister PRNG
    std::uniform_int_distribution<std::uint32_t> distribution(0, 4294967295U); // Range: 0-4294967295U
    return distribution(generator);
}

int main() {
    std::vector<char> randomBytes;
    
    std::cout << "Generating random values:" << std::endl;
    std::uint32_t t1 = generateRandomNumber32();
    std::uint16_t t2 = generateRandomNumber();
    std::uint32_t u1 = generateRandomNumber32();
    std::uint16_t u2 = generateRandomNumber();

    std::cout << "Generated random values:" << std::endl;
    std::cout << "UInt32: " << std::hex << t1 << std::dec << std::endl;
    std::cout << "UInt16: " << std::hex << static_cast<unsigned int>(t2) << std::dec << std::endl;
    std::cout << "UInt32: " << std::hex << u1 << std::dec << std::endl;
    std::cout << "UInt16: " << std::hex << static_cast<unsigned int>(u2) << std::dec << std::endl;

    std::cout << "\nGenerating fixed and random bytes:" << std::endl;
    std::vector<char> allocationBytes = {"0E", "B6", "0A", "8E", "E9", "6F", "0E", "A9"};
    allocationBytes.insert(allocationBytes.end(), begin(std::to_string(static_cast<int>(t1)).begin()), end(std::to_string(static_cast<int>(t1)).end()));
    allocationBytes.insert(allocationBytes.end(), begin(std::to_string(static_cast<int>(t2)).begin()), end(std::to_string(static_cast<int>(t2)).end()));
    allocationBytes.push_back('E');
    allocationBytes.insert(allocationBytes.end(), begin("4C"), end("4C")); // CSID prefix

    std::copy(begin(allocationBytes), end(allocationBytes), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

//This program prints 1 if the number of set bits in the QWord is odd
//else it returns 0

#include <iostream>
#include <bitset>
#include <unordered_map>
#include <utility>

std::unordered_map<std::bitset<4>, bool> a;

bool isOdd(unsigned int input)
{
	unsigned int count;
	std::bitset<64> ba(input);
	for (count = 0; input; count ^= 1)
	{
		input &= input - 1;
	}
	return (count % 2);
}

int main()
{
	for (unsigned int i = 0; i < 16; ++i)
	{
		a.insert(std::pair<std::bitset<4>, bool>(std::bitset<4>(i), isOdd(i)));
	}
	unsigned int mask = 0b1111;
	unsigned int step = 4;
	unsigned int input;
	std::cin >> input;
	std::cout << (a.find(input & mask)->second ^
		a.find((input >> step) & mask)->second ^
		a.find((input >> (step * 2)) & mask)->second ^
		a.find((input >> (step * 3)) & mask)->second);
	return 0;
}
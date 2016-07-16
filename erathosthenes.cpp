#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <memory>
#include <string.h>

using namespace std;

typedef unsigned int uint;
uint n, MAX_N, TEST;

template <typename T>
void erathosthenes(T& list)
{
	list[0] = false;
	list[1] = false;
	uint sqrtn = uint(sqrt(n));
	for (uint i = 2; i <= sqrtn; i++)
	{
		if (list[i])
			// i 의 배수 j 들에 대해 isPrime[j]=false로 둔다.
			// i*i 미만의 배수는 이미 지워졌으므로 신경쓰지 않는다.
			for (uint j = i*i; j <= n; j+= i)
				list[j] = false;
	}
}

int vector_bool()
{
	vector<bool> list(MAX_N, true);

	erathosthenes(list);

	return list[TEST];
}

int array_bool()
{
	auto list = make_unique<bool[]>(MAX_N);
	for (uint i = 0; i < MAX_N; i++)
		list[i] = true;

	erathosthenes(list);

	return list[TEST];
}

int array_char()
{
	auto list = make_unique<char[]>(MAX_N);
	memset(list.get(), 255, sizeof(MAX_N));
	for (uint i = 0; i < MAX_N; i++)
		list[i] = true;

	erathosthenes(list);

	return list[TEST];
}

int bitmask()
{
	// :!g++ -o bin/%< % --std=c++14 -O2 -Wl,-stack_size -Wl,0x10000000 && /usr/bin/time -l bin/%<
	unsigned char sieve[(MAX_N + 7)/8];
	
	auto isPrime = [&sieve](uint k) -> bool {
		return sieve[k >> 3] & (1 << (k & 7));
	};

	auto setComposite = [&sieve](int k) {
		sieve[k >> 3] &= ~(1 << (k & 7));
	};

	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	uint sqrtn = uint(sqrt(n));
	for (uint i = 2; i <= sqrtn; i++)
		if (isPrime(i))
			for (uint j = i*i; j <= n; j += i)
				setComposite(j);

	return isPrime(TEST);
}

int main()
{
	// MAX_N = numeric_limits<decltype(MAX_N)>::max();
	MAX_N = 1 << 28; // 268435456
	cout << "MAX_N : " << MAX_N << endl;
	n = MAX_N - 1;
	TEST = 10003159;

	// note 2^32 bit == 536.8 mb
	// cout << vector_bool() << endl; // 34,271,232 kb  | 1.4 sec
	// cout << array_bool() << endl;  // 269,148,160 kb | 3.0 sec
	// cout << array_char() << endl;  // 269,135,872 kb | 2.8 sec
	// cout << bitmask() << endl;     // 34,254,848 kb  | 1.32 sec

	return 0;
}

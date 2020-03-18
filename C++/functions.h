#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

bool is_prime(long long);
bool is_prime(long long, std::vector<long long>);
std::vector<long long> prime_sieve_under(long long);
std::vector<long long> prime_sieve_first(int);
bool is_palindrome(long long);
int num_digits(long long);
std::vector<long long> prime_factorization(long long);

#endif

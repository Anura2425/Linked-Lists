#include "linked_list.hpp"
#include <iostream>

int main(){
    /* Question 1:
        Prime numbers are integer values that are not divisible by positive integers other than 1 and
        the number itself. Please create a linked list and fill it with the key value pairs that represent
        the first 20 prime numbers as keys and their multiplicative inverses (for prime p, 1/p is the
        multiplicative inverse) as the value. What is the sum of the values of these first twenty
        multiplicative inverses?
    */

    // Step 0: Print Banner for question number
    std::cout << " ______________ " << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|  QUESTION 1  |" << std::endl;
    std::cout << "|______________|" << std::endl;
    std::cout << std::endl;

    // Step 1: Create List of first 20 Primes and their Multiplicative Inverses
    LinkedList primes;
    primes.push_back(2, 1.0/2.0);
    primes.push_back(3, 1.0/3.0);
    primes.push_back(5, 1.0/5.0);
    primes.push_back(7, 1.0/7.0);
    primes.push_back(11, 1.0/11.0);
    primes.push_back(13, 1.0/13.0);
    primes.push_back(17, 1.0/17.0);
    primes.push_back(19, 1.0/19.0);
    primes.push_back(23, 1.0/23.0);
    primes.push_back(29, 1.0/29.0);
    primes.push_back(31, 1.0/31.0);
    primes.push_back(37, 1.0/37.0);
    primes.push_back(41, 1.0/41.0);
    primes.push_back(43, 1.0/43.0);
    primes.push_back(47, 1.0/47.0);
    primes.push_back(53, 1.0/53.0);
    primes.push_back(59, 1.0/59.0);
    primes.push_back(61, 1.0/61.0);
    primes.push_back(67, 1.0/67.0);
    primes.push_back(71, 1.0/71.0);

    // Sum all multiplicative inverse values
    double sum_mult_inverses = 0.0;

    sum_mult_inverses = 
    primes.search(2) + 
    primes.search(3) + 
    primes.search(5) + 
    primes.search(7) + 
    primes.search(11) +
    primes.search(13) +
    primes.search(17) +
    primes.search(19) +
    primes.search(23) +
    primes.search(29) +
    primes.search(31) +
    primes.search(37) +
    primes.search(41) +
    primes.search(43) +
    primes.search(47) +
    primes.search(53) +
    primes.search(59) +
    primes.search(61) +
    primes.search(67) +
    primes.search(71);

    // Step 3: Print answer to terminal
    std::cout << "Sum of the first 20 Prime Numbers Multiplicative Inverses:\n\n" << sum_mult_inverses << " (Approximately)" << std::endl;
    


    // Question 2:

    // Step 0: Print Banner for question number
    std::cout << std::endl;
    std::cout << " ______________ " << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|  QUESTION 2  |" << std::endl;
    std::cout << "|______________|" << std::endl;
    std::cout << std::endl;

    // Step 1:



    // Question 3:

    // Step 0: Print Banner for question number
    std::cout << std::endl;
    std::cout << " ______________ " << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|  QUESTION 3  |" << std::endl;
    std::cout << "|______________|" << std::endl;
    std::cout << std::endl;

    // Step 1:
    return 0;
}
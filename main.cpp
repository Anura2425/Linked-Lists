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
    


    /* Question 2
    Years are calculated many ways. Using the Intercalation and Astronomical years sections of the year wikipedia page. Create a key value pair for each method of calculation that has an equivalent number of days starting from the index 1. Example: Julian calendar would be stored using the key value pair (1, 365.25) because it is the first in these sections that has an equivalent day calculation). What is the difference between the largest and smallest calculation in days when talking about 10,000 years?    
    */

    // Step 0: Print Banner for question number
    std::cout << std::endl;
    std::cout << " ______________ " << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|  QUESTION 2  |" << std::endl;
    std::cout << "|______________|" << std::endl;
    std::cout << std::endl;

    // Step 1: Create list with the numbers of days there are in a year using different calendars, using the keys to index them starting at 1
    LinkedList years;
    years.push_back(1, 365.25); // Julian calendar/Julian year
    years.push_back(2, 365.2425); // Gregorian calendar
    years.push_back(3, 365.256363004); // sidereal year
    years.push_back(4, 365.242); // tropical year
    years.push_back(5, 365.259636); // anomolistic year
    years.push_back(6, 346.620075883); // Draconic year
    years.push_back(7, 411.78443029); // full moon cyle
    years.push_back(8, 354.37); // lunar year
    years.push_back(9, 365.0); // vague year
    years.push_back(10, 365.2568983); // Gaussian year

    // Step 2: Compare all values multiplied by 10,000 to find the max and min number of days for 10,000 years
    double max_val = years.search(1)*10000;
    double min_val = years.search(1)*10000;
    int max_key = 1;
    int min_key = 1;
    int curr_key = 1;
    double curr_val;
    for (Node* iter = years.get_head(); iter != nullptr; iter = iter->next) {
        curr_val = years.search(curr_key)*10000;
        if (curr_val > max_val) {
            max_val = curr_val;
            max_key = curr_key;
        }
        else if (curr_val < min_val) {
            min_val = curr_val;
            min_key = curr_key;
        }
        curr_key++;
    }

    // Step 3: Output the max and min number of days for 10,000 years and their calculated difference
    std::cout << "Maximum number of days for 10,000 years: " << max_val << " days with calendar " << max_key << std::endl;
    std::cout << "Minimum number of days for 10,000 years: " << min_val << " days with calendar " << min_key << std::endl;
    std::cout << "Difference between maximum and minimum number of days for 10,000 years: " << max_val - min_val << " days" << std::endl;


    // Question 3:

    // Step 0: Print Banner for question number
    std::cout << std::endl;
    std::cout << " ______________ " << std::endl;
    std::cout << "|              |" << std::endl;
    std::cout << "|  QUESTION 3  |" << std::endl;
    std::cout << "|______________|" << std::endl;
    std::cout << std::endl;

    double compute_total_cost() {
    LinkedList nasdaqList;

    // Top 15 companies by market cap and their stock prices on March 15, 2025
    nasdaqList.push_back(1, 247.10);  // Apple
    nasdaqList.push_back(2, 130.28);  // NVIDIA
    nasdaqList.push_back(3, 404.00);  // Microsoft
    nasdaqList.push_back(4, 212.71);  // Amazon
    nasdaqList.push_back(5, 181.19);  // Alphabet
    nasdaqList.push_back(6, 668.13);  // Meta
    nasdaqList.push_back(7, 330.53);  // Tesla
    nasdaqList.push_back(8, 62.59);   // PayPal
    nasdaqList.push_back(9, 19.74);   // Intel
    nasdaqList.push_back(10, 93.40);  // AMD
    nasdaqList.push_back(11, 57.33);  // Cisco
    nasdaqList.push_back(12, 139.25); // Qualcomm
    nasdaqList.push_back(13, 352.47); // Adobe
    nasdaqList.push_back(14, 285.98); // Amgen
    nasdaqList.push_back(15, 554.18); // Regeneron

    double total_cost = 0.0;
    int n = nasdaqList.size();

    for (int i = 0; i < n; ++i) {
        Node* node = nasdaqList.at(i);
        total_cost += node->value * 3;
    }

    return total_cost;
}
    double total = compute_total_cost();
    std::cout << "Total cost to buy 3 shares of each top 15 NASDAQ company: $" << total << std::endl;
    
    return 0;
}

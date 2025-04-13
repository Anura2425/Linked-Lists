#include <iostream>

class LinkedList{
    struct Node {
        int x;
        Node *next;
    };

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

int main() {
    double total = compute_total_cost();
    std::cout << "Total cost to buy 3 shares of each top 15 NASDAQ company: $" << total << std::endl;
    return 0;
}

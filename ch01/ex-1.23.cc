// counter books
#include<iostream>
#include "Sales_item.h"

int main() {
    Sales_item currItem, item;
    int cnt = 1;
    if(std::cin >> currItem) {
        int cnt = 1;
        while(std::cin >> item) {
            if(item.isbn() == currItem.isbn())
                ++cnt;
            else {
                std::cout << "The book of ISBN " << currItem.isbn() << ", records: " << cnt << std::endl;
                currItem = item;
                cnt = 1;
            }
        }
        std::cout << "The book of ISBN " << currItem.isbn() << ", records: " << cnt << std::endl;
    }
    return 0;
}

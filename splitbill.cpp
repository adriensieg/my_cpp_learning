// https://app.programiz.pro/community-challenges/preview/cpp-bill-split/info

// clang++ cardnumber.cpp -o cardnumberOutput

#include <iostream>
#include <iomanip>
#include <stdexcept>

double splitBill(double totalBill, int numberOfFriends) {
    // Input validation
    if (totalBill < 0) {
        throw std::invalid_argument("Total bill cannot be negative");
    }
    if (numberOfFriends <= 0) {
        throw std::invalid_argument("Number of friends must be positive");
    }
    
    std::cout << "There were " << numberOfFriends << " people at this dinner\n";
    std::cout << "The total amount was $" << std::fixed << std::setprecision(2) 
              << totalBill << "\n";
    
    double totalBillPerGuest = totalBill / numberOfFriends;
    return totalBillPerGuest;
}

int main() {
    try {
        double totalBillTest = 120.35;
        int numberOfFriendsTest = 2;  // Changed to 3 for better example
        
        double amountPerPerson = splitBill(totalBillTest, numberOfFriendsTest);
        
        std::cout << "Each person must pay $" << std::fixed << std::setprecision(2) 
                  << amountPerPerson << " per person\n";
                  
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

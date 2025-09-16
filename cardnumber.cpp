// https://app.programiz.pro/community-challenges/preview/cpp-hide-credit-card/info

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Fixed version - returns string and properly masks card number
string hideCreditCard(string cardNumber) {
    int lengthCardNumber = cardNumber.length();
    string result = "";
    
    // Show only last 4 digits, mask the rest
    for (int i = 0; i < lengthCardNumber; i++) {
        if (i < lengthCardNumber - 4) {
            result += "*";
        } else {
            result += cardNumber[i];
        }
    }
    return result;
}

// Alternative version using vector (if you wanted to keep vector approach)
string hideCreditCardWithVector(string cardNumber) {
    int lengthCardNumber = cardNumber.length();
    vector<char> myVector;  // Use char, not string
    
    for (int i = 0; i < lengthCardNumber; i++) {
        if (i < lengthCardNumber - 4) {
            myVector.push_back('*');  // Use char '*', not string "*"
        } else {
            myVector.push_back(cardNumber[i]);
        }
    }
    
    // Convert vector back to string
    string result(myVector.begin(), myVector.end());
    return result;
}

// Test the functions
int main() {
    string testCard = "1234567890123456";
    
    cout << "Original: " << testCard << endl;
    cout << "Hidden: " << hideCreditCard(testCard) << endl;
    cout << "Hidden (vector method): " << hideCreditCardWithVector(testCard) << endl;
    
    return 0;
}

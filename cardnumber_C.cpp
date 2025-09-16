#include <iostream>
#include <string>
using namespace std;

// Most optimized version - direct string manipulation
string hideCreditCard(const string& cardNumber) {
    if (cardNumber.length() <= 4) {
        return cardNumber; // If card is 4 digits or less, don't hide anything
    }
    
    string result = cardNumber;
    int charsToHide = min(12, static_cast<int>(cardNumber.length() - 4));
    
    // Replace first 'charsToHide' characters with asterisks
    for (int i = 0; i < charsToHide; i++) {
        result[i] = '*';
    }
    
    return result;
}

// Alternative using string constructor (also very efficient)
string hideCreditCardV2(const string& cardNumber) {
    if (cardNumber.length() <= 4) {
        return cardNumber;
    }
    
    int charsToHide = min(12, static_cast<int>(cardNumber.length() - 4));
    
    // Create string with asterisks + remaining characters
    return string(charsToHide, '*') + cardNumber.substr(charsToHide);
}

// Test function
int main() {
    // Test cases
    vector<string> testCards = {
        "1234567890123456",  // 16 digits - should show ****3456
        "123456789012",      // 12 digits - should show ********9012  
        "12345678901234567890", // 20 digits - should show ************7890
        "1234"               // 4 digits - should show 1234 (no hiding)
    };
    
    cout << "Testing credit card hiding function:\n\n";
    
    for (const string& card : testCards) {
        cout << "Original: " << card << endl;
        cout << "Hidden:   " << hideCreditCard(card) << endl;
        cout << "V2:       " << hideCreditCardV2(card) << endl;
        cout << "Length:   " << card.length() << " digits\n";
        cout << "-------------------\n";
    }
    
    return 0;
}

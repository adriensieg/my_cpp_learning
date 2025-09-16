# My C++ learning
Some mental notes about my C++ Learnings

## Resources
- **Exercices**: https://programiz.pro/community-challenges/cpp
- **Some great ressources**:
  - https://www.w3schools.com/cpp/cpp_new_lines.asp
  - https://hackingcpp.com/cpp/std/string_basics.html
 
## Notes

### `Pass by value` vs.`Pass by reference` vs. `Pass by const reference`

The `&` in `const string&` `cardNumber` means you're passing the **parameter by reference** instead of **by value**. 

```cpp
string hideCreditCard(const string& cardNumber) {
    if (cardNumber.length() <= 4) {
        return cardNumber; // If card is 4 digits or less, don't hide anything
    }
```

The `&` creates a **reference** - think of it as an "alias" or "nickname" for the original variable. 
Instead of **making a copy**, the function **works directly with the original data**.

- **Pass by value**: Like photocopying a document - you get your own copy to write on
- **Pass by reference**: Like sharing the original document - faster, but you could accidentally write on it
- **Pass by const reference**: Like sharing the original document with a "read-only" rule - fast AND safe

#### When to use each:
- **Small types** (`int`, `char`, `bool`): Pass by value is fine
- **Large types** (`string`, `vector`, `custom objects`): Use `const &` for better performance
- When you need **to modify**: Use `&` (without const)

The const `string&` pattern is considered best practice in modern C++ for **function parameters** that you only need to read from!

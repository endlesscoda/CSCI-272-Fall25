// John Jay Cafeteria Menu

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    // Creates a vector called menu.
    vector<string> menu;
    
    // Menu items
    menu.push_back("Chicken");
    menu.push_back("Pizza");
    menu.push_back("Spaghetti");
    menu.push_back("Salad");
    menu.push_back("Fish");
    
    // Adding and removing item from the menu using menu.insert and menu.erase.
    // menu.insert + 1 added “Hamburgers” as the 2nd item in the menu since "+ 1" points to the 2nd element. Without "+ 1", “Hamburgers would have been 1st in the menu.
    // menu.erase + 3 removes the 4th item in the menu since the "+ 3" points to the 4th element, or index 3. 
    // With the addition of “Hamburgers”, the 4th dish is at index 3, which is spaghetti.
    menu.insert(menu.begin() + 1, "Hamburgers");
    menu.erase(menu.begin() + 3);
    
    // Creates the final menu.
    cout << "Final Menu: " << endl;
    for (const auto& dish : menu) {
        cout << "-" << dish << endl;
    }
    
    return 0;
    
}

/* What is Big-O Notation? Explain it simply (no math needed).
When the size of the input data increases, the algorithm's performance can be described using Big-O Notation, which gives us a general idea of how an 
algorithm will scale with larger problems, and it helps us understand the worst-case scenario for its efficiency.

Why is Big-O important for programmers? Give one real-life example (e.g., searching names in a class roster).
Big-O Notation is important for programmers because it can help choose the most efficient or best approach to a problem. One real-life example that I 
could think of is needing to find a name in a phone book with hundreds or thousands of names, and checking each name individually would take a very long 
time and be painfully boring. A more efficient algorithm, like a binary search, would be much faster because it significantly reduces the number of steps 
required to find the name.

From your scenario (Part A): Why was vector a better choice than array for this problem?
Knowing that a cafeteria menu is a dynamic list that usually changes throughout the day, a vector was a better option than an array. An array's size is set 
and can’t be changed, so it must be declared at the outset. Meanwhile, a vector is a dynamic array that can expand or contract in size when dishes are added 
or removed in this case, which makes it more ideal for situations where the number of items is unpredictable and subject to change over time. */

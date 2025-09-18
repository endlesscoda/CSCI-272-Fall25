// Student Club Attendance

#include <iostream>
#include <vector>

using namespace std;

double getAverage(const vector<int>& ids) {
    if (ids.empty()) { // Checks if the vector is empty to avoid dividing by zero.
        return 0.0;
    }
    double sum = 0.0;
    for (int id : ids) { // Range-based loop to add all of the values.
        sum += id;
    }
    return sum / ids.size();
}

int getHighest(const vector<int>& ids) {
    if (ids.empty()) { // Checks if the vector is empty.
        return 0;
    }
    
    int highest = ids.at(0);
    for (size_t i = 1; i < ids.size(); ++i) {
        if (ids.at(i) > highest) { // Checks if the current student ID is larger than the current highest one.
            highest = ids.at(i); // Replaces the current student ID if it is bigger.
        }
    }
    return highest;
}

int main() {
    // Vector stores the student IDs
    vector<int> studentIDs = {28397934, 27387284, 43874875, 22038942, 37238437, 92846732, 52637821, 82937842, 17263767, 77777777};
    // Prints the results of both functions
    cout << "Average Student ID: " << getAverage(studentIDs) << endl;
    cout << "Highest Student ID: " << getHighest(studentIDs) << endl;
    
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

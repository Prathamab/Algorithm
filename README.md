1. Power of xⁿ using Binary Exponentiation (Recursive)
Aim

To efficiently compute x raised to the power n using divide and conquer approach.

Algorithm
int fastPower(int base, int exponent) {
    if(exponent == 0)
        return 1;

    int halfValue = fastPower(base, exponent / 2);

    if(exponent % 2 == 0)
        return halfValue * halfValue;
    else
        return base * halfValue * halfValue;
}

Time Complexity

At each step exponent becomes exponent / 2

Total recursive calls ≈ log₂(n)

Time Complexity: O(log n)
Space Complexity: O(log n) (due to recursion stack)

Use Case

Cryptography algorithms like RSA

Competitive programming modular exponentiation

Large power calculations efficiently

2. String Permutations
Aim

To generate all possible permutations of characters of a string and analyze execution time.

Algorithm
void generatePermutation(string &str, int left, int right) {
    if(left == right) {
        return;
    }

    for(int pos = left; pos <= right; pos++) {
        swap(str[left], str[pos]);
        generatePermutation(str, left + 1, right);
        swap(str[left], str[pos]);   // Backtracking
    }
}

Time Complexity

Time: O(n × n!)
Space: O(n)

Use Case

Password generation

Anagram problems

Brute force search

3. Horner’s Rule (Polynomial Evaluation)
Aim

To evaluate polynomial efficiently using recursive Horner’s method.

Algorithm
long long hornerEvaluate(vector<int> &coef, int valueX, int index) {

    if(index == coef.size() - 1)
        return coef[index];

    return coef[index] + valueX * hornerEvaluate(coef, valueX, index + 1);
}

Time Complexity

Time: O(n)
Space: O(n) recursive, O(1) iterative

Use Case

Polynomial calculation

Compiler optimization

Numerical methods

4. Tower of Hanoi
Aim

To solve Tower of Hanoi using recursion and measure execution time.

Algorithm
void solveHanoi(int disks, char source, char helper, char destination) {

    if(disks == 0)
        return;

    solveHanoi(disks - 1, source, destination, helper);
    solveHanoi(disks - 1, helper, source, destination);
}

Time Complexity

Time: O(2ⁿ)
Space: O(n)

Use Case

Recursion understanding

Divide and conquer concept

5. Bubble Sort and Selection Sort
Aim

To sort arrays and analyze execution time of simple sorting algorithms.

Bubble Sort Algorithm
void bubbleSorting(vector<int> &arrData) {
    int size = arrData.size();

    for(int pass = 0; pass < size - 1; pass++) {
        for(int pos = 0; pos < size - pass - 1; pos++) {
            if(arrData[pos] > arrData[pos + 1])
                swap(arrData[pos], arrData[pos + 1]);
        }
    }
}

Selection Sort Algorithm
void selectionSorting(vector<int> &arrData) {
    int size = arrData.size();

    for(int step = 0; step < size - 1; step++) {
        int minIndex = step;

        for(int check = step + 1; check < size; check++) {
            if(arrData[check] < arrData[minIndex])
                minIndex = check;
        }

        swap(arrData[step], arrData[minIndex]);
    }
}

Time Complexity

Bubble Sort: O(n²)
Selection Sort: O(n²)

Use Case

Learning sorting basics

Small dataset sorting

6. Missing Number using Bitwise Idea
Aim

To detect missing number in sequence using bitwise logic.

Algorithm
int detectMissing(int arrValues[], int length) {

    for(int i = 0; i < length - 1; i++) {

        if((arrValues[i] & 1) == (arrValues[i+1] & 1)) {
            return (arrValues[i] + arrValues[i+1]) / 2;
        }
    }

    return -1;
}

Time Complexity

Time: O(n)
Space: O(1)

Use Case

Bitwise programming

Sequence analysis

7. findTips (Velocity Reduction Recursion)
Aim

To calculate number of tips until velocity becomes less than 1.

Algorithm
int countTips(double velocity) {

    if(velocity < 1.0)
        return 0;

    return 1 + countTips(velocity - 0.425 * velocity);
}

Time Complexity

Time: O(v)
Space: O(v) recursion stack

Use Case

Recursion depth understanding

Simulation problems

8. Truth Table Generation
Aim

To generate boolean truth table combinations using recursion.

Algorithm
void generateTruthTable(int index, int total) {

    if(index > total)
        return;

    arr[index] = true;
    generateTruthTable(index + 1, total);

    arr[index] = false;
    generateTruthTable(index + 1, total);
}

Time Complexity

Time: O(2ⁿ)
Space: O(n)

Use Case

Digital logic

Boolean algebra

Circuit design

9. Linear Search
Aim

To search element sequentially in array and analyze execution time.

Algorithm
void sequentialSearch(int arrData[], int size) {

    int key = rand();

    for(int pos = 0; pos < size; pos++) {
        if(arrData[pos] == key)
            break;
    }
}

Time Complexity

Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)

Space Complexity: O(1)

Use Case

Small datasets

Unsorted arrays

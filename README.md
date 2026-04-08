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

3rd

Analysis of Merge Sort and Quick Sort
Overview
This repository contains the implementation and analysis of two important sorting algorithms:

Merge Sort
Quick Sort (Left element as pivot)

Both algorithms were implemented in C++ to calculate their execution time for different input sizes.
The obtained results were then used in Python to plot graphs showing the relationship between input size and execution time.

Algorithms Implemented

Merge Sort
Uses the divide and conquer technique
Recursively divides the array into halves
Merges sorted subarrays to produce the final sorted array

Time Complexity:
Best / Average / Worst: O(n log n)

Quick Sort
Uses leftmost element as pivot
Partitions the array around the pivot
Recursively sorts the subarrays

Time Complexity:

Best / Average: O(n log n)
Worst: O(n²) (already sorted input)

Time Measurement

Execution time was calculated in C++ using the clock() function
Input sizes ranged from 1000 to 10000
Average time per element (in microseconds) was computed
For small input sizes, execution time appears as 0 due to clock resolution limits

Graph Plotting Using Python

The output time values obtained from C++ programs were stored in Python arrays
Matplotlib was used to plot graphs

Graphs plotted:

Input Size vs Average Time (Merge Sort)
Input Size vs Average Time (Quick Sort)
These graphs help visualize and verify the theoretical time complexities of the algorithms.

Technologies Used

C++ – Algorithm implementation and time calculation
Python – Graph plotting
Matplotlib – Visualization library
GitHub – Version control and project hosting

4th
Kth Smallest Element Using Partition Algorithm (Quickselect)
1. Description

    This program finds the Kth smallest element in an unsorted array using the Partition Algorithm (based on Quick Sort).
    
    The approach used is called Quickselect Algorithm, which works similarly to Quick Sort but only processes the part of the array that contains the required element.

2. Algorithm Used

    Uses Partition function
    
    Selects first element as pivot
    
    Places pivot in its correct sorted position
    
    Recursively searches only the required side of the array
    
    This improves efficiency compared to fully sorting the array.

3. How It Works

    Choose the first element as pivot.
    
    Rearrange elements:
    
    Smaller elements → left side
    
    Larger elements → right side
    
    Get pivot index.
    
    Compare pivot index with k.
    
    If equal → element found.
    
    If greater → search left subarray.
    
    If smaller → search right subarray.

4. Code Features

    Uses recursion
    
    Implements partition logic manually
    
    Does not sort full array
    
    Time Complexity:
    
    Average Case: O(n)
    
    Worst Case: O(n²)


   5th

# Lab-05 – Convex Hull & Greedy Algorithms

##  Overview
This lab contains implementations of:

1. **Brute Force Convex Hull**
2. **Quick Hull Algorithm**
3. **Greedy Approach (Knapsack Problem)**


##  Programs Included

###  Brute Force Hull
- Finds Convex Hull by checking every pair of points.
- Determines if all other points lie on one side of the line.
-  Time Complexity: **O(n³)**
-  Simple but slow for large inputs.



###  Quick Hull
- Divide and Conquer method (similar to QuickSort).
- Finds farthest points recursively to build hull.
-  Average: **O(n log n)**
-  Worst Case: **O(n²)**
-  Faster than brute force.


###  Greedy Approach (Knapsack)
- Solves 0/1 Knapsack using:
  - Greedy by Profit
  - Greedy by Weight
  - Greedy by Profit/Weight Ratio
- Compares all three methods.
-  Time Complexity: **O(n log n)**
-  May not give optimal solution always.

---

6th

# Lab-06 – Greedy Algorithms

##  Overview
This lab contains implementations of:

1. **Activity selection problem**
2. **Dijkestra's algorithm**
3. **Prim's algorithm**
4. **generation of spanning tree**


##  Programs Included

### Activity Selection Problem

-  Selects maximum number of non-overlapping activities.
-  Implemented and compared:
    -  Sorting by Start Time
    -  Sorting by Finish Time
    -  Sorting by Duration
-  Best solution obtained when sorted by Finish Time.
-  Time Complexity: O(n log n)



###  Dijkestra's Algorithm
-  Finds shortest path from a source vertex to all other vertices.
-  Selects the minimum distance vertex at each step.
-  Works for graphs with non-negative edge weights.
-  Time Complexity: O(V²) (Basic Implementation)

 
###  Prim's Algorithm
-  Constructs a Minimum Spanning Tree (MST).
-  Implemented using:
    -  near[i] array
    -  Visited and Unvisited vertex lists
    -  Selects minimum weight edge at each step.
    -  Connects all vertices with minimum total cost.
-  Time Complexity: O(V²)


###  Spanning Tree(Cycle detection method)
-  Constructs a spanning tree by:
    -  Making DSU ,findParent and unionByRank function
    -  Ensuring no cycle is formed
    -  Similar to Kruskal’s Greedy Approach.

-  Time Complexity: O(E log E)

7th

# Lab-07: Kruskal’s Algorithm (Greedy Approach)

## Aim

To implement Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.

## Theory

Kruskal’s Algorithm is a greedy method used to construct a Minimum Spanning Tree. It selects edges in increasing order of weight and adds them to the tree only if they do not form a cycle. A Disjoint Set (Union-Find) data structure is used to efficiently detect cycles.

## Algorithm

1. Sort all edges in increasing order of weight
2. Initialize each vertex as a separate set
3. For each edge, check if it forms a cycle and include it in the MST if it does not
4. Repeat until (V - 1) edges are selected

## Input

Number of vertices (V), number of edges (E), and list of edges with their weights (u, v, weight).

## Output

Total weight of the Minimum Spanning Tree and the edges included in the MST.

## Time Complexity

O(E log E)

## Conclusion

Kruskal’s Algorithm efficiently finds the Minimum Spanning Tree using a greedy approach and works well for sparse graphs.

8th

# Lab-08: Rod Cutting Problem (Dynamic Programming)

## Aim

To implement the Rod Cutting problem using Dynamic Programming and visualize the maximum profit using a graph in Python.

## Theory

The Rod Cutting problem is a classic Dynamic Programming problem where the goal is to determine the maximum profit obtainable by cutting a rod of length n into smaller pieces and selling them. The idea is to try all possible cuts and choose the one that gives the maximum profit. Dynamic Programming is used to store intermediate results and avoid recomputation.

## Algorithm

1. Initialize a DP array to store maximum profit for each length
2. For each rod length i, try all possible cuts j
3. Compute maximum value using price[j] + dp[i - j - 1]
4. Store the maximum value in dp[i]
5. Repeat until the full length is evaluated

## Input

Rod length (n) and an array of prices where price[i] represents the value of a rod of length (i + 1).

## Output

Maximum obtainable profit for the given rod length.

## Graph Visualization

A Python program is used to plot a graph with rod length on the x-axis and maximum profit on the y-axis. This helps in understanding how profit increases with length using Dynamic Programming.

## Time Complexity

O(n^2)

## Conclusion

The Rod Cutting problem demonstrates the effectiveness of Dynamic Programming in optimization problems. It ensures maximum profit by considering all possible cuts and visualizing the result using a graph improves understanding.


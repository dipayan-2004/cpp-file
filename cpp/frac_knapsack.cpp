#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store item details
struct Item {
    int weight, value;
    double val_wt_rat;
};

// Comparator function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort in descending order
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int W, vector<Item> items) {
    // Sort items by descending value/weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;
    int currentWeight = 0;

    for (auto item : items) {
        if (currentWeight + item.weight <= W) { // Take full item
            currentWeight += item.weight;
            maxValue += item.value;
        } else { // Take fraction of item
            int remainingWeight = W - currentWeight;
            maxValue += item.value * ((double)remainingWeight / item.weight);
            break; // Knapsack is full
        }
    }
    return maxValue;
}

int main() {
    // vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // {weight, value}

    cout<<"This is fractional knapsack...."<<endl;
    cout<<"write the number of items...."<<endl;
    int n;
    cin>>n;
    vector<Item> items[n];
    cout<<"write the profits and corresponding weights"<<endl;
    for(int i = 0; i < n ; i++){
        cin>>(items[i]).value;
    }
    int W = 50; // Knapsack capacity

    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxProfit << endl;

    return 0;
}

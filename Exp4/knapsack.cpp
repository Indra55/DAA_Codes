#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 60;  // Capacity of knapsack
    int n = 4;   // Number of items

    int value[] = {100, 280, 120, 120};
    int weight[] = {10, 40, 20, 24};

    // Create value/weight ratio array
    double ratio[100];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)value[i] / weight[i];
    }

    // Sort by ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    double finalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= N) {
            currentWeight += weight[i];
            finalValue += value[i];
        } else {
            int remain = N - currentWeight;
            finalValue += value[i] * ((double)remain / weight[i]);
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum profit earned = " << finalValue << endl;

    return 0;
}

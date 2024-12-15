#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> buildArithmeticProgression(int start, int diff, unordered_map<int, int>& count) {
    vector<int> pa;
    int term = start;

    while (count[term] > 0) {
        pa.push_back(term);
        count[term]--;
        term += diff;
    }

    return pa;
}

vector<int> buildGeometricProgression(int start, int ratio, unordered_map<int, int>& count) {
    vector<int> pg;
    int term = start;

    while (term > 0 && count[term] > 0) {
        pg.push_back(term);
        count[term]--;
        term *= ratio;
    }

    return pg;
}

pair<vector<int>, vector<int>> findBestProgressions(unordered_map<int, int>& count, const vector<int>& arr) {
    bool empty = true;
    for (auto& [key, value] : count) {
        if (value > 0) {
            empty = false;
            break;
        }
    }
    if (empty) {
        return {{}, {}};
    }

    vector<int> bestPA, bestPG;
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            int diff = arr[j] - arr[i];
            if (count[arr[i]] == 0 || count[arr[j]] == 0) continue;

            auto countCopy = count;
            vector<int> currentPA = buildArithmeticProgression(arr[i], diff, countCopy);

            auto [subPA, subPG] = findBestProgressions(countCopy, arr);

            if (currentPA.size() + subPG.size() > bestPA.size() + bestPG.size()) {
                bestPA = currentPA;
                bestPG = subPG;
            }
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == 0 || arr[j] % arr[i] != 0 || count[arr[i]] == 0 || count[arr[j]] == 0) continue;
            int ratio = arr[j] / arr[i];

            auto countCopy = count;
            vector<int> currentPG = buildGeometricProgression(arr[i], ratio, countCopy);

            auto [subPA, subPG] = findBestProgressions(countCopy, arr);

            if (subPA.size() + currentPG.size() > bestPA.size() + bestPG.size()) {
                bestPA = subPA;
                bestPG = currentPG;
            }
        }
    }

    if (bestPA.empty()) {
        for (auto& [key, value] : count) {
            if (value > 0) {
                bestPA.push_back(key);
                count[key]--;
                break;
            }
        }
    }

    return {bestPA, bestPG};
}

void imprimirProgresiones(const vector<int>& arr) {
    unordered_map<int, int> count;
    for (int num : arr) {
        count[num]++;
    }

    auto [bestPA, bestPG] = findBestProgressions(count, arr);

    // Imprimir PA
    cout << "A: ";
    if (!bestPA.empty()) {
        for (int num : bestPA) {
            cout << num << " ";
        }
    } else {
        cout << "-";
    }

    // Imprimir PG
    cout << " - G: ";
    if (!bestPG.empty()) {
        for (int num : bestPG) {
            cout << num << " ";
        }
    } else {
        cout << "-";
    }

    cout << endl;
}


int main() {
    vector<vector<int>> testCases = {
        {1, 10, 9, 5, 7, 13, 100},
        {5, 5, 5, 5, 5, 1},
        {0, 10, 3, 8, 9, 6},
        {100}
    };

    for (const auto& testCase : testCases) {
        imprimirProgresiones(testCase);
    }

    return 0;
}
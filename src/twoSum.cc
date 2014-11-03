#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Given an array of integers, find two numbers such that they add up to a specific target number.
// Input: numbers = {2, 7, 11, 15}, target = 9
// Output: index1 = 1, index2 = 2

vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, int> m;
    vector<int> result;

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        // 如果没有找到，则将当前元素的匹配项放到map中，以便后续查找
        // key: 匹配项；value：当前元素的index
        if (m.find(numbers[i]) == m.end()) {
            m[target - numbers[i]] = i;
        }
        else {
            // 如果找到了，则说明当前元素的匹配项在数组前面出现过
            // 这时，只要从map中把匹配元素的index拿出来即可
            result.push_back(m[numbers[i]] + 1);
            result.push_back(i + 1);
            break;
        }
    }

    return result;
}

int main() {
    int a[] = {2, 7, 11, 15};
    // 初始化vector
    vector<int> numbers(a, a + sizeof(a) / sizeof(int));
    vector<int> result = twoSum(numbers, 13);
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}

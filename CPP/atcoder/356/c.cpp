#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// 函数用于计算一个整数中二进制1的个数
int countOnes(int mask) {
    int count = 0;
    while (mask) {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

// 函数用于检查一个mask是否在给定的keys集合中至少有K个1
bool checkAtLeastKOnes(int mask, const vector<int>& keys, int K) {
    int count = 0;
    for (int key : keys) {
        // 检查mask的对应位是否为1
        if (mask & (1 << (key - 1))) {
            count++;
        }
    }
    return count >= K;
}

// 函数用于检查一个mask是否在给定的keys集合中至多有K-1个1
bool checkAtMostKMinusOneOnes(int mask, const vector<int>& keys, int K) {
    int count = 0;
    for (int key : keys) {
        // 检查mask的对应位是否为1
        if (mask & (1 << (key - 1))) {
            count++;
        }
    }
    return count <= K - 1;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<vector<int>, char>> tests(M);
    for (int i = 0; i < M; ++i) {
        int C;
        cin >> C;
        tests[i].first.resize(C);
        for (int j = 0; j < C; ++j) {
            cin >> tests[i].first[j];
        }
        cin >> tests[i].second;
    }

    vector<int> dp(1 << N, 0); // dp数组大小为2^N

    // 初始化dp数组
    for (int mask = 0; mask < (1 << N); ++mask) {
        if (1) {
            dp[mask] = 1;
        }
    }

    // 根据测试更新dp数组
    for (const auto& test : tests) {
        const vector<int>& keys = test.first;
        char result = test.second;

        for (int mask = 0; mask < (1 << N); ++mask) {
            if (dp[mask] == 0) continue; // 如果这个状态已经被排除了，就跳过

            if (result == 'o' && !checkAtLeastKOnes(mask, keys, K)) {
                dp[mask] = 0; // 如果结果应该是'o'但mask中1的数量不足K个，排除这个状态
            }
            if (result == 'x' && !checkAtMostKMinusOneOnes(mask, keys, K)) {
                dp[mask] = 0; // 如果结果应该是'x'但mask中1的数量超过或等于K个，排除这个状态
            }
        }
    }

    // 计算答案
    int answer = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        if (dp[mask] == 1) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}

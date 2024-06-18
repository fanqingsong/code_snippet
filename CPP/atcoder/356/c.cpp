#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// �������ڼ���һ�������ж�����1�ĸ���
int countOnes(int mask) {
    int count = 0;
    while (mask) {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

// �������ڼ��һ��mask�Ƿ��ڸ�����keys������������K��1
bool checkAtLeastKOnes(int mask, const vector<int>& keys, int K) {
    int count = 0;
    for (int key : keys) {
        // ���mask�Ķ�Ӧλ�Ƿ�Ϊ1
        if (mask & (1 << (key - 1))) {
            count++;
        }
    }
    return count >= K;
}

// �������ڼ��һ��mask�Ƿ��ڸ�����keys������������K-1��1
bool checkAtMostKMinusOneOnes(int mask, const vector<int>& keys, int K) {
    int count = 0;
    for (int key : keys) {
        // ���mask�Ķ�Ӧλ�Ƿ�Ϊ1
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

    vector<int> dp(1 << N, 0); // dp�����СΪ2^N

    // ��ʼ��dp����
    for (int mask = 0; mask < (1 << N); ++mask) {
        if (1) {
            dp[mask] = 1;
        }
    }

    // ���ݲ��Ը���dp����
    for (const auto& test : tests) {
        const vector<int>& keys = test.first;
        char result = test.second;

        for (int mask = 0; mask < (1 << N); ++mask) {
            if (dp[mask] == 0) continue; // ������״̬�Ѿ����ų��ˣ�������

            if (result == 'o' && !checkAtLeastKOnes(mask, keys, K)) {
                dp[mask] = 0; // ������Ӧ����'o'��mask��1����������K�����ų����״̬
            }
            if (result == 'x' && !checkAtMostKMinusOneOnes(mask, keys, K)) {
                dp[mask] = 0; // ������Ӧ����'x'��mask��1���������������K�����ų����״̬
            }
        }
    }

    // �����
    int answer = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        if (dp[mask] == 1) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}

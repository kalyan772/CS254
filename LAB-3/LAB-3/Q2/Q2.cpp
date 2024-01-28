#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct SubarrayInfo {
    int maxsum;
    int maxprefixsum;
    int maxsuffixsum;
    int totalsum;
};

SubarrayInfo getsubarrayinfo(int value) {
    SubarrayInfo info;
    info.maxsum = value;
    info.maxprefixsum = value;
    info.maxsuffixsum = value;
    info.totalsum = value;
    return info;
}

SubarrayInfo mergesubarrays(const SubarrayInfo &left, const SubarrayInfo &right) {
    SubarrayInfo result;
    result.maxsum = result.maxprefixsum = result.maxsuffixsum = result.totalsum = 0;

    result.maxprefixsum = max({left.maxprefixsum, left.totalsum + right.maxprefixsum, left.totalsum + right.totalsum});
    result.maxsuffixsum = max({right.maxsuffixsum, right.totalsum + left.maxsuffixsum, left.totalsum + right.totalsum});
    result.totalsum = left.totalsum + right.totalsum;

    result.maxsum = max({result.maxprefixsum, result.maxsuffixsum, result.totalsum, left.maxsum, right.maxsum, left.maxsuffixsum + right.maxprefixsum});

    return result;
}

SubarrayInfo findmaxsubarray(int left, int right, int array[]) {
    if (left == right) return getsubarrayinfo(array[left]);

    int mid = (left + right) >> 1;

    SubarrayInfo leftsubarray = findmaxsubarray(left, mid, array);
    SubarrayInfo rightsubarray = findmaxsubarray(mid + 1, right, array);

    return mergesubarrays(leftsubarray, rightsubarray);
}

int main() {

    freopen("test_cases_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);

    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int arraysize;
        cin >> arraysize;
        int array[arraysize];
        for (int i = 0; i < arraysize; ++i) {
            cin >> array[i];
        }
        SubarrayInfo result = findmaxsubarray(0, arraysize - 1, array);
        cout << "Maximum subarray sum is: " << result.maxsum << "\n";
    }
    return 0;
}

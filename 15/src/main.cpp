#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    vector<long long> nums;
 
    for(long long i = 0; i < n; ++i) {
        long long num;
        cin >> num;
        nums.push_back(num);
    }
 
    long long max_num = nums[0];
    for(long long i = 1; i < n; i++) {
        if(nums[i] > max_num)
            max_num = nums[i];
    }
 
    long long result = 0;

    for(long long i = 0; i < n; i++) {
        if(nums[i] < nums[i+1]) {
            long long delta = max_num - nums[i];
            result += delta;
            for(long long j = i; j < n and delta != 0; j++) {
                if(delta > max_num - nums[j]) {
                    delta = max_num - nums[j];
                }
                nums[j] += delta;
            }
        }
    }
    result += max_num - nums[nums.size()-1];
    cout << result;
    return 0;
}
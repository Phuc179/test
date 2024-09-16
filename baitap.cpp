#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

// Hàm tính tích của một tập con
long long product(const std::vector<int>& subset) {
    long long prod = 1;
    for (int num : subset) {
        prod *= num;
    }
    return prod;
}

// Hàm tìm tập con có tích lớn nhất
std::vector<int> findMaxProductSubset(const std::vector<int>& arr) {
    int n = arr.size();
    long long maxProduct = LLONG_MIN; // Khởi tạo tích lớn nhất là giá trị nhỏ nhất có thể
    std::vector<int> maxProductSubset;

    // Sử dụng toàn bộ các tập con của dãy
    // Có 2^n tập con
    int totalSubsets = 1 << n;

    for (int i = 0; i < totalSubsets; ++i) {
        std::vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        if (!subset.empty()) { // Chỉ tính tích của tập con không rỗng
            long long currentProduct = product(subset);
            if (currentProduct > maxProduct) {
                maxProduct = currentProduct;
                maxProductSubset = subset;
            }
        }
    }

    return maxProductSubset;
}

int main() {
    std::vector<int> arr = {1, 2, -3, 4, -5};

    std::vector<int> result = findMaxProductSubset(arr);

    std::cout << "Tập con có tích lớn nhất: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

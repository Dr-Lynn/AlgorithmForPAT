#include <iostream>
#include <vector>
#include <algorithm>  // 用于swap函数
using namespace std;

// ================================
// 函数：partitionLomuto
// 作用：对数组arr的[left, right]范围进行分区
//      使用最后一个元素作为基准
// 返回值：基准元素的最终位置索引
// ================================
int partitionLomuto(vector<int>& arr, int left, int right) {
    // 步骤1：选择基准值（这里选择最右边的元素）
    // 为什么不选第一个？因为如果数组已经有序，会导致最坏情况O(n²)
    int pivot = arr[right];  // 基准值
    // i 指向小于基准值区域的最后一个位置
    // 初始为 left-1，因为开始时小于基准的区域为空
    int i = left - 1;

    // 步骤2：遍历数组[left, right-1]（不包括基准元素自己）
    // 将所有小于基准值的元素移动到左边区域
    for (int j = left; j <= right - 1; j++) {
        // 如果当前元素小于等于基准值
        if (arr[j] <= pivot) {
            // 扩大小于基准值的区域：i向右移动一位
            i++;
            // 交换arr[i]和arr[j]
            // 这样arr[i]总是小于等于基准值
            swap(arr[i], arr[j]);
        }
        // 如果arr[j] > pivot，什么都不做，它自然留在右边区域
    }

    // 步骤3：将基准元素放到正确位置
    // 现在i指向小于基准值区域的最后一个位置
    // 所以i+1就是基准值应该放的位置（左边都小于它，右边都大于它）
    swap(arr[i + 1], arr[right]);

    // 步骤4：返回基准值的最终位置
    // 这样左边的递归排序就知道排哪里（left 到 pivotIndex-1）
    // 右边的递归排序也知道排哪里（pivotIndex+1 到 right）
    return i + 1;
}

// ================================
// 函数：quickSortRecursive
// 作用：递归实现快速排序
// 参数：arr-待排序数组，left-子数组左边界，right-子数组右边界
// ================================
void quickSortRecursive(vector<int>& arr, int left, int right) {
    // 递归终止条件：如果子数组只有一个元素或为空，不需要排序
    if (left >= right) {
        // 想象一下：只有一个学生，自然是有序的，不需要排队
        return;
    }

    // 步骤1：进行分区操作，找到基准元素的正确位置
    // partitionIndex是基准值在数组中的最终位置
    int partitionIndex = partitionLomuto(arr, left, right);

    // 步骤2：递归排序基准值左边的子数组
    // 注意：不包括基准值自己，因为它已经在正确位置了
    quickSortRecursive(arr, left, partitionIndex - 1);

    // 步骤3：递归排序基准值右边的子数组
    quickSortRecursive(arr, partitionIndex + 1, right);

    // 思考：为什么先排左边再排右边？其实顺序不重要
}

// ================================
// 函数：quickSort（包装函数）
// 作用：简化调用，用户只需要传入数组
// ================================
void quickSort(vector<int>& arr) {
    // 如果数组为空或只有一个元素，直接返回
    if (arr.size() <= 1) {
        return;
    }

    // 调用递归函数，对整个数组进行排序
    // 初始范围：0 到 最后一个元素索引
    quickSortRecursive(arr, 0, arr.size() - 1);
}

// ================================
// 测试函数
// ================================
int main() {
    // 测试用例1：普通数组
    vector<int> arr1 = {10, 80, 30, 90, 40, 50, 70};
    cout << "原始数组1: ";
    for (int num : arr1) cout << num << " ";
    cout << endl;

    quickSort(arr1);
    cout << "排序后数组1: ";
    for (int num : arr1) cout << num << " ";
    cout << endl << endl;

    return 0;
}
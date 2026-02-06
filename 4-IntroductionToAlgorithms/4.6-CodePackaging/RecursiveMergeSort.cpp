#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left +1; //左子数组长度
    int n2 = right - mid; //右子数组长度

    //创建临时数组存储两个数组
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    //拷贝数据到临时数组
    for(int i = 0;i<n1;i++) leftArr[i] = arr[left+i];
    for(int j = 0;j<n2;j++) rightArr[j] = arr[mid+1+j];

    //合并两个有序数组
    int i = 0; //左子数组索引
    int j = 0; //右子数组索引
    int k = left; //原数组索引（从left开始）

    while(i<n1 && j<n2)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //拷贝剩余元素（如果有）
    while (i<n1)
    {
        arr[k] = leftArr[i];
        i++; k++;
    }
    while (j<n2)
    {
        arr[k] = rightArr[j];
        j++; k++;
    }
}

//归并递归版
void MergeSort(vector<int>& arr,int left, int right)
{
    if(left >= right) return;

    int mid = left + (right - left)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1,right);

    merge(arr, left, mid, right);
}

//包装函数，简化调用
void MergeSortRecursive(vector<int>& arr)
{
    if(arr.size() <= 1) return;
    MergeSort(arr, 0, arr.size()-1);
}

//不递归的迭代版
void mergeSortIterative(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    // 第一层循环：控制当前合并的块大小
    // 从1开始：每个元素自己是一个有序块
    // 每次翻倍：合并后块大小翻倍
    for (int currSize = 1; currSize < n; currSize = 2 * currSize) {

        // 第二层循环：遍历所有需要合并的"块对"
        // left是第一个块的起始索引
        // 每次跳过一对块（两个块），所以left += 2*currSize
        for (int left = 0; left < n - 1; left += 2 * currSize) {

            // mid是第一个块的结束位置
            // left + currSize - 1 是正常情况下第一个块的结束
            // 但可能最后一个块不够大，所以用min防止越界
            int mid = min(left + currSize - 1, n - 1);

            // right是第二个块的结束位置
            // left + 2*currSize - 1 是正常情况下第二个块的结束
            // 同样用min防止越界
            int right = min(left + 2 * currSize - 1, n - 1);

            // 重要！如果mid等于right，说明第二个块不存在
            // 只有一个块时不需要合并
            if (mid < right) {
                // 调用合并函数，合并两个有序块
                // [left...mid] 和 [mid+1...right]
                merge(arr, left, mid, right);
            }
        }

        // 这里可以添加打印语句，观察每轮合并后的结果
        // cout << "合并块大小 " << currSize << " 后: ";
        // for (int num : arr) cout << num << " ";
        // cout << endl;
    }
}

int main() {
    vector<int> arr = {3,4,2,6,1,9,10,5};
    MergeSortRecursive(arr);
    mergeSortIterative(arr);
    for(int i = 0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

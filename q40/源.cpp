#include<iostream>
#include<vector>
using namespace std;

class maxHeap
{
public:
    void createMaxHeap(std::vector<int> v, int k)
    {
        for (int i = 0; i < k; i++)
        {
            push(v[i]);
        }
    }
    
    void floatUp()
    {
        int bottomIdx = data.size() - 1;
        int bottomVal = data[bottomIdx];
        int currIdx = bottomIdx;
        int parentIdx = (currIdx-1) >> 1;
        while (parentIdx>=0)
        {
            if (data[parentIdx] < data[currIdx])
            {
                std::swap(data[parentIdx], data[currIdx]);
                currIdx = parentIdx;
                parentIdx = (currIdx - 1) >> 1;
            }
            else
            {
                break;
            }
        }
    }
    
    void push(int val)
    {
        data.push_back(val);
        floatUp();
    }

    void sink()
    {
        int currIdx = 0;
        int leftChildIdx = 2 * currIdx + 1;
        int rightChildIdx = 2 * currIdx + 2;
        while (currIdx<data.size()&&leftChildIdx<data.size())
        {
            if (leftChildIdx < data.size() && rightChildIdx < data.size())
            {
                int maxVal = max(data[leftChildIdx], data[rightChildIdx]);
                if (data[currIdx] < maxVal)
                {
                    if (maxVal == data[leftChildIdx])
                    {
                        std::swap(data[leftChildIdx], data[currIdx]);
                        currIdx = leftChildIdx;
                    }
                    else
                    {
                        std::swap(data[rightChildIdx], data[currIdx]);
                        currIdx = rightChildIdx;
                    }
                }
                else break;
            }
            else if (rightChildIdx >= data.size())
            {
                if (data[currIdx] < data[leftChildIdx])
                {
                    std::swap(data[leftChildIdx], data[currIdx]);
                    currIdx = leftChildIdx;
                }
                else break;
            }
            else if (leftChildIdx >= data.size()) break;
            leftChildIdx = 2 * currIdx + 1;
            rightChildIdx = 2 * currIdx + 2;
        }
    }

    void pop()
    {
        if (!data.empty())
        {
            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
        }
        sink();
    }

    int top()
    {
        return data[0];
    }
    std::vector<int> data;
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
        {
            return arr;
        }
        if (k == 0)
            return vector<int>();
        maxHeap myHeap;
        myHeap.createMaxHeap(arr, k);
        for (int i = k; i < arr.size(); ++i)
        {
            if (arr[i] < myHeap.top())
            {
                myHeap.pop();
                myHeap.push(arr[i]);
            }
        }
        return myHeap.data;
    }
};

int main()
{
    vector<int> v = { 0, 1, 1, 1, 4, 5, 3, 7, 7, 8, 10, 2, 7, 8, 0, 5, 2, 16, 12, 1, 19, 15, 5, 18, 2, 2, 22, 15, 8, 22, 17, 6, 22, 6, 22, 26, 32, 8, 10, 11, 2, 26, 9, 12, 9, 7, 28, 33, 20, 7, 2, 17, 44, 3, 52, 27, 2, 23, 19, 56, 56, 58, 36, 31, 1, 19, 19, 6, 65, 49, 27, 63, 29, 1, 69, 47, 56, 61, 40, 43, 10, 71, 60, 66, 42, 44, 10, 12, 83, 69, 73, 2, 65, 93, 92, 47, 35, 39, 13, 75 };
    int k = 75;
    Solution sol;
    vector<int> leastK = sol.getLeastNumbers(v, k);
}
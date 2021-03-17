#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        auto less = [](int x, int y) {return x < y; };
        auto greater = [](int x, int y) {return x > y; };

        if (!minHeap.empty())
        {
            if (num < minHeap[0])
            {
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(), maxHeap.end(), less);
                if (maxHeap.size() - minHeap.size() > 1)
                {
                    num = maxHeap[0];
                    pop_heap(maxHeap.begin(), maxHeap.end(), less);
                    maxHeap.pop_back();
                    minHeap.push_back(num);
                    push_heap(minHeap.begin(), minHeap.end(), greater);
                }
            }
            else
            {
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater);
                if (minHeap.size() - maxHeap.size() > 1)
                {
                    num = minHeap[0];
                    pop_heap(minHeap.begin(), minHeap.end(), greater);
                    minHeap.pop_back();
                    maxHeap.push_back(num);
                    push_heap(maxHeap.begin(), maxHeap.end(), less);
                }
            }
        }
        else
        {
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(), maxHeap.end(), less);
            if (maxHeap.size() - minHeap.size() > 1)
            {
                num = maxHeap[0];
                pop_heap(maxHeap.begin(), maxHeap.end(), less);
                maxHeap.pop_back();
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater);
            }
        }
    }

    double findMedian() {
        if (!maxHeap.empty() && !minHeap.empty())
        {
            if (maxHeap.size() == minHeap.size())
                return (double) ((maxHeap[0] + minHeap[0]) / 2.0f);
            else if (maxHeap.size() > minHeap.size())
                return maxHeap[0];
            else if (maxHeap.size() < minHeap.size())
                return minHeap[0];
        }
        else if (minHeap.empty())
        {
            return maxHeap[0];
        }
        return 0.0;
    }

private:
    vector<int> minHeap;
    vector<int> maxHeap;
};

int main()
{
    MedianFinder medianFinder;
    double median;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    median = medianFinder.findMedian();
    medianFinder.addNum(3);
    median = medianFinder.findMedian();
}


#include <iostream>
using namespace std;

template <class elemType> class staticSearch {
  private:
    elemType *data;
    int len;

  public:
    staticSearch<elemType>(elemType a[], int n);
    int Search(const elemType &x) const;
    int BSearch(const elemType &x) const;

    ~staticSearch<elemType>() { delete[] data; }
};

template <class elemType> staticSearch<elemType>::staticSearch(elemType a[], int n) {
    this->len = n;
    data = new elemType[n + 1];
    for (int i = 0; i < n; i++) {
        data[i + 1] = a[i];
    }
}

template <class elemType> int staticSearch<elemType>::Search(const elemType &x) const {
    int i;
    data[0] = x;
    for (i = len; i > 0; i--) {
        if (data[i] == x) {
            break;
        }
    }
    if (i != 0) {
        return i;
    } else {
        return 0;
    }
}

template <class elemType> int staticSearch<elemType>::BSearch(const elemType &x) const {
    int mid, low, high;
    low = 1;
    high = len;
    while (low < high) {
        mid = (low + high) / 2;
        if (data[mid] == x) {
            break;
        } else {
            if (x > data[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    if (low < high) {
        return mid;
    } else {
        return 0;
    }
}
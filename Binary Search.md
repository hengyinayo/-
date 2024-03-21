# 구현 방법 1 (직접 구현)
```
bool binarySearch(int *arr, int len, int key) {
    int start = 0;
    int end = len - 1;
    int mid;

    while(end - start >= 0) {
        mid = (start + end) / 2; // 중앙 값

        if (arr[mid] == key) { //key 값을 찾았을 때
            return true;
        }
        else if (arr[mid] > key) {  // key 값이 mid의 값보다 작을때 (왼쪽으로)
            end = mid -1;
        }
        else {  // key 값이 mid의 값보다 클 때 (오른쪽으로)
            start = mid + 1;
        }
    }
}
```

# 구현 방법 2 (재귀)
```
bool binarySearch(int *arr, int start, int end, int key) {
    if (start > end) return false; // key 값이 없을 때
    
    int mid = (start + end) / 2;
    
    if (arr[mid] == key) {
        return true;
    }
    else if (arr[mid] > key) {
        return binarySearch(arr, start, end-1, key);
    }
    else {
        return binarySearch(arr, mid+1, end, key);
    }
}
```

# 구현 방법 3 (STL 이용)
`binary_search(arr, arr+n, targetNum);`


# lower_bound 1 (직접 구현 코드)
```
myLower_bound(int *arr, int n, int key) {
    int start = 0;
    int end = 0;

    int mid = n;
    while(end - start >= 0) { // start가 end와 같지 않고, 넘지 않을 때
        mid = (start + end) / 2; // 중앙 index

        if (arr[mid] < key) { // key값이 중앙 값보다 크면
            start = mid +1; // mid보다 오른쪽으로
        }
        else {  // key 값이 중앙값보다 작거나 같으면
            end = mid;  // mid 포함 왼쪽(포함하는 이유는 key 값과 같은게 없을 때 큰수 중 가장 작은 값을 위해)
        }
    }
    return end+1;
}
```

# lower_bound 2 (STL 이용)
`lower_bound(arr, arr+n, targetNum) - (arr);`


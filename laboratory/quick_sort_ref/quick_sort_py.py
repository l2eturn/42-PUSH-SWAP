def quick_sort(arr):
    if (len(arr) <= 1):
        return arr;
    pivot = arr[-1]
    left = [x for x in arr[:-1] if x <= pivot]
    right = [x for x in arr[:-1] if x > pivot]
    
    return quick_sort(left) + [pivot] + quick_sort(right)

arr = [343,366,11,878,22,454]
res = quick_sort(arr)
print(res)

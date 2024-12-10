def shellSort(arr, n):
    
    gap = n // 2  
    
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  


arr = [82, 34, 54, 92, 73]
n = len(arr)
print("Percentage of second year students before sorting:")
print(arr)

shellSort(arr, n)
print("\nPercentage of second year students after sorting in ascending order:")
print(arr)


top5 = arr[-5:]
print("\nTop 5 elements in ascending order:", top5)


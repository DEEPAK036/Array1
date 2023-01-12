// Selection Sort (finding the minimum element and swapping it with the element at begining) O(n^2)
void SelectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Bubble sort (repeatedly swap two adjacent elements if they are in wrong order, n-1 iterations to get sorted array) O(n^2)
void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    int counter = 1;
    while (counter < n - 1)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        counter++;
    }
}

// Insertion Sort (inserting an element from an unsorted array to its correct place in the sorted array) O(n^2)
void InsertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
// Merge Sort (Divide and Conquer algorithm) O(n.logn)
void merge(vector<int> arr, int l, int r, int mid)
{
    int n1 = mid + 1 - l;
    int n2 = r - mid;

    int a[n1]; // temporary array
    int b[n2]; // temporary array

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = arr[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = arr[j];
        k++;
        j++;
    }
}
void MergeSort(vector<int> &arr, int l, int r)
{
    if (L < R)
    {
        int mid = (l + r) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);

        merge(arr, l, r, mid);
    }
}

// QuickSort (Divide and Conquer algorithm) Best - O(n.logn)(when pivot element is mid element); Worst - O(n^2) (when pivot element is end element)
int partition(vector<int>& arr, int l ,int r)
{
    int pivot = arr[r];

    int i = l-1;

    for( int j = l; j < r-1; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void QuickSort(vector<int> &arr, int l, int r)
{
    if(l<r)
    {
        int pivot = partition(arr,l,r);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,r);
    }
}

// DNF Algo
void segregateZeroOneandTwo(vector<int> &arr)
{
    int n = arr.size();
    int ptr1 = -1, itr = 0, ptr2 = n - 1;

    while (itr < n)
    {

        if (arr[itr] == 0)
        {
            swap(arr[itr++], arr[++ptr1])
        }
        else if (arr[itr] == 2)
        {
            swap(arr[itr], arr[--ptr2]);
        }
        else
            itr++;
    }
}
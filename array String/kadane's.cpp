// Longest sum in contigous array

int KadaneAlgo(vector<int> &arr)
{
    int gSum = 0, cSum = 0;

    for (int ele : arr)
    {
        cSum += ele;
        if (cSum > gSum)
            gSum = cSum;
        if (cSum <= 0)
            cSum = 0;
    }
    return gSum;
}

vector<int> KadaneAlgo_subarray(vector<int> &arr)
{
    int gSum = 0, cSum = 0, gsi = 0, gei = 0, csi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        cSum += ele;
        if (cSum > gSum)
        {
            gSum = cSum;
            gsi = csi;
            gei = i;
        }

        if (cSum <= 0)
            cSum = 0;
        csi = i + 1;
    }
    return arr.substr(gsi, gsi - gei);
}

// Generic, worls for both + and -
int KadaneAlgo(vector<int> &arr)
{
    int gSum = -1e9, cSum = 0;

    for (int ele : arr)
    {
        cSum = max(ele, cSum + ele);
        gSum = max(gSum, cSum);
    }
    return gSum;
}

vector<int> KadaneAlgo_subarray(vector<int> &arr)
{
    int gSum = -1e9, cSum = 0, gsi = 0, gei = 0, csi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        cSum += ele;
        if (ele > cSum)
        {
            cSum = ele;
            csi = i;
        }

        if (cSum > gSum)
        {
            gSum = cSum;
            gsi = csi;
            gei = i;
        }
    }
    return arr.substr(gsi, gsi - gei);
}

// 1191
int mod = 1e9 + 7;

int KadaneAlgo(vector<int> &arr, int k)
{
    int n = arr.size();
    long gsum = 0, csum = 0;

    for (int i = 0; i < n * k; i++)
    {
        csum += arr[i % n];
        if (csum > gsum)
            gsum = csum;
        if (csum <= 0)
            csum = 0;
    }
    return (gsum % mod);
}
int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int Psum = 0;

    for (int i = 1; i <= 3; i++)
    {
        long sum = KadaneAlgo(arr, i);
        if (k == i)
        {
            return sum;
        }

        if (i == 3)
        {
            return (Psum + (k - 2) * (Psum - sum) % mod);
        }

        Psum = sum;
    }
    return 0;
}

// Max Sum Rectangle

int kadaneAlgoforNegative(vector<int> arr)
{
    int n = arr.size();
    int csum = 0, gsum = -1e9;

    for (int ele : arr)
    {
        csum = max(ele, csum + ele);
        gsum = max(gsum, csum);
    }
    return gsum;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int n = R, m = C, MaxSum = -1e9;

    for (int fixRow = 0; fixRow < n; fixRow++)
    {
        vector<int> colPrefixSum(m, 0);
        for (int row = fixRow; row < n; row++)
        {
            for (int col = 0; col < m; col++)
                colPrefixSum[col] += M[row][col];

            int sum = kadaneAlgoforNegative(colPrefixSum);
            MaxSum = max(MaxSum, sum);
        }
    }

    return MaxSum;
}

// if max sum rectangle is to be printed
vector<int> KadaneAlgo_subarray(vector<int> &arr)
{
    int gSum = -1e9, cSum = 0, gsi = 0, gei = 0, csi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        cSum += ele;
        if (ele > cSum)
        {
            cSum = ele;
            csi = i;
        }

        if (cSum > gSum)
        {
            gSum = cSum;
            gsi = csi;
            gei = i;
        }
    }
    return {gSum, gsi, gei};
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int n = R, m = C, MaxSum = -1e9;
    int r1 = 0, r2 = 0, c1 = 0 c2 = 0;

    for (int fixRow = 0; fixRow < n; fixRow++)
    {
        vector<int> colPrefixSum(m, 0);
        for (int row = fixRow; row < n; row++)
        {
            for (int col = 0; col < m; col++)
                colPrefixSum[col] += M[row][col];

            vector<int> res = kadaneAlgoforNegative(colPrefixSum);
            if (res[0] >= MaxSum)
            {
                MaxSum = res[0];
                r1 = fixRow;
                c1 = res[1];
                r2 = row;
                c2 = res[2];
            }
        }
    }

    return MaxSum;
}

// 781
int numRabbits(vector<int> &arr)
{
    vector<int> freq(1000, 0);
    int ans = 0;
    for (int ele : arr)
    {
        if (freq[ele] == 0)
            ans += ele + 1;
        freq[ele]++;

        if (freq[ele] == ele + 1)
            freq[ele] = 0;
    }
    return ans;
}

// 1074

int TargetSum(vector<int> &arr, int tar)
{
    int n = arr.size();
    unordered_map<int, int> map;
    map[0] = 1;
    int count = 0, sum = 0;

    for (int ele : arr)
    {
        sum += ele;
        count += map.find(sum - tar) != map.end() ? map[sum - tar] : 0;
        map[sum]++;
    }
    return count;
}
int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;

    for (int FixRow = 0; FixRow < n; FixRow++)
    {
        vector<int> colPrefixSum(m, 0);
        for (int row = FixRow; row < n; row++)
        {
            for (int col = 0; col < m; col++)
                colPrefixSum[col] += matrix[row][col];

            count += TargetSum(colPrefixSum, target);
        }
    }
    return count;
}
// if k is negative = (k%n + n)%n

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(vector<int> &arr, int i, int j)
{
    while (i < j)
        swap(arr, i, j);
}
void rotate(vector<int> &arr, int k)
{
    int n = arr.size();
    if (k < 0)
        k %= n;

    reverse(arr, 0, n - 1);
    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
}

// can also be done using 3 pointer approach

///////////////////

// segregating negative and postive nums in array

void segregatenegativeandPostive(vector<int> &arr)
{
    int n = arr.size();
    int ptr = -1, itr = 0;

    while (itr < n)
    {

        if (arr[itr] < 0)
            swap(arr[++ptr], arr[itr]);
        itr++;
    }
}

void segregateOneandZero(vector<int> &arr)
{
    int n = arr.size();
    int ptr = -1, itr = 0;

    while (itr < n)
    {

        if (arr[itr] == 0)
            swap(arr[++ptr], arr[itr]);
        itr++;
    }
}

int MaxSumwithRotation(vector<int> &arr, int n)
{
    int sum = 0, sumwithIndex = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sumwithIndex += arr[i] * i
    }

    int MaxSum = sum;

    for (int i = 1; i < n; i++)
    {
        sumwithIndex = sumwithIndex - sum + arr[i - 1] * n;
        MaxSum = max(MaxSum, sumwithIndex);
    }
    return MaxSum;
}

// 11

int maxArea(vector<int> &height)
{
    int n = height.size();
    int MaxArea = 0, i = 0, j = n - 1;

    while (i < j)
    {
        int w = j - i
                        MaxArea = if (arr[i] < arr[j]) ? max(MaxArea, (w * arr[i++])) : max(MaxArea, (w * arr[j--]));
    }
    return MaxArea;
}

// 3

int n = s.length();
vector<int> freq(128, 0);

int si = 0, ei = 0, len = 0, count = 0;
int gsi = 0, gei = 0;
while (ei < n)
{
    if (freq[s[ei++]]++ > 0)
        count++;

    while (count > 0)
        if (freq[s[si++]]-- > 1)
            count--;

    if (len < ei - si) // to print the required substring
    {
        len = ei - si;
        gsi = si;
        gei = ei;
    }
}
return len;
cout << s.substring(si, ei - si);

// 159

int LongestsubstringWithAtmostTwoDistinct(string s)
{
    int n = s.length();
    if (n <= 2)
        return n;

    vector<int> map(128, 0);

    int si = 0, ei = 0, count = 0, len = 0;

    while (ei < n)
    {
        if (map[s[ei++]]++ == 0)
            count++;

        while (count > 2)
        {
            if (map[s[si++]]-- == 1)
                count--;
        }
        len = max(len, ei - si);
    }
    return len;
}

// 76
string minWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();

    vector<int> map(128, 0);
    for (int i = 0; i < m; i++)
    {
        map[t[i]]++;
    }

    int si = 0, ei = 0, len = 1e9, count = m, gsi = 0;

    while (ei < n)
    {
        if (map[s[ei++]]-- > 0)
            count--;

        while (count == 0)
        {
            if (ei - si < len)
            {
                len = ei - si;
                gsi = si;
            }
            if (map[s[si++]]++ == 0)
                count++;
        }
    }
    return len == 1e9 ? "" : s.substr(gsi, len);
}

// smallest Window that contains distinct characters present in string(all characters)

int findSubString(string str)
{
    int n = str.length();
    vector<int> map(128, 0);
    int s = 0, e = 0, len = 1e9, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (map[str[i]] == 0)
        {
            map[str[i]] == 1;
            count++;
        }
    }

    while (e < n)
    {
        if (map[str[e++]]-- > 0)
            count--;

        while (count == 0)
        {
            if (e - s < len)
            {
                len = e - s;
            }
            if (map[str[s++]]++ == 0)
                count++;
        }
    }
    return len;
}

int findSubString(string s)
{
    int n = s.length();
    if (n <= 1)
        return n;

    vector<int> freq(128, 0);
    int count = 0, si = 0, ei = 0, len = 1e9, gsi = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq[s[i]] == 0)
        {
            freq[s[i]] = 1;
            count++;
        }
    }

    while (ei < n)
    {
        if (freq[s[ei++]]-- == 1)
            count--;

        while (count == 0)
        {
            while (ei - si < len)
            {
                len = ei - si;
                gsi = si;
            }
            if (freq[s[si++]]++ == 0)
                count++;
        }
    }
    return len;
}

// 340

int LongestsubstringWithAtmostKDistinct(string s, int k)
{
    int n = s.length();
    if (n <= k)
        return n;

    vector<int> map(128, 0);

    int si = 0, ei = 0, count = 0, len = 0;

    while (ei < n)
    {
        if (map[s[ei++]]++ == 0)
            count++;

        while (count > k)
        {
            if (map[s[si++]]-- == 1)
                count--;
        }
        len = max(len, ei - si);
    }
    return len;
}

// 1456
bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
int maxVowels(string s, int k)
{
    int n = s.length();

    int si = 0, ei = 0, Vowelcount = 0, MaxCount = 0;

    while (ei < n)
    {
        if (isVowel(s[ei++]))
            Vowelcount++;

        if (ei - si == k)
        {
            MaxCount = max(MaxCount, Vowelcount);
            if (isVowel(s[si++]))
                Vowelcount--;
        }
    }
    return MaxCount;
}

// 1248

int numberAtMostkSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> freq(50001, 0);
    int si = 0, ei = 0, subcount = 0, oddcount = 0;

    while (ei < n)
    {
        if (nums[ei++] % 2 != 0)
            oddcount++;

        while (oddcount > k)
        {
            if (nums[si++] % 2 != 0)
                oddcount--;
        }
        subcount += ei - si;
    }
    return subcount;
}
int numberOfSubarrays(vector<int> &nums, int k)
{

    return numberAtMostkSubarrays(nums, k) - numberAtMostkSubarrays(nums, k - 1);
}

// 992 using map
int subsarrayWithatmostKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    int si = 0, ei = 0, count = 0, ans = 0;
    unordered_map<int, int> map;

    while (ei < n)
    {
        map[nums[ei++]]++;
        while (map.size() > k)
        {
            if (map[nums[si++]]-- == 1)
                map.erase(nums[si - 1]);
        }
        ans += ei - si;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return subsarrayWithatmostKDistinct(nums, k) - subsarrayWithatmostKDistinct(nums, k - 1);
}

// using vector
int subsarrayWithatmostKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    int si = 0, ei = 0, count = 0, ans = 0;
    vector<int> map(20000 + 1, 0);

    while (ei < n)
    {
        if (map[nums[ei++]]++ == 0)
            count++;
        while (count > k)
        {
            if (map[nums[si++]]-- == 1)
                count--;
        }
        ans += ei - si;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return subsarrayWithatmostKDistinct(nums, k) - subsarrayWithatmostKDistinct(nums, k - 1);
}

// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int longestKSubstr(string s, int k)
{
    int n = s.length();
    int si = 0, ei = 0, len = -1, count = 0;
    vector<int> map(128, 0);

    while (ei < n)
    {
        if (map[s[ei++]]++ == 0)
            count++;

        while (count > k)
        {
            if (map[s[si++]]-- == 1)
                count--;
        }
        if (count >= k)
            len = max(len, ei - si);
    }
    return len;
}

// 904
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    vector<int> map(100000 + 1, 0);

    int si = 0, ei = 0, count = 0, len = 0;

    while (ei < n)
    {
        if (map[fruits[ei++]]++ == 0)
            count++;

        while (count > 2)
        {
            if (map[fruits[si++]]-- == 1)
                count--;
        }
        len = max(len, ei - si);
    }
    return len;
}

// 930
int atMostSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    int si = 0, ei = 0, sum = 0, count = 0;

    while (ei < n)
    {
        sum += nums[ei++];
        while (sum > goal)
            sum -= nums[si++];

        count += ei - si;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMostSum(nums, goal) - (goal != 0 ? atMostSum(nums, goal - 1) : 0);
}

// 485
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int si = 0, ei = 0, len = 0;

    while (ei < n)
    {
        if (nums[ei++] == 0)
            si = ei;

        len = max(len, ei - si);
    }
    return len;
}

// 487
int findMaxConsecutiveOnesII(vector<int> &nums)
{
    int n = nums.size();
    int si = 0, ei = 0, len = 0, count = 0;

    while (ei < n)
    {
        if (nums[ei++] == 0)
            count++;

        while (count > 1)
        {
            if (nums[si++] == 0)
                count--;
        }
        len = max(len.ei - si);
    }
    return len;
}

int findMaxConsecutiveOnesII(vector<int> &nums)
{
    int n = nums.size();
    int si = 0, ei = 0, len = 0, FirstZerIndex = -1;

    while (ei < n)
    {
        if (nums[ei++] == 0)
        {
            si = FirstZerIndex + 1;
            FirstZerIndex = ei - 1;
        }

        len = max(len.ei - si);
    }
    return len;
}

// 1004
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int si = 0, ei = 0, count = 0, len = 0;

    while (ei < n)
    {
        if (nums[ei++] == 0)
            count++;

        while (count > k)
            if (nums[si++] == 0)
                count--;

        len = max(len, ei - si);
    }
    return len;
}

// 974
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int ei = 0, ans = 0, sum = 0;
    vector<int> rem(k, 0);
    rem[0] = 1;

    while (ei < n)
    {
        sum += nums[ei++];
        int r = (sum % k + k) % k;

        ans += rem[r];
        rem[r]++;
    }
    return ans;
}

// Longest subarray divisible by k
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int ei = 0, len = 0, sum = 0;
    vector<int> rem(k, -2);
    rem[0] = -1;

    while (ei < n)
    {
        sum += nums[ei];
        int r = (sum % k + k) % k;

        if (rem[r] == -2)
            rem[r] = ei;
        else
            len = max(len, ei - rem[r]);

        ei++;
    }
    return len;
}

// https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    unordered_map<int, int> map;
    map[0] = 1;
    int ei = 0, sum = 0, count = 0;

    while (ei < n)
    {
        int val = arr[ei++];
        sum += val;
        if (val == 0)
            sum += -1;

        count += map[sum];
        map[sum]++;
    }
    return count;
}

// 525

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int ei = 0, len = 0, sum = 0;
    unordered_map<int, int> map;
    map[0] = -1;

    while (ei < n)
    {
        int val = nums[ei];
        sum += val;
        if (val == 0)
            sum += -1;

        if (map.find(sum) == map.end())
            map[sum] = ei;
        len = max(len, ei - map[sum]);
        ei++;
    }
    return len;
}

// 239  O(n.logn)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans(n - k + 1);
    int idx = 0;

    priority_queue<vector<int>> pq; //{val,index}

    for (int i = 0; i < n; i++)
    {
        while (pq.size() != 0 && pq.top()[1] <= i - k)
            pq.pop();

        pq.push({nums[i], i});

        if (i >= k - 1)
        {
            ans[idx++] = pq.top()[0];
        }
    }
    return ans;
}

// 239  O(n)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans(n - k + 1);
    int idx = 0;

    list<int> deque; //{val,index}

    for (int i = 0; i < n; i++)
    {
        while (deque.size() != 0 && deque.front() <= i - k)
            deque.pop_front();

        while (deque.size() != 0 && nums[deque.back()] <= nums[i])
            deque.pop_back();

        deque.push_back(i);

        if (i >= k - 1)
        {
            ans[idx++] = nums[deque.front()];
        }
    }
    return ans;
}
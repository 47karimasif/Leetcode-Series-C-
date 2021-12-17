class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        vector<int> ans;
        int asumf = 0, bsumf = 0;
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());

        for (auto x : aliceSizes)
        {
            asumf += x;
        }
        for (auto x : bobSizes)
        {
            bsumf += x;
        }

        for (int i = 0; i < aliceSizes.size(); i++)
        {
            int asum = asumf - aliceSizes[i];
            int bsum = bsumf + aliceSizes[i];
            int v = (bsum - asum) / 2;
            int searchIndex = BinarySearch(bobSizes, v);
            if (searchIndex != -1)
            {
                ans.push_back(aliceSizes[i]);
                ans.push_back(bobSizes[searchIndex]);
                return ans;
            }
        }
        return ans;
    }

    int BinarySearch(vector<int> w, int v)
    {
        int l = 0, h = w.size();
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (w[m] == v)
            {
                return m;
            }
            else if (w[m] > v)
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return -1;
    }
};
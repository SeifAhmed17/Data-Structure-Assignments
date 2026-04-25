bool exists(vector<int>& arr, int x) {
    for (int num : arr)
        if (num == x)
            return true;
    return false;
}
vector<int> removeDuplicates(vector<int>& arr) {
    vector<int> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1])
            res.push_back(arr[i]);
    }
    return res;
}
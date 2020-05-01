/*
Time Complexity: O(n)
DS used: Deque
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> nums, int k) {
    deque<int> q(k);
    int i;
    vector<int> res;
    int n = nums.size();

    // for the first window
    for(i=0; i<k; i++){
    	// removing previous smaller elements
    	// if q becomes empty, simply push
        while(!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);
    } // q is always in descending order
    // max is at front
    // max of first window stored
    res.push_back(nums[q.front()]);

    // for remaining n-k elements
    // shifting the window
    for(i=k; i<n; i++){

    	// removing element which is not of current window
        if(q.front() == i-k)
            q.pop_front();

        // removing previous smaller elements
    	// if q becomes empty, simply push
        while(!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);

        // store max of this window
        res.push_back(nums[q.front()]);
    }
    return res;
}

vector<int> minSlidingWindow(vector<int> nums, int k) {
    deque<int> q(k);
    int i;
    vector<int> res;
    int n = nums.size();

    for(i=0; i<k; i++){
    	// removing previous larger elements
    	// if q becomes empty, simply push
        while(!q.empty() && nums[i] <= nums[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    res.push_back(nums[q.front()]);

    for(i=k; i<n; i++){

        if(q.front() == i-k)
            q.pop_front();

        // removing previous larger elements
    	// if q becomes empty, simply push
        while(!q.empty() && nums[i] <= nums[q.back()])
            q.pop_back();
        q.push_back(i);

        res.push_back(nums[q.front()]);
    }
    return res;
}

int main() {
	vector<int> nums;
	nums = {8, 4, 5, 1, 7}; // array
	int k = 3; // window size

	vector<int> max = maxSlidingWindow(nums, k);
	vector<int> min = minSlidingWindow(nums, k);

	int nMax = max.size();
	int nMin = min.size();
	int i;

	// printing max elemets of each window
	for(i=0; i<nMax; i++)
		cout << max[i] << " ";
	cout << endl;

	// printing min elemets of each window
	for(i=0; i<nMin; i++)
		cout << min[i] << " ";
	cout << endl;

	return 0;
}

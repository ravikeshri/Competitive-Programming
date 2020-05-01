/*
Time Complexity: O(n)
DS used: Stack
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, i=0, s_top; //s_top to store just popped value from stack
    stack <int> s; //stack
    cin >> n;
    int h[n]; // histogram
    for(i=0; i<n; i++)
        cin >> h[i];
    int area; // area to store area of rectangle with s_top element as least
    int max_area = 0; // max_area to store largest area

    for(i=0; i<n; i++){
	// either stack is empty or next element is larger than the previous one, push index into stack
        if(s.empty() || h[s.top()] <= h[i])
            s.push(i);

        else{
	// pop the top element and considering top as least, find area
            s_top = s.top();
            s.pop();
            if(s.empty())
                area = h[s_top]*i; // stack empty means no elemt in left, so width is  i
            else
                area = h[s_top]*(i - s.top() - 1); // here i denotes index of just right smaller element
						   // s.top() denotes index of just left smaller element
						   // width = ( right - left - 1 )
            if(max_area < area)
                max_area = area;
            i--; // to continue the pop operation until all the left elements are equal or greater
        }
    }
    // all the ements added to the stack in non-descending order
    // so finding all possible areas with the remaining elements of the stack

    while(!s.empty()){
        s_top = s.top();
        s.pop();
        if(s.empty())
            area = h[s_top]*i;
        else
            area = h[s_top]*(i - s.top() - 1);
        if(max_area < area)
            max_area = area;
    }
    cout << max_area;
    return 0;
}

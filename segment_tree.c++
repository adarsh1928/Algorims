#include<bits/stdc++.h>
using namespace std;


class SegmentTree {
    vector<int> seg; // Segment Tree to be stored in a vector.
public:
    SegmentTree() {}
    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n, 0);  // Maximum size of a segment tree for an array of size n is 4n
        buildTree(nums, 0, 0, n - 1); // Build the segment tree
    }
    void buildTree(vector<int>& nums, int pos, int left, int right) {
        if (left == right) {
            seg[pos] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(nums, 2 * pos + 1, left, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, right);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
    void updateTree(int pos, int left, int right, int index, int val) {
        // no overlap
        if(index <left || index >right) return;
        
        // total overlap
        if(left==right){
            if(left==index)
                seg[pos]=val;
            return;
        }

        // partial overlap
        int mid=(left+right)/2;
        updateTree(2*pos+1,left,mid,index,val); // left child
        updateTree(2*pos+2,mid+1,right,index,val); // right child
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }

    
    int queryTree(int qleft, int qright, int left, int right, int pos) {
        if (qleft <= left && qright >= right) { // total overlap
            return seg[pos];
        }
        if (qleft > right || qright < left)  {  // no overlap
            return 0;
        }
        // partial overlap
        int mid = left + (right - left) / 2;
        return queryTree(qleft, qright, left, mid, 2 * pos + 1) + queryTree(qleft, qright, mid + 1, right, 2 * pos + 2);
    }
};

class NumArray {
    SegmentTree st;
    int n;  // Length of the num vector. 
public:
// Each node at 'k' can access their child at 2k+1, 2k+2
// Each node can access its parent at (k-1)/2
    NumArray(vector<int>& nums) {
        this->st = SegmentTree(nums);
        this->n = nums.size();
    }
    
    void update(int index, int val) {
        st.updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return st.queryTree(left, right, 0, n - 1, 0);
    }
};
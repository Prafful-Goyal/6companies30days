//PROBLEM STATEMENT
/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
Implement KthLargest class:
KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
*/
//CODE
class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> pq;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        if(nums.size() >= k){
            for(int i = 0; i < k; i++){
                pq.push(nums[i]);
            }
            for(int i = k; i < nums.size(); i++){
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        else{
            if(nums.size() != 0){
                for(int i = 0; i < nums.size();i++){
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(x > pq.size()){
            pq.push(val);
        }
        else{
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

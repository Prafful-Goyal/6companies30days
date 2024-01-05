//PROBLEM STATEMENT
/*
For a stream of integers, implement a data structure that checks if the last k integers parsed in the stream are equal to value.

Implement the DataStream class:

DataStream(int value, int k) Initializes the object with an empty integer stream and the two integers value and k.
boolean consec(int num) Adds num to the stream of integers. Returns true if the last k integers are equal to value, and false otherwise. If there are less than k integers, the condition does not hold true, so returns false.
*/

//APPROACH(We Use a Queue and Map For this question and if queue.size()>k then we simple erase q.front() from map and also pop from queue and if mp.size()==1 and value is present in the map then we return true
//otherwise return false)
/*
  T.C = O(1)
  S.C = O(1)
*/
class DataStream {
public:
    unordered_map<int,int>mp;
    queue<int>q;
    int K,val;
    DataStream(int value, int k) {
        this->K = k;
        this->val = value;
    }
    
    bool consec(int num) {
        q.push(num);
        mp[num]++;
        if(q.size()>=K)
        {
            if(q.size()>K)
            {
                mp[q.front()]--;
                if(mp[q.front()]==0)
                {
                    mp.erase(q.front());
                }
                q.pop();
            }
            if(mp.size()==1&&mp[val]>0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;

using std::vector;
using std::map;

class Solution
{
public:
    Solution() {};
    ~Solution() {};

    vector<int> twoSum(vector<int> &numbers, int target) {

        // convert vector to map
        map<int, vector<int> > dmap;
        map<int, vector<int> >::iterator m_it;
        for(vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            m_it = dmap.find(*it);
            if (m_it == dmap.end()) {
                vector<int> vc;
                vc.push_back(it - numbers.begin() + 1);
                dmap[*it] = vc;
            } else {
                dmap[*it].push_back(it - numbers.begin() + 1);
            }
        }

        int key = 0;
        int remain = 0;
        int index1 = 0;
        int index2 = 0;
        // use map to get the solution
        for (map<int, vector<int> >::const_iterator it = dmap.begin(); it != dmap.end(); it++)
        {
            key = it->first;
            remain = target - key;
            index1 = it->second[0];
            m_it = dmap.find(remain);
            if (m_it != dmap.end()) {
                if (m_it == it) {
                    index2 = m_it->second[1];
                } else {
                    index2 = m_it->second[0];
                }
                break;
            }
        }
        if(index1 > index2) {
            int tmp;
            tmp = index1;
            index1 = index2;
            index2 = tmp;
        }

        vector<int> ret;
        ret.push_back(index1);
        ret.push_back(index2);
        return ret;
    }
};


int main()
{
    Solution *sol = new Solution();
    int tmp[] = {2, 7, 14, 11, 15};
    vector<int> numbers(tmp, tmp + 4);
    int target = 25;
    vector<int> ret = sol->twoSum(numbers, target);
    cout<< "(";
    for(vector<int>::const_iterator iter = ret.begin(); iter != ret.end(); iter++) 
    {
     cout << *iter << " ";
    }
    cout << ")" << endl;

    return 0;
}

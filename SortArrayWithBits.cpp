#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

// Complete rearrange function
// DO NOT MODIFY anything outside the below function

struct ElementInfo
{
    ElementInfo(int value, int bits) : m_value(value), m_setBits(bits)
    {}
    int m_value;
    int m_setBits;
};

std::list<ElementInfo> mylist;

int setBitsCount(int n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

void printList()
{
    cout << "printList: =========START==========" << endl;
    std::list<ElementInfo>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it)
    {
        cout << "printList:  value="<< it->m_value <<" bits="<<it->m_setBits << endl;
    }
    cout << "printList: ==========END=========" << endl;
}

void addIntoList(int value, int setBits)
{
    cout << "addIntoList: ===|||||||||=== value="<< value <<" bits="<<setBits << endl;
    
    if (mylist.size() == 0) {
        mylist.push_back(ElementInfo(value, setBits));
        return;
    }
    
    std::list<ElementInfo>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it)
    {
        cout << "addIntoList: iterator value="<< it->m_value <<" bits="<<it->m_setBits << endl;
        
        if (setBits < it->m_setBits) {
            mylist.insert(it, ElementInfo(value, setBits));
            break;
        }
        else if (setBits == it->m_setBits) 
        {
            if (value < it->m_value) {
                mylist.insert(it, ElementInfo(value, setBits));
                break;
            }
            else if (value > it->m_value) {
                ++it;
                if (it != mylist.end() && setBits==it->m_setBits)
                    --it;
                else {
                    mylist.insert(it, ElementInfo(value, setBits));
                    break;
                }
            }
            else 
                break;  
        }
    }
    printList();
}

vector<int> rearrange(vector<int> elements) {
    vector<int> res;
    
    int elem;
    for (int i = 0; i < elements.size(); ++i) {
        elem = elements[i];
        addIntoList(elem, setBitsCount(elem));
    }
    
    std::list<ElementInfo>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it)
    {
        res.push_back(it->m_value);
    }
 
    return res;
}
// DO NOT MODIFY anything outside the above function

int test_rearrange() {
    /* Read input from STDIN. Print output to STDOUT */
 
    vector<int> elements;
   
    elements.push_back(3);
    elements.push_back(1);
    elements.push_back(2);
    elements.push_back(5);
    elements.push_back(4);
    elements.push_back(16);
    elements.push_back(8);
    elements.push_back(3);
    
    
    // call rearrange function
    vector<int> sorted_elements = rearrange(elements);
    
    for (int i = 0; i < sorted_elements.size(); ++i) {
        cout << "sorted_elements =" <<sorted_elements[i] << endl;
    }
    return 0;
}


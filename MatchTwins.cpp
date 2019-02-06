#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


// Complete twins function
// DO NOT MODIFY anything outside the below function
void swapEvenOdd(string& a, string& b, int start)
{
    if (a.length() != b.length()) return;
    for(int i = start; i < a.length(); i+=2)
    {
        //cout<<endl <<"swapEvenOdd i="<<i <<"  a[i]= "<<a[i] <<" b[i]="<<b[i] <<endl;
        if (a[i] != b[i]) {
            for(int j = i+2; j < a.length(); j+=2)
            {
                //cout<<"swapEvenOdd j="<<j <<"  a[j]= "<<a[j] <<" b[i]="<<b[i] <<endl;
                if (a[j] == b[i]) {
                    std::swap(a[i], a[j]);
                    //cout << "swapEvenOdd a="<<a;
                }
            }
        }
    }
}

vector<string> twins(const vector<string>& a, const vector<string>& b) {
    vector<string> res;
    
    string aStr, bStr;
    vector<string>::const_iterator it  = a.begin();
    vector<string>::const_iterator it2 = b.begin();
    
    for (; it != a.end() && it2 != b.end(); ++it, ++it2) 
    {
        aStr = *it;
        bStr = *it2;
        swapEvenOdd(aStr, bStr, 0);
        swapEvenOdd(aStr, bStr, 1);
        
        cout << endl << "twins------ aStr="<<aStr <<" bStr="<<bStr << endl;
        if (aStr == bStr)
            res.push_back("Yes");
        else
            res.push_back("No");
    } 

    return res;
}
// DO NOT MODIFY anything outside the above function


int testMain() {
    /* Read input from STDIN. Print output to STDOUT */
 
    vector<std::string> a, b;
    
    a.push_back("cdab");
    a.push_back("dcba");
    
    b.push_back("abcd");
    b.push_back("abcd");
        
    // call twins method
    vector<string> res = twins(a, b);
    
    for (vector<string>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}


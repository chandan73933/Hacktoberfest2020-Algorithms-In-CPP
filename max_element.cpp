#include <vector>

#include <set>

#include <algorithm>

#include <iostream>

using namespace std;

 

class CInt;

ostream& operator<<(ostream& osIn, const CInt& rhs);

 

class CInt

{

    public:

       CInt(int n = 0) : m_nVal(n){}

       CInt(const CInt& rhs) : m_nVal(rhs.m_nVal){}

       CInt& operator=(const CInt& rhs)

       {    m_nVal = rhs.m_nVal; return *this;    }

       bool operator<(const CInt& rhs) const

       {    return (m_nVal < rhs.m_nVal);    }

      friend ostream& operator<<(ostream& osIn, const CInt& rhs);

    private:

       int m_nVal;

};

 

inline ostream& operator<<(ostream& osIn, const CInt& rhs)

{

   osIn<<"CInt("<<rhs.m_nVal<<")";

   return osIn;

}

 

// return whether modulus of elem1 is greater than modulus of elem2

bool mod_lesser(int elem1, int elem2)

{

   if(elem1 < 0)

      elem1 = - elem1;

   if(elem2 < 0)

      elem2 = - elem2;

   return (elem1 < elem2);

};

 

int main()

{

    // searching a set container with elements of type CInt for the maximum element

    CInt c1 = 1, c2 = 2, c3 = -3;

    set<CInt> st1;

    set<CInt>::iterator st1_Iter, st2_Iter, st3_Iter;

    st1.insert(c1);

    st1.insert(c2);

    st1.insert(c3);

    cout<<"st1 data: ";

    for(st1_Iter = st1.begin(); st1_Iter != --st1.end(); st1_Iter++)

        cout<<" "<<*st1_Iter<<",";

    st1_Iter = --st1.end();

    cout<<" "<<*st1_Iter<<endl;

    st2_Iter = max_element(st1.begin(), st1.end());

    cout<<"The largest element in st1 is: "<<*st2_Iter<<endl;

    cout<<endl;

    // searching a vector with elements of type int for the maximum

    // element under default less than & mod_lesser binary predicates

    vector <int> vec;

    vector <int>::iterator vec_Iter, vec1_Iter, vec2_Iter;

    int i;

    for(i = 0; i <= 3; i++)

    vec.push_back(i);

    int j;

    for(j = 1; j <= 4; j++)

        vec.push_back(-j);

    cout<<"Vector vec data: ";

    for(vec_Iter = vec.begin(); vec_Iter != vec.end(); vec_Iter++)

        cout<<*vec_Iter<<" ";

    cout<<endl;

    vec1_Iter = max_element(vec.begin(), vec.end());

    vec2_Iter = max_element(vec.begin(), vec.end(), mod_lesser);

    cout<<"The largest element in vec is: "<<*vec1_Iter<<endl;
    cout<<"The largest element in vec under the\nmod_lesser binary predicate is: "<<*vec2_Iter<<endl;

    return 0;

}

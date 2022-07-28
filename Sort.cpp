#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
using namespace std ;

struct freq
{
    int n ;
    int index ;
    int count ;
};


bool compare(freq a, freq b)
{
    if( a.count == b.count)
    {
        return a.index < b.index ;
    }
    return a.count > b.count ;
}

int main ()
{
    int n, m, num ;
    cout << "Enter n & m : " ;
    cin >> n >> m ;

    map<int, pair<int, int>> freqandindexmap;

    for (int i=0 ; i<n ; i++)
    {
        cout << "Enter a value" ;
        cin >> num ;
        
        map<int, pair<int, int>> :: iterator it = freqandindexmap.find(num) ;
        if (it == freqandindexmap.end())
        {
            freqandindexmap[num] = make_pair(i,1) ;
        }
        else
        {
            freqandindexmap[num].second++ ;
        }
    }
    vector<freq> v;
        
        for(map<int,pair<int,int>> :: iterator it = freqandindexmap.begin() ; it != freqandindexmap.end() ; it++ )
        {
            freq temp_freq ;
            temp_freq.n = it->first ;
            temp_freq.index = it->second.first ;
            temp_freq.count = it->second.second ;
            v.push_back(temp_freq) ;
        }
    sort(v.begin(), v.end(), compare) ;

    for(vector<freq> :: iterator it = v.begin(); it != v.end(); it++)
    {
        for(int i = 0 ; i < it->count ; i++  )
        {
            cout << it->n << " " ;
        }
    }

    return 0 ; 

}
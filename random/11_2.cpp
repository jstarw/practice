#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

void sortAnagram(vector<string> &v) {
    sort(v.begin(), v.end());
}

void sortAnagram2(vector<string> &v) {
    map<string, list<string> > hashMap;
    for (int i=0; i<v.size(); i++) {
        string key = v[i];
        sort(key.begin(), key.end());
        if (hashMap[key].empty()) {
            list<string> value;
            hashMap[key] = value;
        }
        hashMap[key].push_back(v[i]);
    }

    //reconstruct the array
    int index = 0;
    map<string, list<string> >::iterator i;
    for (i = hashMap.begin(); i!=hashMap.end(); i++) {
        list<string> value = i->second;
        for (list<string>::iterator i=value.begin(); i!=value.end(); i++) {
            v[index] = *i;
            index++;
        }
    }
}

int main(int argc, char const *argv[])
{
    string staticArr[] = {"asdf", "ghjk", "dsfa", "hjkg", "cool", "nice", "looc", "ecind"};
    vector<string> arr;

    for (int i=0; i<sizeof(staticArr)/sizeof(*staticArr); i++) {
        arr.push_back(staticArr[i]);
    }
    sortAnagram2(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        cout<<arr[i]<<" ";
    }
}
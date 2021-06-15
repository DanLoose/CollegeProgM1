#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Data {
  int Value1;
  int Value2;
};

struct cotacao{
    string data;
    int valor;
};

map<string, map<string, vector<Data> > > myMap;

void addData(string Date1, string Date2, int V1, int V2) {
  Data myData;
  myData.Value1 = V1;
  myData.Value2 = V2;
  myMap[Date1][Date2].push_back(myData);
}


int main() {
  int iTotal = 0;

  addData("vale", "Blah2", 1, 1);
  addData("vale", "Blah2", 1, 1);
  addData("brad", "Blah1", 1, 1);
  addData("brad", "Blah3", 1, 1);

  cout << "There Are " << myMap.size() << " different Date1's" << endl;

  // Loop Through Each Date1, Count How many Date2's Each Date1 Has.
  map<string, map<string, vector<Data> > >::iterator vPtr = myMap.begin();
  while (vPtr != myMap.end()) {
    cout << "Date1: " << (*vPtr).first << " has " << myMap[(*vPtr).first].size() << " different Date2s" << endl;
    iTotal += myMap[(*vPtr).first].size();
    vPtr++;
  }
  cout << "There are a total of " << iTotal << " dDate2's across your Date1's" << endl;

  cout << "Printing Pairs: " << endl;
  // Loop Through And List of All Date2s
  vPtr = myMap.begin();
  while (vPtr != myMap.end()) {
    // Create Date2 Iterator
    map<string, vector<Data> >::iterator v2Ptr = myMap[(*vPtr).first].begin();
    while (v2Ptr != myMap[(*vPtr).first].end()) {
      cout << "Pair: " << (*vPtr).first << " : " << (*v2Ptr).first << endl;
      v2Ptr++;
    }
    vPtr++;
  }

  return 0;
}

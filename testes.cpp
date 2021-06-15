#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Data
{
  int Value1;
  int Value2;
};

struct cotacao
{
  string data;
  int valor;
};

map<string, map<string, vector<cotacao>>> myMap;

void addData(string Date1, string Date2, string V1, int V2)
{
  cotacao myData;
  myData.data = V1;
  myData.valor = V2;
  myMap[Date1][Date2].push_back(myData);
}

int main()
{
  int iTotal = 0;

  addData("vale", "Blah2", "ontem", 1);
  addData("vale", "Blah2", "ontem", 1);
  addData("brad", "Blah1", "amanha", 1);
  addData("brad", "Blah3", "hoje", 1);

  cout << "There Are " << myMap.size() << " different Date1's" << endl;

  // Loop Through Each Date1, Count How many Date2's Each Date1 Has.
  map<string, map<string, vector<cotacao>>>::iterator vPtr = myMap.begin();
  while (vPtr != myMap.end())
  {
    cout << "Date1: " << (*vPtr).first << " has " << myMap[(*vPtr).first].size() << " different Date2s" << endl;
    iTotal += myMap[(*vPtr).first].size();
    vPtr++;
  }
  cout << "There are a total of " << iTotal << " dDate2's across your Date1's" << endl;

  cout << "Printing Pairs: " << endl;
  // Loop Through And List of All Date2s
  vPtr = myMap.begin();
  while (vPtr != myMap.end())
  {
    // Create Date2 Iterator
    map<string, vector<cotacao>>::iterator v2Ptr = myMap[(*vPtr).first].begin();
    while (v2Ptr != myMap[(*vPtr).first].end())
    {
      cout << "Pair: " << (*vPtr).first << " : " << (*v2Ptr).first << endl;
      v2Ptr++;
    }
    vPtr++;
  }

  return 0;
}

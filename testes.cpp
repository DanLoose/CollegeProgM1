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

map<string, vector<cotacao>> historicoBovespa;

void addCotacao(string sigla, string data, int valor)
{
  cotacao minhaCotacao;
  minhaCotacao.data = data;
  minhaCotacao.valor = valor;
  historicoBovespa[sigla].push_back(minhaCotacao);
}

int main()
{

  addCotacao("vale", "ontem", 1);
  addCotacao("vale", "ontem", 1);
  addCotacao("vale", "ontem", 1);
  addCotacao("brad", "amanha", 1);
  addCotacao("brad", "hoje", 1);

  cout << "existem " << historicoBovespa.size() << " acoes diferentes" << endl;

  // loop que retorna quantos elementos tem cada chave
  map<string, vector<cotacao>>::iterator vPtr = historicoBovespa.begin();
  while (vPtr != historicoBovespa.end())
  {
    cout << "acao: " << (*vPtr).first << " possui " << (*vPtr).second.size() << " registros" << endl;
    vPtr++;
  }

  vPtr = historicoBovespa.begin();
  while (vPtr != historicoBovespa.end())
  {
    cout << "acao: " << (*vPtr).first << " ";

    vector<cotacao>::iterator v2Ptr = historicoBovespa[(*vPtr).first].begin();
    while (v2Ptr != historicoBovespa[(*vPtr).first].end())
    {
      cout << "data: " << (*v2Ptr).data << " valor: " << (*v2Ptr).valor << " | ";
      v2Ptr++;
    }
    cout << endl;
    vPtr++;
  }


  return 0;
}

#ifndef HASH_H
#define HASH_H
#include <string>
using namespace std;
class hash
{
  public:
    hash();
    virtual ~hash();
    string arquivoToString(ifstream *arquivo);
    int* strToInt(string *str);
  protected:

  private:


};


#endif // HASH_H

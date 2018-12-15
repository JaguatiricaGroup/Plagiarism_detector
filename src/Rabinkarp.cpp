#include "Rabinkarp.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Rabinkarp::Rabinkarp(vector<string> diretoriosPA,vector<string> diretoriosNP,int tamanhoPadrao){
    ifstream original,plagio;
    //original.open(originalName);
    //plagio.open(plagioName);
    this->numeroNP=0;
    this->diretoriosNP=diretoriosNP;
    this->diretoriosPA=diretoriosPA;
//    this->plagio=arquivoToString(&plagio);
//    this->original=arquivoToString(&original);
    this->tamanhoPadrao=tamanhoPadrao;
    this->h=1;
    //this->lasVegas = qualHash!='r' ? false : true;
    //this->totalPadroes=0;
    this->hashPadrao=0;
    this->numeroPa=0;
    this->hashOriginal=0;
//    this->totalPadroesBernstein=0;
//    this->totalPadroesFNV=0;
    hashPaBurn.resize(qtdPa);
    hashPaFNV.resize(qtdPa);
    hashPaRK.resize(qtdPa);
    for(int l=0;l < qtdPa;l++){
        hashPaBurn[l].resize(TAM_TABELA);
        hashPaFNV[l].resize(TAM_TABELA);
        hashPaRK[l].resize(TAM_TABELA);
    }

    //for(numeroPa=0;numeroPa < qtdPa;numeroPa++)
    //    for(int i=0;i+tamanhoPadrao<TAM_TABELA;i++)
    //        hashPaBurn[numeroPa][i].push_back("nada");
    //for(numeroPa=0;numeroPa < qtdPa;numeroPa++)
    //    for(int i=0;i < TAM_TABELA;i++)
    //    if(! hashPaBurn[numeroPa][i].empty())
     //   cout << hashPaBurn[numeroPa][i].front();
//    for(int k=0;k<diretoriosPA.size();k++)
//        cout<< diretoriosPA.at(k)<< endl;
//    for(int k=0;k<diretoriosNP.size();k++)
//        cout<< diretoriosNP.at(k)<< endl;
    geraEstruturaPA();

    //this->totalPadroesRK=0;
    //this->qualHash=qualHash;
    //this->tamanhoOriginal=this->original.size();
//    colisoesRK=new string[TAM_TABELA];
 //   colisoesB=new string[TAM_TABELA];
//    colisoesFNV=new string[TAM_TABELA];
    //indColisoes=new int[TAM_TABELA];
 //   for(int i=0;i<TAM_TABELA;i++)
   //     indColisoes[i]=0;
    //cout << this->plagio << endl;
    //cout << this->original << endl;

}

Rabinkarp::~Rabinkarp(){
//    delete [] colisoesRK,colisoesB,colisoesFNV;
//    delete [] indColisoes;
}
void Rabinkarp::geraEstruturaPA(){
    cout << diretoriosPA.at(0)<<endl;
    for(numeroPa=0;numeroPa < qtdPa;numeroPa++){
        original=arquivoToString(diretoriosPA.at(numeroPa));
        //cout << "v" << endl;
        //hashPaBurn[numeroPa][3].push_back("nada");
        //cout << hashPaBurn[numeroPa][3].front();
        for(int i=0; i+tamanhoPadrao < original.size();i++){
            string p=original.substr(i,tamanhoPadrao);
            //cout <<p<<" "<<bernstein_hash(p)<<" "<<fnv_hash(p) <<" "<< rk_hash(p)  << endl;
            hashPaBurn.at(numeroPa).at(bernstein_hash(p)).push_back(diretoriosPA.at(numeroPa));
            //cout << diretoriosPA[numeroPa]<< endl;
            //cout << bernstein_hash(p)<<" "<<fnv_hash(p) <<" "<< rk_hash(p)  << endl;
            hashPaFNV.at(numeroPa).at(fnv_hash(p)).push_back(diretoriosPA.at(numeroPa));
            hashPaFNV.at(numeroPa).at(rk_hash(p)).push_back(diretoriosPA.at(numeroPa));
        }
    }
}

void Rabinkarp::printTotalPadroes(){
//    double j= ((float)totalPadroesRK/tamanhoOriginal);
//    cout <<"colisoes usando hash de bernstein" <<"  "<< totalPadroesBernstein <<"  " << "de"<<" " <<tamanhoOriginal<<" "
//    << ((float)totalPadroesBernstein/tamanhoOriginal)*100<<"%"<<endl;
//    cout <<"colisoes usando hash FNV" <<"  " << totalPadroesFNV <<"  " << "de" <<" "<<tamanhoOriginal<<" "
//    << ((float)totalPadroesFNV/tamanhoOriginal)*100<<"%"<<endl;
//    cout <<"colisoes usando hash RK" <<"  " << totalPadroesRK <<"  " << "de" <<" "<<tamanhoOriginal<<" "
//    <<((float)totalPadroesRK/tamanhoOriginal)*100<<"%"<<endl;
}

void Rabinkarp::printColisoes(){
    for(int i=0;i < TAM_TABELA;i++){
        // cout << "ind" <<" "<< setw(4) << i <<" " << "strin :"<< colisoes[i]<< endl;
    }
}

unsigned  Rabinkarp::fnv_hash(string s){
    unsigned long h = BASE_FNV;
    for (int i = 0; i < tamanhoPadrao; i++){
        h = (h * PRIMO_FNV) ^ s[i];
    }
    return h%TAM_TABELA;
}

unsigned Rabinkarp::bernstein_hash (string p){
    unsigned h = 0;
    for (int i = 0; i < tamanhoPadrao; i++ )
        h = 33 * h + p[i];
    return h%TAM_TABELA;
}

int Rabinkarp::rk_hash(string p){
    int hash_RK=0;h=1;
    for (int i = 0; i < tamanhoPadrao-1; i++)//calcula h = d elevado tamapat-1
          h = (h*numCaractAlfabeto) % TAM_TABELA;
    for (int i = 0; i < tamanhoPadrao; i++)
      hash_RK = (numCaractAlfabeto*hash_RK + p[i]) % TAM_TABELA ;
      return hash_RK%TAM_TABELA;
}

void Rabinkarp::searchRK(){
    hashPadrao=0;
    hashOriginal=0;
    //int h=1;
    //int k=0;
    totalColisoesRK.push_back(0);
    //for (int i = 0; i < tamanhoPadrao-1; i++)//calcula h = d elevado tamapat-1
          //h = (h*numCaractAlfabeto) % TAM_TABELA;
    for (int i = 0; i < tamanhoPadrao; i++){
      //hashPadrao = (numCaractAlfabeto*hashPadrao + padrao[i]) % TAM_TABELA ;
      hashOriginal = (numCaractAlfabeto*hashOriginal + original[i]) % TAM_TABELA ;
    }
      for ( int i = 0; i <= tamanhoOriginal - tamanhoPadrao; i++){//percorre tamOriginal todo
            //if ( hashPadrao == hashOriginal ){
            if ( !hashPaRK.at(numeroPa).at(hashOriginal).empty() ){
                cout << "colisao na posiçao" << i << endl;
                totalColisoesRK.back()++;
                hashPaRK.at(numeroPa).at(hashOriginal).push_back(diretoriosNP.at(numeroNP));
                //colisoes[hashOriginal%TAM_TABELA]=padrao;
                //indColisoes[hashOriginal%TAM_TABELA]++;
//                while(!colisoesRK[(hashOriginal+k*REHASHING)%TAM_TABELA].empty())
//                    k++;
//                colisoesRK[(hashOriginal+k*REHASHING)%TAM_TABELA]=padrao;
            }
        if ( i < tamanhoOriginal-tamanhoPadrao ){//atualiza o hash caracter a caracter
        int j=hashOriginal;
        j = (numCaractAlfabeto*(j - (original)[i]*h)+ original[i+tamanhoPadrao])%TAM_TABELA;
        if (j < 0)
            j = (j + primoGrande);
            hashOriginal=j;
        }
    }
}

void Rabinkarp::searchBernstein(){
    hashPadrao=0;
    hashOriginal=0;
    int k=0;
    totalColisoesBernstein.push_back(0);
    hashOriginal=bernstein_hash(original.substr(0,tamanhoPadrao));
    //hashPadrao=bernstein_hash(padrao);
    for ( int i = 0; i <= tamanhoOriginal - tamanhoPadrao; i++){//percorre tamOriginal todo
        //if ( hashPadrao == hashOriginal ){//verifica hash
             if ( !hashPaBurn.at(numeroPa).at(hashOriginal).empty() ){
                cout << "colisao na posiçao" << i << endl;
                (totalColisoesBernstein.back())++;
                //cout << "colisao na posiçao" << i << endl;
                //totalPadroesBernstein++;
                hashPaBurn.at(numeroPa).at(bernstein_hash(padrao)).push_back(diretoriosNP.at(numeroNP));
                //indColisoes[hashOriginal%TAM_TABELA]++;
//                while(!colisoesB[(hashOriginal+k*REHASHING)%TAM_TABELA].empty())
//                    k++;
//                colisoesB[(hashOriginal+k*REHASHING)%TAM_TABELA]=padrao;
        }
        hashOriginal=bernstein_hash(original.substr(i,tamanhoPadrao));
    }
}

void Rabinkarp::searchFNV(){
    hashPadrao=0;
    hashOriginal=0;
    totalColisoesFNV.push_back(0);
    int k=0;
    //hashPadrao=fnv_hash(padrao);
    hashOriginal=fnv_hash(original.substr(0,tamanhoPadrao));
    for ( int i = 0; i <= tamanhoOriginal - tamanhoPadrao; i++){//percorre tamOriginal todo
        //if ( hashPadrao == hashOriginal ){//verifica hash
            //    cout << "colisao na posiçao" << i << endl;
            if ( !hashPaFNV.at(numeroPa).at(hashOriginal).empty() ){
                cout << "colisao na posiçao" << i << endl;
                (totalColisoesFNV.back())++;
                //cout << "colisao na posiçao" << i << endl;
                //totalPadroesBernstein++;
                hashPaFNV.at(numeroPa).at(fnv_hash(padrao)).push_back(diretoriosNP.at(numeroNP));
//                totalPadroesFNV++;
                //colisoes[hashOriginal%TAM_TABELA]=padrao;
                //indColisoes[hashOriginal%TAM_TABELA]++;
//                while(!colisoesFNV[(hashOriginal+k*REHASHING)%TAM_TABELA].empty())
                    k++;
//                colisoesFNV[(hashOriginal+k*REHASHING)%TAM_TABELA]=padrao;
        }
        hashOriginal=fnv_hash(original.substr(i,tamanhoPadrao));
    }
}

void Rabinkarp::geraPattern(){
    numeroPa=0;
    for(unsigned int i=0;i < plagio.size();i+=tamanhoPadrao){
            //string* pat=let.geraPattern(s1,i,&outputFile);
            padrao = plagio.substr(i,tamanhoPadrao);
            cout << "PATTERN =" << padrao << endl;
            this->searchFNV();
            this->searchBernstein();
            this->searchRK();
            numeroPa++;
        }
}

string Rabinkarp::arquivoToString(string& nomeArquivo){
  string str,k;
  ifstream arquivo;
  arquivo.open(nomeArquivo.c_str());
  //cout << arquivo->is_open()<< arquivo->good() << endl;
  if(arquivo.is_open()){
    while(arquivo.good()){
      getline(arquivo,str,'\n');
      k+=str;
    }
  }
  else cout << "erro no arquivo" << endl;
   arquivo.close();
   return k;
}


/*void Rabinkarp::search(){
    int h=1;
    int j;
    //---Seleciona e calcula hash inicial---
    if(qualHash=='r'){
      for (int i = 0; i < tamanhoPadrao-1; i++)//calcula h = d elevado tamapat-1
          h = (h*numCaractAlfabeto) % primoGrande;
      for (int i = 0; i < tamanhoPadrao; i++){
          hashPadrao = (numCaractAlfabeto*hashPadrao + padrao[i]) % primoGrande ;
          hashOriginal = (numCaractAlfabeto*hashOriginal + original[i]) % primoGrande ;
      }
        } else {
          if(qualHash=='b'){
            hashOriginal=bernstein_hash(original.substr(0,tamanhoPadrao));
            hashPadrao=bernstein_hash(padrao);
                }else {

                  hashPadrao=fnv_hash(padrao);
                  hashOriginal=fnv_hash(original.substr(0,tamanhoPadrao));
                }
        }
        //---Executa Comparaçao--
    for ( int i = 0; i <= tamanhoOriginal - tamanhoPadrao; i++){//percorre tamOriginal todo
        if ( hashPadrao == hashOriginal ){//verifica hash
//            if(lasVegas){
                if (original.substr(i,tamanhoPadrao) == padrao){//compara as strings
                    cout << "colisao na posiçao" << i << endl;
//                    totalPadroes++;
//                    colisoes[hashOriginal%TAM_TABELA]=padrao;
//                    indColisoes[hashOriginal%TAM_TABELA]++;
                }
            }else{ //assume q só verificar o hash é suficiente
                cout << "colisao na posiçao" << i << endl;
//                totalPadroes++;
//                colisoes[hashOriginal%TAM_TABELA]=padrao;
//                indColisoes[hashOriginal%TAM_TABELA]++;
            }
        }
        //---Atualiza  hash do arquivo Original---
        if(qualHash=='r'){//escolha do hash
//          if ( i < tamanhoOriginal-tamanhoPadrao ){//atualiza o hash caracter a caracter
              int j=hashOriginal;
//              j = (numCaractAlfabeto*(j - (original)[i]*h)+ original[i+tamanhoPadrao])%primoGrande;
              if (j < 0)
                  j = (j + primoGrande);
            hashOriginal=j;
            }
//        } else {
          if(qualHash=='b'){
//                hashOriginal=bernstein_hash(original.substr(i,tamanhoPadrao));
            }else {
//                hashOriginal=fnv_hash(original.substr(i,tamanhoPadrao));
            }
        }
//    }
//}
*/

/*
void Rabinkarp::rabinkarp3000(){
    int i, j;

    int h = 1;
    //cout <<"ENTRANDO NO RABIN_KARP"<< endl;
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i <  tamanhoPadrao-1; i++)
        h = (h*numCaractAlfabeto)%primoGrande;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < tamanhoPadrao; i++)
    {
        hashPadrao = (numCaractAlfabeto*hashPadrao + (padrao)[i])%primoGrande;
        hashOriginal = (numCaractAlfabeto*hashOriginal + (original)[i])%primoGrande;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= tamanhoOriginal -  tamanhoPadrao; i++){
        if ( hashPadrao == hashOriginal ){//verifica hash
            if (original.substr(i,tamanhoPadrao) == padrao){//uma ocorrencia de dif quebra (original)[i+j]!= padrao[j]
                        cout << "colisao na posiçao" << i << endl;
                        totalPadroes++;
                        colisoes[hashOriginal%TAM_TABELA]=padrao;
                        indColisoes[hashOriginal%TAM_TABELA]++;
                    }
            /*for (j = 0; j <  tamanhoPadrao; j++){//verifica caracteres
                if ((original)[i+j] != (padrao)[j])//uma ocorrencia de dif quebra
                    break;
            }
            if (j ==  tamanhoPadrao)// tudo igual em todo o pattern
               { printf("colisao na posiçao %d \n", i);

                }*
        }
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < tamanhoOriginal - tamanhoPadrao ){//
            int j=hashOriginal;
            j = (numCaractAlfabeto*(j - original[i]*h) + (original)[i+ tamanhoPadrao])%primoGrande;

            // We might get negative value of t, converting it
            // to positive
            if (j < 0)
            j  += primoGrande;
            hashOriginal=j;
        }
    }
}
*/

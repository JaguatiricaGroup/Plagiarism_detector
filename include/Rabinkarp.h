#ifndef RABINKARP_H
#define RABINKARP_H
#include "hash.h"
#include <fstream>
#include <list>
#include <string>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#define numCaractAlfabeto 256
#define primoGrande 3355439//3355439 //1099511628211 //997
#define TAM_TABELA 500
#define BASE_FNV 14695981039346656037
#define PRIMO_FNV 1099511628211
#define REHASHING 1
#define qtdPa 774

class Rabinkarp
{
  public:
   // Rabinkarp(ifstream *original,ifstream *plagio);
    Rabinkarp(vector<string> diretoriosPA,vector<string> diretoriosNP,int tamanhoPadrao);
    virtual ~Rabinkarp();
    void geraPattern();
    void printColisoes();
    void printTotalPadroes();
    //void search();
    //void rabinkarp3000();

  private:
    vector<vector<list<string> > > hashPaBurn;
    vector<vector<list<string> > > hashPaFNV;
    vector<vector<list<string> > > hashPaRK;
    vector<string> diretoriosNP;
    vector<string> diretoriosPA;
    //hashPaBurn.reserve(1040);
    //hashPaFNV.reserve(1040);
    int numeroPa;
    int numeroNP;
    void searchFNV();
    void searchBernstein();
    void searchRK();
    unsigned bernstein_hash (string p);
    int tamanhoOriginal;
    unsigned fnv_hash(string s);
    unsigned hashPadrao;
    unsigned hashOriginal;
    int tamanhoPadrao;
    int h;
    int rk_hash(string p);
    void geraEstruturaPA();
    list<int> totalColisoesBernstein;
    list<int> totalColisoesFNV;
    list<int> totalColisoesRK;
    //string *colisoesB;
    //string *colisoesFNV;
    //string *colisoesRK;
    string padrao;//padrao
    string plagio;//talvez plagio
    string original;//documento a ser analizado como original
    string arquivoToString(string& nomeArquivo);
//    string arquivoToString(ifstream *arquivo);
};

#endif // RABINKARP_H

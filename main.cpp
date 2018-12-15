#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"
#include "Rabinkarp.h"
#include <vector>
#include <dirent.h>
using namespace std;

//void controleDeArquivos(ifstream *PA,ifstream *NP){
//    string dirNP,dirPA;int i=0;
//    vector<string> arquivo1,arquivo2;
//    while(!PA->eof()){
//        getline(*PA,dirPA);
//        if(dirPA.substr(0,4)=="2016"){
//            *(--(dirPA.end()))='/';
//            //cout << dirPA << endl;
//            while(1){
//                //cout << " entrei" << endl;
//                string aux;
//                getline(*PA,aux);
//                dirPA+=aux;
//                if(aux.empty()){
//                    break;
//                }
//                getline(*NP,dirNP);
//                if(dirNP.substr(0,4)=="2016"){
//                    *(--(dirNP.end()))='/';
//                    //cout << dirPA << endl;
//                    while(1){
//                        //cout << " entrei" << endl;
//                        string aux1;
//                        getline(*NP,aux1);
//                        if(aux1.empty()){
//                            break;
//                        }
//                        cout <<dirNP+aux1 << endl;
//                        arquivo2.push_back(dirNP+aux1);
//                        //arquivo1.push_back(dirPA + aux);
//                        //cout << *arquivo1[i].begin() << endl;
//  //                      i++;
//                    }
//                //arquivo1.push_back(dirPA + aux);
//                //cout << *arquivo1[i].begin() << endl;
////                i++;
//            }
//
//            for(int i=0;i<arquivo2.size();i++){
//                cout <<"vdd---"<< dirPA <<'\n'<<"plagio---"<< arquivo2[i]  << endl;
//            }
//            arquivo2.clear();
//
//            }
//        }
//    }
//}



//void controleDeNp(ifstream *NP,vector<string> v){
//    string dirNP;int x=0;
//    while(!NP->eof()){
//        getline(*NP,dirNP);
//        if(dirNP.substr(0,4)=="2016"){
//            *(--(dirNP.end()))='/';
//                          string aux;
//            do{
//                //cout << " entrei" << endl;
//
//                getline(*NP,aux);
//                dirNP+=aux;
//                x++;
//                //out<< dirNP << x << endl;
//                v.push_back(dirNP);
//            }while(!aux.empty());
//           // x++;
//           // cout<< dirPA<< x << endl;
//        }
//    }
//}
//int getdir (string dir, vector<string> &files)
//{
////    DIR *dp;
//    struct dirent *dirp;
//    if((dp  = opendir(dir.c_str())) == NULL) {
//        cout << "Error(" << 3 << ") opening " << dir << endl;
//        return 3;
//    }
//
//    while ((dirp = readdir(dp)) != NULL) {
//        files.push_back(string(dirp->d_name));
//    }
//    closedir(dp);
//    return 0;
//}

void controleDePa(ifstream *PA,vector<string> *vetor_PA){
    string dirPA;int x=0;string aux;ofstream g("nada.txt");int i=0;
    while(!PA->eof()){
        getline(*PA,dirPA);
        if(dirPA.substr(0,4)=="2016"){
            //dirPA="./"+dirPA;
            *(--(dirPA.end()))='/';
            //cout << dirPA << endl;
            //string k=dirPA;
            while(1){
                //cout << " entrei" << endl;
                //aux.clear();
                getline(*PA,aux);
                //cout << aux <<endl;
                //k = dirPA+aux;
                if(aux.empty())break;
                g << dirPA + aux << '\n';
                //cout << dirPA<< endl;
                //x++;
                //cout <<  dirPA  << endl;
                vetor_PA->push_back(dirPA + aux);
                i++;
            }
        }
    }
}


int main(){
    ifstream v,p,s,y;
    vector<string> vetor_NP;
    vector<string> vetor_PA;
    v.open("indexPA.txt");
    p.open("indexNP.txt");
    controleDePa(&v,&vetor_PA);
    controleDePa(&p,&vetor_NP);
    //cout << vetor_PA.at(4).c_str() << endl;

    y.open(vetor_NP.at(2).c_str());
    //cout << vetor_NP.at(2);
//    -------------confere se algum arquivo falhou---------------------
    for(int k=0;k<vetor_NP.size();k++){
      //cout<< vetor_NP.at(k)<< endl;
      y.open(vetor_NP.at(k).c_str());
        if (!y.is_open())
            cout << "falhou" << endl;
        }
     for(int k=0;k<vetor_PA.size();k++){
      //cout<< vetor_NP.at(k)<< endl;
      s.open(vetor_PA.at(k).c_str());
        if (!s.is_open())
            cout << "falhou" << endl;
        }
//       //cout<<"NP"<< vetor_NP.size() << "PA"<< vetor_PA.size() << endl;
    Rabinkarp leticia(vetor_PA,vetor_NP,4);
    //cout << vetor_NP.size() <<" "<< vetor_PA.size() << endl;
    // << s;
    //cout << s.is_open()<< y.is_open()<< endl;// << y.is_open();

    //leticia.geraPattern();
//    leticia.printColisoes();
    //leticia.printTotalPadroes();
    //string dir = string("2016.3-meter-corpus/meter-corpus/PA/rawtexts/courts/29.03.00/collins");
    //vector<string> files = vector<string>();
    //getdir(dir,files);

    //for (unsigned int i = 0;i < files.size();i++) {
     //   cout << files[i] << endl;
    //}

    p.close();
    v.close();
    return 0;
}

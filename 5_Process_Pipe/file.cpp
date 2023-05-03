#include<iostream>
#include<fstream>

using namespace std;

int main(){

    ifstream fin;
    string line;
    fin.open("f.txt");
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    return 0;
    fin.close();
}
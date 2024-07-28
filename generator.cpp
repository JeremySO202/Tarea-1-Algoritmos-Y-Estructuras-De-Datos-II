#include<fstream>
#include<string.h>
#include <iostream>


using namespace std;



int main(int argc, char* argv[]){
    char *size;
    string output;

    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i],"-size") == 0){
            size = argv[i+1];
        }
        if (strcmp(argv[i],"-output") == 0){
            output = argv[i+1];

        }
    }
    fstream file(output, ios::out | ios::binary | ios:: trunc);

    if (file){
        int maxSize = 0;
        if (strcmp(size,"SMALL")==0){
            maxSize = 134217728;
        }
        if (strcmp(size,"MEDIUM")==0){
            maxSize = 268435456;

        }
        if (strcmp(size,"LARGE")==0){
            maxSize = 536870912;
        }
        for (int i = 0; i < maxSize; ++i) {
            int num = rand();
            file.write((char*) &num, sizeof(int));
        }
        cout << "Archivo generado...\n";


    }

    if (file.is_open()){
        file.close();
    }

    return 0;
}
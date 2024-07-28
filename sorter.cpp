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
    fstream file(output, ios::in | ios::binary | ios:: trunc);

    if (file){

    }

    if (file.is_open()){
        file.close();
    }

    return 0;
}
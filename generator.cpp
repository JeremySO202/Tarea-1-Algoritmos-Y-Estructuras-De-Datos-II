#include<fstream>
#include<string.h>
#include <iostream>



using namespace std;



int main(int argc, char* argv[]){

    char *size, *output;

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
        int *num = new int[1024]();
        int lastIndex = 0;
        srand(time(0));
        for (int i = 0; i < maxSize; ++i) {
            num[i%1024] = rand();
            if (lastIndex != int(i/1024)){
                file.write((char*) num, 1024 * sizeof(int));
                lastIndex = int(i/1024);
                delete[] num;
                num = new int[1024]();
            }
        }

        if (maxSize%1024!=0){
            file.write((char*) num, int(maxSize%1024) * sizeof(int));
        }
        else{
            file.write((char*) num, 1024 * sizeof(int));
        }

    }

    if (file.is_open()){
        file.close();
    }

    return 0;
}
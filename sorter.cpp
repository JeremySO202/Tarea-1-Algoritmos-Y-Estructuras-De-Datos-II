#include<fstream>
#include<string.h>
#include <iostream>
#include <chrono>
#include "PagedArray.cpp"
#include "sorts.cpp"

using namespace std;


int main(int argc, char *argv[]) {
    string input, output;
    const char *alg;

    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-input") == 0) {
            input = argv[i + 1];
        }
        if (strcmp(argv[i], "-output") == 0) {
            output = argv[i + 1];
        }
        if (strcmp(argv[i], "-alg") == 0) {
            alg = argv[i + 1];
        }
    }
    fstream file(input, ios::in | ios::binary);


    if (file.is_open()) {
        file.close();
        string comand = "copy " + input + " " + output + ".bin";
        system(comand.c_str());
        PagedArray array(output + ".bin");


        if (strcmp(alg, "QS") == 0)
        {
            auto start = std::chrono::high_resolution_clock::now();
            quickSort(array, 0, array.sizeFile - 1);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
            cout << "Tiempo de ejecución: " << duration.count() << " segundos" << endl;
            array.savePages();
        }



        if (strcmp(alg, "IS") == 0) {


        }
        if (strcmp(alg, "BS") == 0) {

        }

        fstream outputFile(output + ".csv", ios::out | ios::trunc);

        for (int i = 0; i < array.sizeFile; ++i) {
            if (i != 0) {
                outputFile << ',';
            }
            outputFile << array[i];
        }
        array.file.close();

        outputFile.close();


    }

    if (file.is_open()) {
        file.close();
    }

    return 0;
}
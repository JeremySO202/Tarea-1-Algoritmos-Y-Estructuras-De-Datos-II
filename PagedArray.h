//
// Created by jerem on 27/7/2024.
//

#ifndef TAREA_1_PAGEDARRAY_H
#define TAREA_1_PAGEDARRAY_H



class PagedArray {

public:
    int SIZE = 16384; //tamano de pagina 64 KB
    int sizeFile;
    int pageFault = 0;
    int pageHit = 0;

    static const int maxFrame = 4;


    std::fstream file;

    int **frames;
    int currentPages[maxFrame];

    explicit PagedArray(std::string path);
    int &operator[](int);
    int getPage(int index);
    void loadPage(int page, int newFrame);
    void savePages();
};




#endif //TAREA_1_PAGEDARRAY_H

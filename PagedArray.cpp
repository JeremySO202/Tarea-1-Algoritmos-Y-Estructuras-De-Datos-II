#include<iostream>
#include <fstream>

#include "PagedArray.h"

using namespace std;

PagedArray::PagedArray(string input) {

    this->file.open(input, ios::in | ios::out | ios::binary);
    this->file.seekg(0, ios::end);
    sizeFile = int(this->file.tellg()) / 4;
    frames = (int **) malloc(maxFrame * sizeof(int *));
    for (int i = 0; i < maxFrame; i++) {
        frames[i] = (int *) malloc(SIZE * sizeof(int));
    }
    for (int i = 0; i < maxFrame; ++i) {
        currentPages[i] = -1;
    }

}

int PagedArray::getPage(int index) {

    if (index < sizeFile) {
        return int(index / SIZE);
    } else {
        return -1;
    }
}

void PagedArray::loadPage(int page, int newFrame) {
    if (currentPages[newFrame] != -1) {
        file.seekp(SIZE * currentPages[newFrame] * sizeof(int));
        file.write((char *) frames[newFrame], SIZE * sizeof(int));

    }
    file.seekg(SIZE * page * sizeof(int));
    file.read((char *) frames[newFrame], SIZE * sizeof(int));
    currentPages[newFrame] = page;
}

int &PagedArray::operator[](int index) {

    int page = getPage(index);

    for (int i = 0; i < maxFrame; ++i) {
        if (currentPages[i] == page) {
            this->pageHit += 1;
            return frames[i][index % SIZE];
        }
    }
    int newFrame = -1;
    for (int i = 0; i < maxFrame; ++i) {
        if (currentPages[i] == -1) {
            newFrame = i;
            break;
        }
    }
    if (newFrame == -1) {
        newFrame = rand() % 4;
    }
    loadPage(page, newFrame);
    this->pageFault += 1;
    return frames[newFrame][index % SIZE];

}

void PagedArray::savePages() {

    for (int i = 0; i < maxFrame; ++i) {
        if (currentPages[i] != -1) {
            file.seekp(SIZE * currentPages[i]);
            file.write((char *) frames[i], SIZE * sizeof(int));
        }
    }
    file.flush();

}

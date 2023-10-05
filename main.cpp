#include<iostream>
#include<cstring>
#include "bmplib.h"
using namespace std;
unsigned char imag[SIZE][SIZE];
unsigned char imag2[SIZE][SIZE];
unsigned char imag3[SIZE][SIZE];
void loadImage();
void loadImage2();
void yourFilter();
void InvertImage();
void MergeImages();
void saveImage();
void blackAndWhite();
void saveImage2();

int main() {
    int n;
    cout<<"chose the number of filter"<<endl;
    cout<<"1-black and white"<<endl;
    cout<<"2-invers image"<<endl;
    cout<<"3-mare image"<<endl;
    cin>>n;
    if(n==1){
        loadImage();
        blackAndWhite();
        saveImage();
    }
    if(n==2){
        loadImage();
        InvertImage();
        saveImage();
    }
    if(n==3){
        loadImage();
        loadImage2();
        MergeImages();
        saveImage2();


    }
    return 0;

}
void loadImage2() {
    char imageName[100];
    cout << "enter your SOCAND image file sourse";
    cin >> imageName;
    strcat(imageName, ".bmp");
    readGSBMP(imageName, imag2);
}
void loadImage(){
    char imageName[100];
    cout<<"enter your image file sourse";
    cin>>imageName;
    strcat(imageName,".bmp");
    readGSBMP(imageName,imag);

}
void saveImage(){
    char imageName[100];
    cout<<"enter your image name after edit";
    cin>>imageName;
    strcat(imageName,".bmp");
    writeGSBMP(imageName,imag);



}
void saveImage2() {
    char imageName[100];
    cout << "enter your image name after edit";
    cin >> imageName;
    strcat(imageName, ".bmp");
    writeGSBMP(imageName,imag3);
}

void yourFilter() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
        }
    }
}

void blackAndWhite() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (imag[i][j] > 127) {
                imag[i][j] = 255;
            } else {
                imag[i][j] = 0;
            }
        }
    }
}
    void InvertImage()
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imag[i][j]=255-imag[i][j];
            }
        }
    }
void MergeImages(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          imag3[i][j]=(imag[i][j]+imag2[i][j])/2;

        }

    }
}

           

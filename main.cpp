#include<iostream>
#include<cstring>
#include "bmplib.h"
using namespace std;
unsigned char imag[SIZE][SIZE];

void loadImage();
void yourFilter();
void blackAndWhite();
void InvertImage();
void saveImage();

int main() {
loadImage();
blackAndWhite();
saveImage();
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

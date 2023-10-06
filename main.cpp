#include<iostream>
#include<cstring>
#include "bmplib.h"
using namespace std;
unsigned char imag[SIZE][SIZE];
unsigned char imag2[SIZE][SIZE];
unsigned char imag3[SIZE][SIZE];
unsigned char imag4[SIZE][SIZE];


void loadImage();
void loadImage2();
void yourFilter();
void InvertImage();
void MergeImages();
void saveImage();
void saveImage2();
void blackAndWhite();
void flibImage();
void rotateImage(int degrees);
void darkenLightenImage(bool darken);



int main() {
    int n;
    cout<<"chose the number of filter"<<endl;
    cout<<"1-black and white"<<endl;
    cout<<"2-invers image"<<endl;
    cout<<"3-mare image"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5-Rotate Image"<<endl;
    cout<<"6-Lighten and Darken Image"<<endl;


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
    if(n==4){
        loadImage();
        flibImage();
        saveImage2();
    }
    if(n==5){
        int degree=0;
        loadImage();
        cout<<"enter rotation degree 90,180,270";
        cin>>degree;
        rotateImage(degree);
        saveImage();
    }
    if(n==6){
        int fac=0;
        loadImage();
        cout<<"enter 0 to lighten ,1 to darken"<<endl;
        cin>>fac;
        darkenLightenImage(fac? true:false);
        saveImage();
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
void  flibImage() {
    for (int i = SIZE; i >0; i--) {
        for (int j = SIZE; j >0; j--) {
            imag4[i][j]= imag[ 256- i][256-j];

        }



    }
    for (int i = SIZE; i >0; i--) {
        for (int j = SIZE; j > 0; j--) {
            imag3[i][j] = imag4[i][256 - j];
        }
    }
}
void rotateImage(int degrees)
{
    unsigned char tempImage[SIZE][SIZE];
    // int degrees=180;

    switch (degrees) {
        case 90:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    tempImage[i][j] = imag[SIZE - j - 1][i]; // Rotate 90 degrees clockwise
                }
            }
            break;

        case 180:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    tempImage[i][j] = imag[SIZE - i - 1][SIZE - j - 1]; // Rotate 180 degrees
                }
            }
            break;

        case 270:
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    tempImage[i][j] = imag[j][SIZE - i - 1]; // Rotate 270 degrees clockwise
                }
            }
            break;

        default:
            // Invalid input for degrees
            return;
    }

    // Copy the temp image back to the original image
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            imag[i][j] = tempImage[i][j];
        }
    }
}
void darkenLightenImage(bool darken) {
    float factor = darken ? 0.5 : 1.5; // Darken by reducing brightness, Lighten by increasing brightness

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int newValue = imag[i][j] * factor;

            // Ensure the value stays within the valid range [0, 255]
            imag[i][j] = min(max(newValue, 0), 255);
        }
    }
}

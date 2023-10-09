//FCAI- OOP Programming - 2023 - Assignment 1
//Program Name: main.cpp
//Last Modification Date: 9 Oct 2023
// Raghad Thabet 20220912
// Hasan Ali AlHamed 20220732
// Ali Hafiz Allah Ali 20220764
//Program to apply different filters to an image.

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
void InvertImage();
void MergeImages();
void saveImage();
void saveImage2();
void blackAndWhite();
void flipImage();
void rotateImage(int degrees);
void darkenLightenImage(bool darken);



int main() {
    int n;
    cout<<"Chose the number of filter"<<endl;
    cout<<"1-black and white"<<endl;
    cout<<"2-Inverse image"<<endl;
    cout<<"3-Mare image"<<endl;
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
        flipImage();
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
    cout << "enter your second image file source";
    cin >> imageName;
    strcat(imageName, ".bmp");
    readGSBMP(imageName, imag2);
}
void loadImage(){
    char imageName[100];
    cout<<"enter your image file source";
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

// New image will be a black and white version of the original color image.
void blackAndWhite() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (imag[i][j] > 127) {
                imag[i][j] = 255; //If the pixel value is greater than 127, Sets the pixel value to 255 which means (white)
            } else {
                imag[i][j] = 0;// Otherwise set it to 0 which means (black)
            }
        }
    }
}//New image will be a negative of the original image, where black pixels become white and white pixels become black
void InvertImage()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imag[i][j]=255-imag[i][j];
        }
    }
}
//Each pixel value will be the average of the corresponding pixel values in both images
void MergeImages(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imag3[i][j]=(imag[i][j]+imag2[i][j])/2;// calculates the average of the pixel values at a position in imag and imag2 then assigns the result to the same position in imag3.

        }

    }
}
// New image will be flipped horizontally and vertically of the original one
void  flipImage() {
    for (int i = SIZE; i >0; i--) {
        for (int j = SIZE; j >0; j--) {
            imag4[i][j]= imag[ 256- i][256-j];// Vertically flipped

        }



    }
    for (int i = SIZE; i >0; i--) {
        for (int j = SIZE; j > 0; j--) {
            imag3[i][j] = imag4[i][256 - j];// Horizontally flipped
        }
    }
}
// New image will bw rotated by the chosen degree. Created by Raghad Thabet ID 20220912
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
// New image will have its brightness according to what is chosen.Created by Raghad Thabet ID 20220912
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
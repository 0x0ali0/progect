//FCAI- OOP Programming - 2023 - Assignment 1
//Program Name: CS213-2023-20220912-20220732-20220764-A1-Part1.cpp
//Last Modification Date: 9 Oct 2023
// Raghad Mutaher Thabet-20220912-raghadabsi202@gmail.com
// Hasan Ali AlHamed-20220732-h.a.h.a04@hotmail.com
// Ali Hafiz Allah Ali-20220764-ali0552969317@icloud.com
//Program to apply different filters to an image.

#include<iostream>
#include<cstring>
#include "bmplib.h"
#include<cmath>


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
void skewRightImage(int degrees);
void skewUPImage(int degrees);
void rotateImage(int degrees);
void DetectImageEdges();
void darkenLightenImage(bool darken);
void shrinkImage(int factor);
void mirrorImage(string n);
void blurImage();
void CropImage();
void enlargeFilter(int num);
void shaffleImage(int num);


int main() {
    char n;
    cout<<"Choose the number of filter"<<endl;
    cout<<"1-black and white Image"<<endl;
    cout<<"2-Inverse Image"<<endl;
    cout<<"3-Mare Image"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5-Darken or Lighten Image"<<endl;
    cout<<"6-Rotate Image"<<endl;
    cout<<"7- DetectImageEdges"<<endl;
    cout<<"8- DetectImageEdges"<<endl;
    cout<<"9-Shrink Image"<<endl;
    cout<<"a-mirror Image"<<endl;
    cout<<"c-Blur Image"<<endl;
    cout<<"d-CropImage"<<endl;
    cout<<"e-Skew Image UP"<<endl;
    cout<<"f-Skew Image RIGHT"<<endl;





    cin>>n;
    if(n=='1'){
        loadImage();
        blackAndWhite();
        saveImage();
    }
    if(n=='2'){
        loadImage();
        InvertImage();
        saveImage();
    }
    if(n=='3'){
        loadImage();
        loadImage2();
        MergeImages();
        saveImage2();
    }
    if(n=='4'){
        loadImage();
        flipImage();
        saveImage2();
    } if(n=='5'){
        int fac=0;
        loadImage();
        cout<<"enter 0 to lighten ,1 to darken"<<endl;
        cin>>fac;
        darkenLightenImage(fac? true:false);
        saveImage();
    }
    if(n=='6'){
        int degree=0;
        loadImage();
        cout<<"enter rotation degree 90,180,270";
        cin>>degree;
        rotateImage(degree);
        saveImage();
    }

    if(n=='7'){
        loadImage();
        DetectImageEdges();
        saveImage();
    }
    if(n=='8'){
        int num;
        loadImage();
        enlargeFilter(num);
        saveImage2();

    }

    if (n == '9') {
        int factor = 0;
        loadImage();
        cout << "Enter shrink factor (2, 3, or 4): ";
        cin >>factor;
        if (factor == 2 || factor == 3 || factor == 4) {
            shrinkImage(factor);
            saveImage();
        } else {
            cout << "Invalid factor. Please enter 2, 3, or 4." << endl;
        }
    }
    if(n=='a'){
        string n;
        loadImage();
        mirrorImage(n);
        saveImage2();

    }
    if(n=='b'){
        int num;
        loadImage();
        shaffleImage(num);
        saveImage();


    }
    if(n == 'f'){
        int degree = 0;

        loadImage();
        cout << "Enter skew degrees (e.g., 30): ";
        cin >> degree;

        skewRightImage(degree);
        saveImage();
    }
    if(n == 'e'){
        int degree = 0;
        loadImage();
        cout << "Enter skew degrees (e.g., 30): ";
        cin >> degree;

        skewUPImage(degree);
        saveImage();
    }
    if(n=='d'){
        loadImage();
        CropImage();
        saveImage();
    }
    if(n=='c') {
        loadImage();
        blurImage();
        saveImage();

        return 0;

    }
}

void loadImage2() {
    char imageName[100];
    cout << "Enter your second image file source (excluding file extension): ";
    cin >> imageName;
    string imagePath = "in_images/" + string(imageName) + ".bmp";
    readGSBMP(imagePath.c_str(), imag2);
}

void loadImage() {
    char imageName[100];
    cout << "Enter your image file source (excluding file extension): ";
    cin >> imageName;
    string imagePath = "in_images/" + string(imageName) + ".bmp";
    readGSBMP(imagePath.c_str(), imag);
}

void saveImage() {
    char imageName[100];
    cout << "Enter your image name after edit (excluding file extension): ";
    cin >> imageName;
    string imagePath = "out_images/" + string(imageName) + ".bmp";
    writeGSBMP(imagePath.c_str(), imag);
}

void saveImage2() {
    char imageName[100];
    cout << "Enter your image name after edit (excluding file extension): ";
    cin >> imageName;
    string imagePath = "out_images/" + string(imageName) + ".bmp";
    writeGSBMP(imagePath.c_str(), imag3);
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
void InvertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imag[i][j]=255-imag[i][j];
        }
    }

}
//Each pixel value will be the average of the corresponding pixel values in both images
void MergeImages()
{

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
    }}
//This function applies a vertically skew filter to a given image.
//Created by Raghad Thabet 20220912
void skewRightImage(int degree)  {
    double rad = degree * (22/7) / 180.0;
    double factor = -tan(rad);

    // Create an empty temporary image
    unsigned char tempImage[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tempImage[i][j] = 255;
        }
    }

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int newX = x +(factor * ( y - SIZE / 2 ));
            if (newX >= 0 && newX < SIZE) {
                tempImage[y][newX] = imag[y][x];
            }
        }
    }
    memcpy(imag, tempImage, SIZE * SIZE);

    // Ensure the result is 256x256
    memcpy(tempImage, imag,SIZE*SIZE);

}
// New image will bw rotated by the chosen degree. Created by Raghad Thabet ID 20220912
void rotateImage(int degrees){
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
// The function applies a shrink transformation to the original image
// Created by Raghad Thabet, 20220912
void shrinkImage(int fac) {
    int newSize = SIZE /fac;
    unsigned char tempImage[SIZE][SIZE];
    for (int i = 0; i<newSize; ++i) {
        for (int j = 0; j<newSize; ++j) {
            int sum=0;
            for (int x=0; x<fac; ++x) {
                for (int y=0; y<fac; ++y) {
                    sum += imag[ i*fac+ x][j*fac + y];
                }
            }
            tempImage[i][j] = sum / (fac* fac);
        }
    }
    for (int i = 0; i <SIZE; ++i) {
        for (int j = 0; j <SIZE; ++j) {
            imag[i][j] = 255;
        }
    }
    // Copy the shrunken image back to the original image
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            imag[i][j] = tempImage[i][j];
        }
    }
}
//This function applies a blur effect to a given image
//Created by Raghad Thabet, 20220912
void blurImage() {
    unsigned char tempImage[SIZE][SIZE];
    for(int x=0;x<=10;x++){
        for(int i =0; i<SIZE;i++) {
            for (int j=0; j<SIZE; j++) {
                // Calculate average of surrounding pixels (including current pixel)
                int sum = imag[i-1][j-1] + imag[i-1][j] + imag[i-1][j+1] +
                          imag[i][j-1] + imag[i][j] + imag[i][j+1] +
                          imag[i+1][j-1] + imag[i+1][j] + imag[i+1][j+1];
                tempImage[i][j]=sum/9;
            }
        }
        // Copy the temp image back to the original image
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                imag[i][j] = tempImage[i][j];
            }
        }}
}

void skewUPImage(int degree) {
    double rad = degree * (22/7) / 180.0;
    double factor = tan(rad);

    // Create an empty temporary image
    unsigned char tempImage[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tempImage[i][j] = 255;
        }
    }

    for (int y = 0; y < SIZE; ++y) {
        for (int x = 0; x < SIZE; ++x) {
            int newY = y + (factor * (x - SIZE / 2));
            if (newY >= 0 && newY < SIZE) {
                tempImage[newY][x] = imag[y][x];
            }
        }
    }

    memcpy(imag, tempImage, SIZE * SIZE);

    // Ensure the result is 256x256
    memcpy(tempImage, imag,SIZE*SIZE);
}void mirrorImage(string n) {
    cout << "l-for left and r- for right and u for upper and lo for lower";
    cin >> n;
    if (n == "l") {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (j < 127) {
                    imag3[i][j] = imag[i][j];
                    imag3[i][j + 127] = imag[i][127 - j];
                }

            }

        }
    }
    if (n == "r") {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (j > 127) {
                    imag3[i][j] = imag[i][j];
                    imag3[i][j - 127] = imag[i][127 - j];
                }

            }

        }
    }
    if (n == "u") {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (i < 127) {
                    imag3[i][j] = imag[i][j];
                    imag3[i + 127][j] = imag[127 - i][j];
                }

            }

        }
    }
     if (n == "lo") {
        for (int i = 0; i < 127; ++i) {
            for (int j = 0; j < 255; ++j) {

                    imag3[i][j] = imag[255-i][j];
                    imag3[i+127][j] = imag[i+127][j];

                }

            }

        }
    }
void CropImage () {
    int x,y,w,l;
    cout<<"enter x , y , m ,l";
    cin>>x>>y>>w>>l;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i<x){
                imag[i][j]=255;
            }
            if(j<y){
                imag[i][j]=255;
            }
            if(i>256-w){
                imag[i][j]=255;
            }
            if(j>256-l){
                imag[i][j]=255;
            }
        }
    }

}
//this filter copy one pixel to 4 picxel and jump to next odd pixel.
void enlargeFilter(int num) {
    cout << "1" << "|" << "2" << endl;
    cout << "--" << "--" << endl;
    cout << "3" << "|" << "4" << endl;
    cout << "enter number of part you want to large" << endl;
    cin >> num;
    if (num == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i < 127 && j < 127) {
                    imag3[(i * 2 - 1)][(j * 2 - 1)] = imag[i][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1)] = imag[i][j];
                    imag3[(i * 2 - 1)][(j * 2 - 1) + 1] = imag[i][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1) + 1] = imag[i][j];
                }
            }
        }
    }
    if (num == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i < 127 && j > 127) {
                    imag3[(i * 2 - 1)][(j * 2 - 1)] = imag[i + 127][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1)] = imag[i + 127][j];
                    imag3[(i * 2 - 1)][(j * 2 - 1) + 1] = imag[i + 127][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1) + 1] = imag[i + 127][j];
                }
            }
        }
    }

    if (num == 3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i < 127 && j < 127) {
                    imag3[(i * 2 - 1)][(j * 2 - 1)] = imag[i + 127][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1)] = imag[i + 127][j];
                    imag3[(i * 2 - 1)][(j * 2 - 1) + 1] = imag[i + 127][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1) + 1] = imag[i + 127][j];
                }
            }
        }
    }

    if (num == 4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i < 127 && j > 127) {
                    imag3[(i * 2 - 1)][(j * 2 - 1)] = imag[i + 127][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1)] = imag[i + 127][j];
                    imag3[(i * 2 - 1)][(j * 2 - 1) + 1] = imag[i + 127][j];
                    imag3[(i * 2 - 1) + 1][(j * 2 - 1) + 1] = imag[i + 127][j];
                }
            }
        }
    }
}
void shaffleImage(int num) {
    cout << "1" << "|" << "2" << endl;
    cout << "--" << "--" << endl;
    cout << "3" << "|" << "4" << endl;
    cout << "inter the order for the part of image [1,2,3,4]";
    unsigned char first[128][128];
    unsigned char second[128][128];
    unsigned char third[128][128];
    unsigned char forth[128][128];
    int arr[4];
    for (int i = 0; i < 4; ++i) {
        cout << "Enter quarters order: ";
        cin >> arr[i];
    }
    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 128; ++j) {
            first[i][j] = imag[i][j];
            second[i][j] = imag[i][j + 127];
            third[i][j] = imag[i + 127][j];
            forth[i][j] = imag[i + 127][j + 127];
        }
    }
    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 128; ++j) {
            switch (arr[0]) {
                case 1:
                    imag[i][j]=first[i][j];
                    break;
                case 2:
                    imag[i][j]=second[i][j];
                    break;
                case 3:
                    imag[i][j]=third[i][j];
                    break;
                case 4:
                    imag[i][j]=forth[i][j];
                    break;

            }

            switch (arr[1]) {
                case 1:
                    imag[i][j + 128]=first[i][j+128];
                    break;
                case 2:
                    imag[i][j + 128] = second[i][j+128];
                    break;
                case 3:
                    imag[i][j + 128] = third[i][j+128];
                    break;
                case 4:
                    imag[i][j + 128] = forth[i][j+128];
                    break;
            }

            switch (arr[2]) {
                case 1:
                    imag[i+128][j] = first[i][j];
                    break;
                case 2:
                    imag[i+128][j] = second[i][j];
                    break;
                case 3:
                    imag[i+128][j] = third[i][j];
                    break;
                case 4:
                    imag[i+128][j] = forth[i][j];
                    break;
            }

            switch (arr[3]) {
                case 1:
                    imag[i + 128][j+128] = first[i][j];
                    break;
                case 2:
                    imag[i + 128][j + 128] = second[i][j];
                    break;
                case 3:
                    imag[i + 128][j + 128] = third[i][j];
                    break;
                case 4:
                    imag[i + 128][j + 128] = forth[i][j];
                    break;
            }
        }
    }

}
void DetectImageEdges(){
    for (int i = 0; i <SIZE; ++i) {
        for (int j = 0; j <SIZE; ++j) {
            if(imag[i][j]<=imag[i][j+1]+30&&imag[i][j]>=imag[i][j+1]-90&&imag[i][j]<=imag[i+1][j]+30&&imag[i][j]>=imag[i+1][j]-90){
                imag[i][j]=255;
            }
            else{
                imag[i][j]=0;
            }
        }
    }
}

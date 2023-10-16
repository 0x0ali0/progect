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
void skewImage(int degrees);
void rotateImage(int degrees);
void darkenLightenImage(bool darken);
void shrinkImage(int factor);
void blurImage();



int main() {
    int n;
    cout<<"Choose the number of filter"<<endl;
    cout<<"1-black and white Image"<<endl;
    cout<<"2-Inverse Image"<<endl;
    cout<<"3-Mare Image"<<endl;
    cout<<"4-Flip Image"<<endl;
    cout<<"5-Rotate Image"<<endl;
    cout<<"6-Shrink Image"<<endl;
    cout<<"7-Blur Image"<<endl;
    cout<<"8-Skew Image"<<endl;
    cout<<"9-Darken or Lighten Image"<<endl;




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
    if (n == 9) {
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
    if(n == 10){
        int degree = 0;

        loadImage();
        cout << "Enter skew degrees (e.g., 30): ";
        cin >> degree;

        skewImage(degree);
        saveImage();
    }
    if(n==8) {
        loadImage();
        blurImage();
        saveImage2();

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
void skewImage(int degree)  {
    double rad = degree * (22/7) / 180.0;
    double factor = tan(rad);

    // Create an empty temporary image
    unsigned char tempImage[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tempImage[i][j] = 255;
        }
    }

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int newX = x +(factor * (y - SIZE / 2));
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
void shrinkImage(int fac) {
    int newSize = SIZE /fac;
    unsigned char tempImage[SIZE][SIZE];
    for (int i = 0; i<newSize; ++i) {
        for (int j = 0; j<newSize; ++j) {
            int sum=0;
            for (int x=0; x<fac; ++x) {
                for (int y=0;y <fac; ++y) {
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
void blurImage() {
    unsigned char tempImage[SIZE][SIZE];
    for(int x=0;x<=10;x++){
        for(int i =1; i<SIZE - 1;i++) {
            for (int j=1; j<SIZE- 1; j++) {
                // Calculate average of surrounding pixels (including current pixel)
                int sum = imag[i-1][j-1] + imag[i-1][j] + imag[i-1][j+1] +
                          imag[i][j-1] + imag[i][j] + imag[i][j+1] +
                          imag[i+1][j-1] + imag[i+1][j] + imag[i+1][j+1];
                tempImage[i][j]=sum/9;
            }
        }
        // Cop y the temp image back to the original image
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                imag[i][j] = tempImage[i][j];
            }
        }}
}

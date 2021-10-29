#include <myimage.h>
#include <QImage>
#include <QPixmap>
#include <QtDebug>

MyImage::MyImage(QImage image){
    imageData = image;
    height = imageData.height();
    width = imageData.width();
    bytesPerLine = imageData.bytesPerLine();
    QImageToChar();
}

MyImage::~MyImage(){
    delete []charData;
}

void MyImage::QImageToChar(){
    charData = new unsigned char* [height];
    for(int i = 0; i < height; ++i){
        charData[i] = new unsigned char[bytesPerLine];
        for(int j = 0; j < bytesPerLine; ++j){
              charData[i][j] = *(imageData.scanLine(i) + j);
        }
    }
}

void MyImage::CharToQimage(){
    unsigned char *data = new unsigned char[height*bytesPerLine];
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < bytesPerLine; ++j)
            *(data + i * bytesPerLine + j) = charData[i][j];
    imageData = QImage(data,width,height,bytesPerLine,QImage::Format_Grayscale8);
}

const QImage &MyImage::getImageData() const
{
    return imageData;
}

void MyImage::setImageData(const QImage &newImageData)
{
    imageData = newImageData;
}


void MyImage::AffineTransformation(double matrixs[][2][3], int num){
    //创建一个新的数组
    unsigned char **newCharData = new unsigned char* [height];
    for(int i = 0; i < height; ++i)
        newCharData[i] = new unsigned char[bytesPerLine];
   //遍历
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < bytesPerLine; ++j){
            double x = i;
            double y = j;
            for(int k = 0; k < num; ++k){
                double x1 = matrixs[k][0][0]*x + matrixs[k][0][1]* y + matrixs[k][0][2];
                double y1 = matrixs[k][1][0]*x + matrixs[k][1][1]* y + matrixs[k][1][2];
                x = x1;
                y = y1;
            }
            newCharData[i][j] = BilinearInterpolation(x,y);
        }
    }
    delete []charData;
    charData = newCharData;
    CharToQimage();
}

int MyImage::BilinearInterpolation(double x, double y){
    if(x < 0 || x >= height || y < 0 || y >= bytesPerLine){
        return 0;
    }
    if(x-(int)x < 1e-18 && y-(int)y < 1e-18){
        return charData[(int)x][(int)y];
    }
    int x1 = (int)x;
    int x2;
    if(x1 + 1 >= height){
       x2 = x1;
       x1 = x1 - 1;
    }
    else x2 = x1 + 1;
    int y1 = (int)y;
    int y2;
    if(y1 + 1 >= bytesPerLine){
       y2 = y1;
       y1 -= 1;
    }else y2 = y1 + 1;
    //BilinearInterpolation
    int ans = (charData[x1][y1]*(x2-x)*(y2-y) + charData[x2][y1]*(x-x1)*(y2-y) + charData[x1][y2]*(x2-x)*(y-y1) + charData[x2][y2]*(x-x1)*(y-y1));
    return ans;
}

void MyImage::Translation(int x, int y){
    double matrix[1][2][3] = {{{1.0,0.0,(double)x},
                          {0.0,1.0,(double)y}}};
    AffineTransformation(matrix, 1);
}

void MyImage::Scaling(double x, double y){
    double matrix[1][2][3] = {{{x,0.0,0.0},
                          {0.0,y,0.0}}};
    AffineTransformation(matrix, 1);
}

void MyImage::Rotation(double theta){
    double matrix[3][2][3] = {
                                {
                                  {1.0,0.0,-((double)height)/2},
                                  {0.0,1.0,-((double)bytesPerLine)/2}
                                },
                                {
                                  {cos(theta), -sin(theta), 0},
                                  {sin(theta), cos(theta), 0}
                                },
                                {
                                  {1.0,0.0,((double)height)/2},
                                  {0.0,1.0,((double)bytesPerLine)/2}
                                }
                             };
    AffineTransformation(matrix, 3);
}



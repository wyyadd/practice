#include <myimage.h>
#include <QImage>
#include <QPixmap>
#include <QtDebug>
#include <QFile>
#include <QDataStream>

MyImage::MyImage(QImage image){
    imageData = image;
    height = imageData.height();
    width = imageData.width();
    type = "bmp";
    QImageToChar();
}

MyImage::MyImage(QString imageAddress){
    QFile file(imageAddress);
    if(!file.open(QFile::ReadOnly))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }
    QDataStream in(&file);
    //intel order
    in.setByteOrder(QDataStream::LittleEndian);
    //init
    quint32 w,h;
    in >> w;
    in >> h;
    width =  w;
    height = h;
    type = "raw0";
    //array
    rawData = new unsigned short[width*height];
    charData = new unsigned char[width*height];
    long i = 0;
    while (!in.atEnd()) {
        in >> rawData[i++];
    }
}

MyImage::~MyImage(){
    if(charData != nullptr)
        delete []charData;
    if(rawData != nullptr)
        delete []rawData;
}

void MyImage::QImageToChar(){
    charData = new unsigned char [height*width];
    for(long i = 0; i < height; ++i){
        for(long j = 0; j < width; ++j){
              charData[i*width + j] = *(imageData.scanLine(i) + j);
        }
    }
}

void MyImage::CharToQimage(){
    imageData = QImage(charData,width,height,width,QImage::Format_Grayscale8);
}

const QImage &MyImage::getImageData() const
{
    return imageData;
}

void MyImage::setImageData(const QImage &newImageData)
{
    imageData = newImageData;
}

void MyImage::AffineTransformation(double matrixs[][2][3], long num){
    //创建一个新的数组
    unsigned char *newCharData = new unsigned char [height*width];
   //遍历
    for(long i = 0; i < height; ++i){
        for(long j = 0; j < width; ++j){
            double x = i;
            double y = j;
            for(long k = 0; k < num; ++k){
                double x1 = matrixs[k][0][0]*x + matrixs[k][0][1]* y + matrixs[k][0][2];
                double y1 = matrixs[k][1][0]*x + matrixs[k][1][1]* y + matrixs[k][1][2];
                x = x1;
                y = y1;
            }
            newCharData[i*width + j] = BilinearInterpolation(x,y);
        }
    }
    delete []charData;
    charData = newCharData;
    CharToQimage();
}

long MyImage::BilinearInterpolation(double x, double y){
    if(x < 0 || x >= height || y < 0 || y >= width){
        return 0;
    }
    if(x-(long)x < 1e-18 && y-(long)y < 1e-18){
        return charData[(long)x * width + (long)y];
    }
    long x1 = (long)x;
    long x2;
    if(x1 + 1 >= height){
       x2 = x1;
       x1 = x1 - 1;
    }
    else x2 = x1 + 1;
    long y1 = (long)y;
    long y2;
    if(y1 + 1 >= width){
       y2 = y1;
       y1 -= 1;
    }else y2 = y1 + 1;
    //BilinearInterpolation
    long ans = (charData[x1*width + y1]*(x2-x)*(y2-y) +
            charData[x2*width + y1]*(x-x1)*(y2-y) +
            charData[x1*width + y2]*(x2-x)*(y-y1) +
            charData[x2*width + y2]*(x-x1)*(y-y1));
    return ans;
}

void MyImage::Translation(long x, long y){
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
                                  {0.0,1.0,-((double)width)/2}
                                },
                                {
                                  {cos(theta), -sin(theta), 0},
                                  {sin(theta), cos(theta), 0}
                                },
                                {
                                  {1.0,0.0,((double)height)/2},
                                  {0.0,1.0,((double)width)/2}
                                }
                             };
    AffineTransformation(matrix, 3);
}

bool MyImage::windowsMapping(long pos, long w){
   type = "raw1";
   long downLimit = pos - w/2;
   long upLimit = pos + w/2;
   if(downLimit < 0 || upLimit > 4096)
       return false;
   for(int i = 0; i < width*height; ++i){
       if(rawData[i] < downLimit){
           charData[i] = 0;
           continue;
       }
       if(rawData[i] > upLimit){
           charData[i] = 255;
           continue;
       }
       charData[i] = (rawData[i]-downLimit)*255/w;
   }
   CharToQimage();
   return true;
}

void MyImage::UnsharpMasking(double alpha){
    // init Laplacian and alpha
//    double alpha = 0.5;
    double laplacian[3][3] = {{0,-1,0},{-1,4,-1},{0,-1,0}};
    for(int i =0; i<3; ++i)
        for(int j = 0; j < 3; ++j)
            laplacian[i][j]*=alpha;
    int* newCharData = Conv(laplacian);
    // do UnsharpMasking
    for(int i = 0; i < height*width; ++i){
        int temp = newCharData[i] + charData[i];
        if(temp < 0)
            temp = 0;
        if(temp > 255)
            temp = 255;
        charData[i] = (unsigned char) temp;
    }
    delete []newCharData;
    CharToQimage();
}

void MyImage::GaussianFilter(){
    double kernel[3][3] = {{0.05711826, 0.12475775, 0.05711826},{0.12475775, 0.27249597, 0.12475775},{0.05711826, 0.12475775, 0.05711826}};
    int *newCharData = Conv(kernel);
    for(int i = 0; i < height*width; ++i){
        if(newCharData[i] < 0)
            newCharData[i] = 0;
        if(newCharData[i] > 255)
            newCharData[i] = 255;
        charData[i] = newCharData[i];
    }
    delete []newCharData;
}

int* MyImage::Conv(double matrix[3][3]){
    // copy a new chardata with padding = 1 filled by zero
    unsigned char newCharData[(height+2)*(width+2)];
    std::fill(newCharData,newCharData+(height+2)*(width+2),0);
    int *result = new int[height*width];
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            newCharData[(i+1)*width+(j+1)] = charData[i*width+j];
        }
    }
    // walk through
    for(int i = 1; i < height+1; ++i){
        for(int j = 1; j < width+1; ++j){
            double value = 0;
            // conv
            for(int x = 0; x < 3; ++x)
                for(int y = 0; y < 3; ++y)
                    value += matrix[x][y]*newCharData[(i+x-1)*width+j+y-1];
            // 四舍五入
            value = (int)(value+0.5);
            result[(i-1)*width+j-1] = value;
        }
    }
    return result;
}

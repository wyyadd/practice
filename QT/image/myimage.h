#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <QImage>
#include <QPixmap>

class MyImage
{
public:
    MyImage(QImage imageData);
    MyImage(QString imageAddress); //读raw图片
    ~MyImage();
    QString type; //图像类型
    void QImageToChar(); //转换成unsigned char
    void CharToQimage(); //由unsigned char转换成QImage
    const QImage &getImageData() const;
    void setImageData(const QImage &newImageData);
    void AffineTransformation(double matrixs[][2][3], long num); //仿射变换
    long BilinearInterpolation(double x, double y); //双线性插值
    bool windowsMapping(long pos, long w); //灰度窗
    void Translation(long x, long y); //平移变换， y-水平方向， x-竖直方向
    void Scaling(double x, double y); //缩放变换， y-水平缩放, x-竖直缩放
    void Rotation(double m); //m旋转角度
    void UnsharpMasking(double alpha); //细节增强
    void GaussianFilter(); //高斯过滤器
    void SobelFeatureExtract(); //Sobel特征提取
    int* Conv(double matrix[3][3]); //卷积

private:
    QImage imageData;
    unsigned char *charData = nullptr; //bmp
    unsigned short *rawData = nullptr; //raw
    long height = 0;
    long width = 0;
};

#endif // MYIMAGE_H

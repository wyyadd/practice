#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <QImage>
#include <QPixmap>

class MyImage
{
public:
    MyImage(QImage imageData);
    ~MyImage();
    void QImageToChar(); //转换成unsigned char
    void CharToQimage(); //由unsigned char转换成QImage
    const QImage &getImageData() const;
    void setImageData(const QImage &newImageData);
    void AffineTransformation(double matrixs[][2][3], int num); //仿射变换
    void Translation(int x, int y); //平移变换， y-水平方向， x-竖直方向
    void Scaling(double x, double y); //缩放变换， y-水平缩放, x-竖直缩放
    void Rotation(double m); //m旋转角度
    int BilinearInterpolation(double x, double y); //双线性插值

private:
    QImage imageData;
    unsigned char **charData;
    int height;
    int width;
    int bytesPerLine;
};

#endif // MYIMAGE_H

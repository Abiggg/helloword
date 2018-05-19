#include "winimagestrength.h"
#include "ui_winimagestrength.h"

using namespace cv;
using namespace std;

WinImageStrength::WinImageStrength(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinImageStrength)
{
    ui->setupUi(this);
}

WinImageStrength::~WinImageStrength()
{
    delete ui;
}

void WinImageStrength::on_PbbackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}

void WinImageStrength::on_PbOpenFile_clicked()
{

    CHECK(QtCv.OpenImageFile(matIn));   //open image file
    CHECK(QtCv.cvMat2QImage(matIn,QImgIn));     //convert image file
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn)); //show image in inputLable
}

void WinImageStrength::on_PbSaveFile_clicked()
{
    CHECK(QtCv.QImage2cvMat(QImgOut, matOut)); //change qimg to img
    CHECK(QtCv.SaveImageFile(matOut)); //save image
}

void WinImageStrength::on_PbAverage_clicked()
{

}

#include "winbeatifyphoto.h"
#include "ui_winbeatifyphoto.h"
#include <QString>
#include "winaiphoto.h"

using namespace cv;
using namespace std;

/****************************************************************************************file open start*/

WinBeatifyPhoto::WinBeatifyPhoto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinBeatifyPhoto)
{
    ui->setupUi(this);
}

WinBeatifyPhoto::~WinBeatifyPhoto()
{
    delete ui;
}

/*reopen this win*/
void WinBeatifyPhoto::gotoBeatifyPhoto_clicked_reshow(Mat SrcMat)
{
    matIn = SrcMat;
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matIn, QImgIn));
    CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
    this->show();

    /*Init other things*/
    /*init SpinBox*/
    SpinBoxInit();

    /*Slider Init*/
    VectorSliderInit();

    /*TempSavemat init*/
    TempSavematInit();
}

/*SpinBox Init*/
void WinBeatifyPhoto::SpinBoxInit()
{
    ui->SbCorrosion->setRange(3,255);
    ui->SbCorrosion->setSingleStep(2);

    ui->SbExpand->setRange(3,255);
    ui->SbExpand->setSingleStep(2);

    ui->SbFuzzy->setRange(1,99);
    ui->SbFuzzy->setSingleStep(2);

    ui->SbBinarization->setRange(0,255);
    ui->SbBinarization->setSingleStep(1);
    ui->SbBinarization->setValue(128);

    ui->SbSharpen->setRange(1,99);
    ui->SbSharpen->setSingleStep(2);

    ui->SbRatation->setRange(0,10000);
    ui->SbRatation->setSingleStep(1);

    ui->SbGaussian->setRange(1,99);
    ui->SbGaussian->setSingleStep(2);

    ui->SbSketch->setRange(1,255);
    ui->SbSketch->setSingleStep(1);

    ui->SbOilPaint->setRange(3,255);
    ui->SbOilPaint->setSingleStep(2);

    ui->SbFFtLowFilter->setRange(1,255);
    ui->SbFFtLowFilter->setSingleStep(1);

    ui->SbFFtHighFilter->setRange(1,255);
    ui->SbFFtHighFilter->setSingleStep(1);
    ui->SbFFtHighFilter->setValue(100);

    ui->SbFFtBandFilter0->setRange(1,255);
    ui->SbFFtBandFilter0->setSingleStep(1);
    ui->SbFFtBandFilter1->setRange(1,255);
    ui->SbFFtBandFilter1->setSingleStep(1);
    ui->SbFFtBandFilter1->setValue(50);
}

/*Vector Slider init*/
void WinBeatifyPhoto::VectorSliderInit()
{
    ui->VsBrightness->setRange(0,200);
    ui->VsBrightness->setSliderPosition(100);

    ui->VsConstration->setRange(0,200);
    ui->VsConstration->setSliderPosition(100);

    ui->VsSaturation->setRange(0,200);
    ui->VsSaturation->setSliderPosition(100);
}

/*Temprory save mat Init, used for pubotton "Last" and "Next"*/
void WinBeatifyPhoto::TempSavematInit()
{
    /*Init last TempSavemat*/
    TempSavemat_pos_last = 0;
    TempSavemat_last = new DoubleLq_S;
    TempSavemat_last->DoubleLqInit(&TempSavemat_last, matCur);

    /*Init next TempSavemat*/
    TempSavemat_pos_next = 0; /*current pic pos*/
    TempSavemat_next = new DoubleLq_S;
    TempSavemat_next->DoubleLqInit(&TempSavemat_next, matCur);
}

/*Win init*/
void WinBeatifyPhoto::WinInit()
{
    /*Init Class variable*/

    /*init SpinBox*/
    SpinBoxInit();

    /*Slider Init*/
    VectorSliderInit();

    /*init Input and Output Box*/
    if(PhotoFlag)
    {
         matCur = matIn.clone();
         CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
         ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
         ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
         PhotoFlag = false;
    }
    else
    {
        matIn = imread("/home/abig/bitch.png");
        matCur = matIn.clone();
        CHECK(QtCv.cvMat2QImage(matCur, QImgIn));
        CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
        ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn));
        ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
    }
    /*TempSavemat init*/
    TempSavematInit();
}


/*Open Image*/
void WinBeatifyPhoto::on_PbOpenFile_clicked()
{
    CHECK(QtCv.OpenImageFile(matIn));   //open image file
    CHECK(QtCv.cvMat2QImage(matIn,QImgIn));     //convert image file
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matCur, QImgOut));
    ui->LbInputImage->setPixmap(QPixmap::fromImage(QImgIn)); //show image in inputLable
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(QImgOut));
}

/*PushBotton Back to Main*/
void WinBeatifyPhoto::on_PbBackToMain_clicked()
{
    emit WinDisplay();
    this->close();
}

/*go to winAiPhoto*/
void WinBeatifyPhoto::on_PbWinAiPhoto_clicked()
{
    emit WinAiDisplay(matCur);
    this->close();
}

/*PushBotton Last*/
void WinBeatifyPhoto::on_PbLast_clicked()
{
    int i = 1;
    QImage qimg;
    pDoubleLq_S temp = TempSavemat_last;

    /*judge if has steps save*/
    if(TempSavemat_pos_last > 0)
    {
        while(i < TempSavemat_pos_last)
        {
            temp = temp->pNext;
            i += 1;
        }
        TempSavemat_pos_last -= 1;

        /*show picture*/
        matCur = (temp->mat).clone();
        CHECK(QtCv.cvMat2QImage(matCur, qimg));
        ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));

        /*save the tempority value into next*/
        if(temp->pNext == NULL)
        {
           ui->TbHint->setText(QString::fromStdString("no more steps to last!"));
        }
        else
        {
            TempSavemat_next->DoubleLqAddNode(TempSavemat_next, temp->pNext->mat);
            TempSavemat_pos_next += 1;
        }

        /*delete last mat in TempSavemat_last*/
        TempSavemat_last->DoubleLqDeletRearNode(TempSavemat_last);
    }
    else
    {
        ui->TbHint->setText(QString::fromStdString("no more steps to last!"));
    }
}

/*PushBotton Next*/
void WinBeatifyPhoto::on_PbNext_clicked()
{
    int i = 1;
    QImage qimg;
    pDoubleLq_S temp = TempSavemat_next;

    /*judge if has steps save*/
    if(TempSavemat_pos_next > 0)
    {
        while(i < TempSavemat_pos_next+1)
        {
            temp = temp->pNext;
            i += 1;
        }

        TempSavemat_pos_next -= 1;

        /*show picture*/
        matCur = (temp->mat).clone();
        CHECK(QtCv.cvMat2QImage(matCur, qimg));
        ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));

        /*save the tempority value into next*/
        TempSavemat_last->DoubleLqAddNode(TempSavemat_last, matCur);
        TempSavemat_pos_last += 1;

        /*delete last mat in TempSavemat_last*/
        TempSavemat_next->DoubleLqDeletRearNode(TempSavemat_next);
    }
    else
    {
        ui->TbHint->setText(QString::fromStdString("no more steps to next!"));
    }
}

/*PushBotton Confirm*/
void WinBeatifyPhoto::on_PbConfirm_clicked()
{
    int flag;
    Mat matLast;
    //QtCv.CompareMat(matCur, TempSavemat_last->mat, flag); /*compare current mat with origin mat*/
    if(!ImageBasic.matOut.empty())
    {
        TempSavemat_last->DoubleLqGetLast(TempSavemat_last,matLast); /*Get last mat*/
        matCur = ImageBasic.matOut;  /*get current matCur*/
        QtCv.CompareMat(matCur, matLast, flag); /*compare current mat with last save mat*/

        if(flag) /*if mat changed*/
        {
            if(TempSavemat_pos_last < MaxTempSaveNum)
            {
                TempSavemat_last->DoubleLqAddNode(TempSavemat_last, matCur);
                TempSavemat_pos_last += 1;
                ui->TbHint->setText(QString::fromStdString("save success!"));
            }
            else
            {
                TempSavemat_last->DoubleLqDelet2ndNode(TempSavemat_last);
                TempSavemat_last->DoubleLqAddNode(TempSavemat_last, matCur);
                ui->TbHint->setText(QString::fromStdString("save success!"));
            }
        }
        else  /*if mat unchanged*/
        {
            ui->TbHint->setText(QString::fromStdString("no change need to be save"));
        }
    }
    else
    {
        ui->TbHint->setText(QString::fromStdString("no change need to be save33333"));
    }


}

/*Reset in Oringal Picture*/
void WinBeatifyPhoto::on_PbResetAll_clicked()
{
    QImage qimg;
    matCur = matIn.clone();
    CHECK(QtCv.cvMat2QImage(matCur, qimg));
     ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Save Picture*/
void WinBeatifyPhoto::on_PbSaveFile_clicked()
{
    CHECK(QtCv.SaveImageFile(matCur)); //save image
    ui->TbHint->setText(QString::fromStdString("save image \
    , please choose this storage root and putting the image name"));
}

/****************************************************************************************file open close end*/

/****************************************************************************************image process start*/

/*Biarization*/
void WinBeatifyPhoto::on_PbBiarization_clicked()
{
    QImage qimg;
    uint32 BinaryThrehold = ui->SbBinarization->value();
    CHECK(ImageBasic.ImageBinary(matCur, qimg, BinaryThrehold));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Equration*/
void WinBeatifyPhoto::on_PbEquration_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageEquration(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*GrayScale*/
void WinBeatifyPhoto::on_PbGrayScale_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageGrayscal(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Minior Y*/
void WinBeatifyPhoto::on_PbYMinior_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageYminor(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Minor X*/
void WinBeatifyPhoto::on_PbXMinior_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageXminor(matCur,qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Fuzzy*/
void WinBeatifyPhoto::on_PbFuzzy_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbFuzzy->value();
    CHECK(ImageBasic.ImageFuzzyAverage(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Gaussian Fuzzy*/
void WinBeatifyPhoto::on_PbGaussian_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbGaussian->value();

    CHECK(ImageBasic.ImageGaussian(matCur,qimg,FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Bright*/
void WinBeatifyPhoto::on_VsBrightness_sliderMoved(int position)
{
    QImage qimg;
    uint8 ratioBrightness = position;
    CHECK(ImageBasic.ImageBrightness(matCur, qimg, ratioBrightness));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Constrat*/
void WinBeatifyPhoto::on_VsConstration_sliderMoved(int position)
{
    QImage qimg;
    uint8 ratioConstrast = position;
    CHECK(ImageBasic.ImageConstrast(matCur, qimg, ratioConstrast));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Saturation*/
void WinBeatifyPhoto::on_VsSaturation_sliderMoved(int position)
{
    QImage qimg;
    uint8 ratioSaturation = position;
    CHECK(ImageBasic.ImageSaturation(matCur, qimg, ratioSaturation));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Classical Style*/
void WinBeatifyPhoto::on_PbClassical_clicked()
{
    QImage qimg;
    CHECK(ImageBasic.ImageClassical(matCur, qimg));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Sketch style*/
void WinBeatifyPhoto::on_PbSketch_clicked()
{
    QImage qimg;
    uint8 SketchThrehold = (uint8) ui->SbSketch->value();

    CHECK(ImageBasic.ImageSketch(matCur,qimg,SketchThrehold));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*OilPaint style*/
void WinBeatifyPhoto::on_PbOilPaint_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbOilPaint->value();

    CHECK(ImageBasic.ImageOilPaint(matCur,qimg,FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Laplace Shapen*/
void WinBeatifyPhoto::on_PbLaplaceShape_clicked()
{
    QImage qimg;
    uint8 FilterSize = 3;
    CHECK(ImageBasic.ImageScalar(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

void WinBeatifyPhoto::on_PbShapen_clicked()
{
    QImage qimg;
    uint8 RatioShape = (uint8) ui->SbSharpen->value();
    CHECK(ImageBasic.ImageShapen(matCur, qimg, RatioShape));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

void WinBeatifyPhoto::on_PbCorrosion_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbCorrosion->value();
    CHECK(ImageBasic.ImageCorrosion(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

void WinBeatifyPhoto::on_PbExpand_clicked()
{
    QImage qimg;
    uint8 FilterSize = (uint8) ui->SbExpand->value();
    CHECK(ImageBasic.ImageExpand(matCur, qimg, FilterSize));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*Ratation Transform*/
void WinBeatifyPhoto::on_PbRatation_clicked()
{
    QImage qimg;
    uint8 angle = (uint8) ui->SbRatation->value();
    CHECK(ImageBasic.ImageRatation(matCur, qimg, angle));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*FFT Band Filter */
void WinBeatifyPhoto::on_PbFFtBandFilter_clicked()
{
    QImage qimg;
    int CutOff0 = ui->SbFFtBandFilter0->value();
    int CutOff1 = ui->SbFFtBandFilter1->value();
    CHECK(ImageBasic.ImageCvFFtBandPass(matCur, qimg, CutOff0, CutOff1));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*FFT low FILTER*/
void WinBeatifyPhoto::on_PbFFtLowFilter_clicked()
{
    QImage qimg;
    int CutOff = ui->SbFFtLowFilter->value();
    CHECK(ImageBasic.ImageCvFFtLowPass(matCur, qimg, CutOff));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

/*FFT High FILTER*/
void WinBeatifyPhoto::on_PbFFtHighFilter_clicked()
{
    QImage qimg;
    int CutOff = ui->SbFFtHighFilter->value();
    CHECK(ImageBasic.ImageCvFFtHighPass(matCur, qimg, CutOff));
    ui->LbOutputImage->setPixmap(QPixmap::fromImage(qimg));
}

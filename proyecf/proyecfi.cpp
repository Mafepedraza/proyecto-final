#include "proyecfi.h"
#include "ui_proyecfi.h"
#include <QString>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <QDateTime>
#include <QDebug>
using namespace std;

proyecfi::proyecfi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::proyecfi)
{
    ui->setupUi(this);
    ui->ip->setText("186.155.208.171");
    ui->puerto->setText("65000");
    ui->txt->setText(" ");
}

proyecfi::~proyecfi()
{
    delete ui;
}

void proyecfi::on_pushButton_clicked()
{

    abrirdatos();

}

void proyecfi::abrirdatos()
{
    QString direc= ui->ip->text();
    QString car= ui->carnet->text();
    QString pue= ui->puerto->text();
    QString command= direc+" "+car+" "+pue;
    command="/home/alse/proyecf/./commProc.bin "+command;
    std::system(qPrintable(command));
    string tex;
    fstream myFILE("/home/alse/proyecf/datosRecibidos.txt");
    while (getline(myFILE,tex)) {
        QString vec=QString::fromStdString(tex);
        datos(vec);
        ui->txt->setText(QString::fromStdString(tex));
    }
    myFILE.close();
}

void proyecfi::datos(QString vec)
{
    bool convetOK;
    QString car= ui->carnet->text();
    QString Tv= car.mid(1,2);
    float tvp=Tv.toFloat()/100;
    QString Tvol= car.mid(4,1);
    float tvol=Tvol.toFloat()/100;
    unsigned long int n= ui->carnet->text().toULong( &convetOK);
    float Tt = n%10/100;
    int ve= vec.indexOf("velocidad");
    int fe= vec.indexOf("frecuencia");
    int vo= vec.indexOf("voltaje");
    int tem= vec.indexOf("temperatura");
    int tiem= vec.indexOf("tiempo");

    QDateTime fech= QDateTime::currentDateTime();
    QString fecha= fech.toString("dd/MM/yyyy hh:mm:ss");
    ui->resultado->addItem("Tiempo= "+fecha);

    QString velocidad= vec.mid(ve+11,fe-(13+ve));
    float vel=velocidad.toFloat();
    mostrar_datos(vel, tvp, 1800,"Velocidad= ");

    QString Frecuencia= vec.mid(fe+12,vo-fe-14);
    float fre=Frecuencia.toFloat();
    mostrar_datos(fre, 0.05, 60,"Frecuencia= ");

    QString Voltaje= vec.mid(vo+9,tem-vo-11);
    float vol=Voltaje.toFloat();
    mostrar_datos(vol, tvol, 120,"Voltaje= ");

    QString Temperatura= vec.mid(tem+13,tiem-tem-15);
    float temp=Temperatura.toFloat();
    mostrar_datos(temp, Tt, 40,"Temperatura= ");

    ui->resultado->addItem("");
}

void proyecfi::mostrar_datos(float vari, float por, float Vcrit, QString fun)
{
    if ((Vcrit-por)> vari || vari >(Vcrit+por))
    {ui->resultado->addItem(fun+QString::number(vari)+" ERROR");
        ui->resultado->setStyleSheet("color:orange");}
        else {
            ui->resultado->addItem(fun+QString::number(vari));

    }
}


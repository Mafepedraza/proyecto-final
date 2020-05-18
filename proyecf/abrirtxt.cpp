#include "abrirtxt.h"
#include <fstream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

abrirtxt::abrirtxt(QString direc, QString car, QString pue,QString velocidad)
{
    QString Tv= car.mid(2,3);
    float tvp=Tv.toFloat()/100;
    QString Tvol= car.mid(5,5);
    float tvol=Tvol.toFloat()/100;
    QString Ttf= car.mid(7,7);
    float Tt = Ttf.toFloat()/100;
    QString vec;

    QString command= direc+" "+car+" "+pue;
    command="/home/alse/proyecf/./commProc.bin "+command;
    std::system(qPrintable(command));
    string tex;
    fstream myFILE("/home/alse/proyecf/datosRecibidos.txt");
    while (getline(myFILE,tex)) {
        vec=QString::fromStdString(tex);
    }
    myFILE.close();
    int ve= vec.indexOf("velocidad");
    int fe= vec.indexOf("frecuencia");
    int vo= vec.indexOf("voltaje");
    int tem= vec.indexOf("temperatura");
    int tiem= vec.indexOf("tiempo");

    velocidad= vec.mid(ve+11,fe-(13+ve));
    float vel=velocidad.toFloat();

    QString Frecuencia= vec.mid(fe+12,vo-fe-14);
    float fre=Frecuencia.toFloat();

    QString Voltaje= vec.mid(vo+9,tem-vo-11);
    float vol=Voltaje.toFloat();

    QString Temperatura= vec.mid(tem+13,tiem-tem-15);
    float temp=Temperatura.toFloat();

}



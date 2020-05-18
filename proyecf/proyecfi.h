#ifndef PROYECFI_H
#define PROYECFI_H
#include "abrirtxt.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class proyecfi; }
QT_END_NAMESPACE

class proyecfi : public QMainWindow
{
    Q_OBJECT

public:
    proyecfi(QWidget *parent = nullptr);
    ~proyecfi();

private slots:
    void on_pushButton_clicked();
    void abrirdatos();
    void datos(QString vec);
    void mostrar_datos(float vari,float por,float Vcrit,QString fun);
private:
    Ui::proyecfi *ui;
};
#endif // PROYECFI_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include "qlabelimageviewer.h"
#include "pyramid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionUpload_triggered();

    void on_layersComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    ImageViewer *imageViewer;

    Pyramid* p = nullptr;
};
#endif // MAINWINDOW_H

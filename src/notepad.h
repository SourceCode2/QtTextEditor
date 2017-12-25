#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <fstream>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QFont>
#include <QFontDialog>
#include <QMessageBox>
#include <QTextStream>
namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionFont_triggered();

private:
    Ui::Notepad *ui;
    QString CurrentFile;
};

#endif // NOTEPAD_H

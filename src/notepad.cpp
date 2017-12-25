#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionNew_triggered()
{
    CurrentFile = "";
    ui->textEdit->setText("");
}

void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    CurrentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "File not opened");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void Notepad::on_actionSave_triggered()
{
    QFile file(CurrentFile);
    if (!file.open(QIODevice::ReadWrite | QFile::Text)) {
        QMessageBox::warning(this, "..", "No file opened. Use Save As");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void Notepad::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QFile::Text)) {
        QMessageBox::warning(this, "..", "No file opened.");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void Notepad::on_actionExit_triggered()
{
    std::exit(-1);
}

void Notepad::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected) {
        ui->textEdit->setFont(font);
    }
}

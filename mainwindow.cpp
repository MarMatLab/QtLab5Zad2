#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->pushButtonLeft->setEnabled(false);
    this->ui->calendarWidget->setSelectedDate(QDate::currentDate());
    this->ui->dateEdit->setDate(QDate::currentDate());
    this->ui->statusbar->showMessage("Pierwszy");

    connect(ui->kwadratSpin, &QDoubleSpinBox::valueChanged, this, &MainWindow::calculateSquare);

    connect(ui->pushButtonLeft, &QPushButton::clicked, this, &MainWindow::left_clicked);
    connect(ui->pushButtonRight, &QPushButton::clicked, this, &MainWindow::right_clicked);

    connect(ui->dateEdit, &QDateEdit::userDateChanged, this, &MainWindow::dateEdit_changed);
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::calendar_date_changed);

    connect(this->ui->radioButtons, &QButtonGroup::idClicked, this, &MainWindow::radio_clicked);

    connect(ui->horizontalSliderRed, &QSlider::valueChanged, this, &MainWindow::change_red_spin);
    connect(ui->horizontalSliderGreen, &QSlider::valueChanged, this, &MainWindow::change_green_spin);
    connect(ui->horizontalSliderBlue, &QSlider::valueChanged, this, &MainWindow::change_blue_spin);

    connect(ui->spinBoxRed, &QSpinBox::valueChanged, this, &MainWindow::change_red_slider_and_pixmap);
    connect(ui->spinBoxGreen, &QSpinBox::valueChanged, this, &MainWindow::change_green_slider_and_pixmap);
    connect(ui->spinBoxBlue, &QSpinBox::valueChanged, this, &MainWindow::change_blue_slider_and_pixmap);

    updateColor();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::calculateSquare(double arg1)
{
    this->ui->kwadratLabel->setText(QString::number(arg1 * arg1, 'f', 4));
}

void MainWindow::left_clicked()
{
    this->ui->pushButtonLeft->setEnabled(false);
    this->ui->pushButtonRight->setEnabled(true);
}

void MainWindow::right_clicked()
{
    this->ui->pushButtonLeft->setEnabled(true);
    this->ui->pushButtonRight->setEnabled(false);
}

void MainWindow::dateEdit_changed(const QDate &date)
{
    this->ui->calendarWidget->setSelectedDate(date);
}

void MainWindow::calendar_date_changed(const QDate &date)
{
    this->ui->dateEdit->setDate(date);
}

void MainWindow::radio_clicked(int id)
{
    QString value = "";
    if(id == this->ui->radioButtons->id(this->ui->rb1))
    {
        value = "Pierwszy";
    }

    if(id == this->ui->radioButtons->id(this->ui->rb2))
    {
        value = "Drugi";
    }

    if(id == this->ui->radioButtons->id(this->ui->rb3))
    {
        value = "Trzeci";
    }

    this->ui->statusbar->showMessage(value);
}


void MainWindow::change_red_spin(int val)
{
    ui->spinBoxRed->setValue(val);
}

void MainWindow::change_green_spin(int val)
{
    ui->spinBoxGreen->setValue(val);
}

void MainWindow::change_blue_spin(int val)
{
    ui->spinBoxBlue->setValue(val);
}
void MainWindow::change_red_slider_and_pixmap(int val)
{
    ui->horizontalSliderRed->setValue(val);
    updateColor();
}

void MainWindow::change_green_slider_and_pixmap(int val)
{
    ui->horizontalSliderGreen->setValue(val);
    updateColor();
}

void MainWindow::change_blue_slider_and_pixmap(int val)
{
    ui->horizontalSliderBlue->setValue(val);
    updateColor();
}

void MainWindow::updateColor()
{
    static size_t i = 0;
    QPixmap mapa(this->ui->labelPixmap->size());
    mapa.fill(QColor(this->ui->spinBoxRed->value(), this->ui->spinBoxGreen->value(), this->ui->spinBoxBlue->value()));
    this->ui->labelPixmap->setPixmap(mapa);
    i++;
    qInfo() << "Zmieniono kolor" << i << "razy.";
}

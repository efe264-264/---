#ifndef SUBJECTWINDOW_H
#define SUBJECTWINDOW_H

#include <QMainWindow>

namespace Ui {
class subjectwindow;
}

class subjectwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit subjectwindow(QWidget *parent = nullptr);
    ~subjectwindow();

private slots:


    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::subjectwindow *ui;
};

#endif // SUBJECTWINDOW_H

#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>

#include <QSqlDatabase>
namespace Ui {
class newwindow;
}

class newwindow : public QWidget
{
    Q_OBJECT

public:
    explicit newwindow(QWidget *parent = nullptr);
    ~newwindow();

private:
    Ui::newwindow *ui;

};

#endif // NEWWINDOW_H

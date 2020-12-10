#ifndef EML_H
#define EML_H

#include <QWidget>

namespace Ui {
class eml;
}

class eml : public QWidget
{
    Q_OBJECT

public:
    explicit eml(QWidget *parent = 0);
    ~eml();
    void send();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::eml *ui;
};

#endif // EML_H

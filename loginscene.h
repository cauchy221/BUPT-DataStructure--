#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QWidget>

const int width_s = 600;
const int height_s = 400;

namespace Ui {
    class LoginScene;
}

class LoginScene : public QWidget
{
    Q_OBJECT
public:
    explicit LoginScene(QWidget *parent = nullptr);

private:
    Ui::LoginScene *ui;

signals:

private slots:
    void on_loginBtn_clicked();
    void on_registerBtn_clicked();
};

#endif // LOGINSCENE_H

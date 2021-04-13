#include "loginscene.h"
#include "ui_LoginScene.h"
#include <QIcon>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "mainwindow.h"

LoginScene::LoginScene(QWidget *parent) : QWidget(parent), ui(new Ui::LoginScene)
{
    //登陆界面 class与ui的连接
    ui->setupUi(this);
    //基本参数设置
    this->setFixedSize(width_s, height_s);
    this->setWindowTitle(QStringLiteral("登录界面"));
    this->setWindowIcon(QIcon(":/res/logo.png"));

    //ui 上方logo图片
    ui->logo->setAlignment(Qt::AlignHCenter);
    QPixmap logoPix;
    logoPix.load(":/res/loginback.jpeg");
    logoPix = logoPix.scaled(width_s, height_s*0.4);
    ui->logo->setPixmap(logoPix);

    //ui 下方登录
    ui->loginBtn->setGeometry(200, 110, 170, 40);
    //输入框 图片

    //输入框 默认提示文字 聚焦则文字消失

    //设置成淡蓝色
    QPalette pal(ui->widget_login->palette());
    pal.setColor(QPalette::Background, "#ebf2f9");
    ui->widget_login->setAutoFillBackground(true);
    ui->widget_login->setPalette(pal);

}

//点击登录按钮
void LoginScene::on_loginBtn_clicked()
{
    //输入的用户名密码
    QString username = ui->username->text();
    QString password = ui->password->text();

    //查询数据库验证 跳转逻辑
    //利用自带的模型
    QSqlTableModel *model =new QSqlTableModel;
    model->setTable("userinfo");
    model->setFilter(QString("username = '%1' and password = '%2'").arg(username).arg(password));
    model->select();

    //检测是否查询到数据
    int row = model->rowCount();
    if (row > 0) {
        //关闭登陆页面 跳转到mainwindow
        MainWindow *w;
        w = new MainWindow();
        w->show();
        this->hide();
    }
    else {
        QMessageBox::information(this, QStringLiteral("登录提示"), QStringLiteral("用户名或密码错误"));
    }

}

//点击注册按钮
void LoginScene::on_registerBtn_clicked()
{
    //输入的用户名密码
    QString username = ui->username->text();
    QString password = ui->password->text();

    //向数据库插入新数据
    QString cmd = QString("insert into userinfo values('%1', '%2')").arg(username).arg(password);
    QSqlQuery query;
    if(query.exec(cmd)) {
        QMessageBox::information(this, QStringLiteral("登录提示"), QStringLiteral("注册成功"));
    }
    else {
        QMessageBox::information(this, QStringLiteral("登录提示"), QStringLiteral("注册失败"));
    }
}





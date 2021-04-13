#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QSqlDatabase>
#include "loginscene.h"
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //程序启动时的欢迎界面
    QSplashScreen *splash = new QSplashScreen;
    //欢迎界面 图片
    QPixmap welcomePix;
    welcomePix.load(":/res/Welcome.jpeg");
    welcomePix = welcomePix.scaled(width_s, height_s);
    splash->setPixmap(welcomePix);
    //欢迎界面 文字
    splash->showMessage(QStringLiteral("制作人:刘欣悦 南雅丰 梁咏琪"), Qt::AlignRight | Qt::AlignBottom, Qt::white);
    splash->show();


    //创建登录界面数据库 用户信息数据库
    QSqlDatabase db_user = QSqlDatabase::addDatabase("QSQLITE");
    db_user.setDatabaseName("userInfo.db");
    if (db_user.open()) {
        qDebug() << "open database successfully";
    }
    else {
        qDebug() << "failed to open database";
    }

    //创建一个数据库表 存储用户名、密码
    QString cmd = "create table if not exists userinfo (username varchar(64), password varchar(64))";
    //执行sql语句
    QSqlQuery query;
    if (query.exec(cmd)) {
        qDebug() << "exec successfully";
    }
    else {
        qDebug() << "already has a database";
    }


    //登录注册界面
    LoginScene login;
    login.show();


    //欢迎界面在程序加载完毕后消失
    splash->finish(&login);
    delete splash;

    return a.exec();
}

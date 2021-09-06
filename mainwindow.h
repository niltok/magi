#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace magiUI {
    using namespace magi;
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;

        // QObject interface
    public:
        bool eventFilter(QObject *watched, QEvent *event);

        // QObject interface
    protected:
        void timerEvent(QTimerEvent *event);

        // QWidget interface
    protected:
        void keyPressEvent(QKeyEvent *event);
    private slots:
        void on_startGameButton_clicked();

        // QWidget interface
        void on_againButton_clicked();

        void on_backButton_clicked();

    protected:
        void keyReleaseEvent(QKeyEvent *event);

        // QWidget interface
    protected:
        void resizeEvent(QResizeEvent *event);
    };
}
#endif // MAINWINDOW_H

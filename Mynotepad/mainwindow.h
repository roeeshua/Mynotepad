#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSettings>
#include <QMainWindow>
#include <QLabel>
#include "codeeditor.h"
#include "searchdialog.h"
#include "replacedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hyperlinkActivated(const QUrl &url);

    void on_actionAbout_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actCut_triggered();

    void on_actionCopy_triggered();

    void on_actionUndo_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionFontColor_triggered();

    void on_actionEditorBackground_triggered();

    void on_actionFontBackground_triggered();

    void on_actionUneWrap_triggered();

    void on_actionFont_triggered();

    void on_actionShowToolbar_triggered();

    void on_actionShowstatusbar_triggered();

    void on_actionSelectAll_triggered();

    void on_actionExit_triggered();

    void on_actionShowLineNumber_triggered(bool checked);

    void on_tabCloseRequested(int index);

    void on_TextChanged();

    void updatePasteAction();

    void on_actionAddBookmark_triggered();
    void on_actionRemoveBookmark_triggered();
    void on_actionViewBookmarks_triggered();
    void on_actionGotoBookmark_triggered();

    void on_actionAddFavorite_triggered();
    void on_actionRemoveFavorite_triggered();
    void on_actionOpenFavorite_triggered();
    void on_actionViewFavorites_triggered();

private:

    QSettings settings;
    QMap<QString, QString> favorites; // 用于临时存储收藏夹
    void loadFavorites(); // 加载收藏夹
    void saveFavorites(); // 保存收藏夹

    Ui::MainWindow *ui;
    QTabWidget *tabWidget; // 多标签页容器
    QString filePath;
    QLabel statusCursorLabel;
    QLabel statusLabel;
    bool textchanged;
    bool isDarkTheme; // 添加一个成员变量来跟踪主题状态

    bool userEditConfirmed();
    CodeEditor* currentEditor();
    void updateEditorActions(); // 更新按钮状态
    void switchTheme(); // 添加一个函数来切换主题
};
#endif // MAINWINDOW_H

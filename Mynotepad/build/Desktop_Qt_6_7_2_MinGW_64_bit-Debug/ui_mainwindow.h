/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actCut;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionUndo;
    QAction *actionOpen;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionFont;
    QAction *actionUneWrap;
    QAction *actionShowToolbar;
    QAction *actionShowstatusbar;
    QAction *actionRedo;
    QAction *actionSelectAll;
    QAction *actionAbout;
    QAction *actionShowLineNumber;
    QAction *actionFontColor;
    QAction *actionEditorBackground;
    QAction *actionFontBackground;
    QAction *actionToggleTheme;
    QAction *actionAddBookmark;
    QAction *actionRemoveBookmark;
    QAction *actionViewBookmarks;
    QAction *actionGotoBookmark;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_V;
    QMenu *menu_H;
    QMenu *menuBookmarks;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::DocumentNew)) {
            icon = QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew);
        } else {
            icon.addFile(QString::fromUtf8(":/img/new2.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
            icon.addFile(QString::fromUtf8(":/img/120.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        }
        actionNew->setIcon(icon);
        actionNew->setMenuRole(QAction::MenuRole::TextHeuristicRole);
        actCut = new QAction(MainWindow);
        actCut->setObjectName("actCut");
        QIcon icon1;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::EditCut)) {
            icon1 = QIcon::fromTheme(QIcon::ThemeIcon::EditCut);
        } else {
            icon1.addFile(QString::fromUtf8(":/img/cut.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        actCut->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon2;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::SystemLogOut)) {
            icon2 = QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut);
        } else {
            icon2.addFile(QString::fromUtf8(":/img/Exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        actionExit->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon3;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::DocumentSave)) {
            icon3 = QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave);
        } else {
            icon3.addFile(QString::fromUtf8(":/img/Save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        actionSave->setIcon(icon3);
        actionSave->setMenuRole(QAction::MenuRole::TextHeuristicRole);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        QIcon icon4;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::DocumentSaveAs)) {
            icon4 = QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs);
        } else {
            icon4.addFile(QString::fromUtf8(":/img/Saveas.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        actionSaveAs->setIcon(icon4);
        actionSaveAs->setMenuRole(QAction::MenuRole::TextHeuristicRole);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionUndo->setIcon(icon5);
        actionUndo->setMenuRole(QAction::MenuRole::NoRole);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpen->setIcon(icon6);
        actionOpen->setMenuRole(QAction::MenuRole::NoRole);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        actionCopy->setIcon(icon7);
        actionCopy->setMenuRole(QAction::MenuRole::TextHeuristicRole);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        actionPaste->setIcon(icon8);
        actionPaste->setMenuRole(QAction::MenuRole::NoRole);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        actionFind->setIcon(icon9);
        actionFind->setMenuRole(QAction::MenuRole::NoRole);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName("actionReplace");
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaylistRepeat));
        actionReplace->setIcon(icon10);
        actionReplace->setMenuRole(QAction::MenuRole::NoRole);
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        QIcon icon11(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextItalic));
        actionFont->setIcon(icon11);
        actionFont->setMenuRole(QAction::MenuRole::NoRole);
        actionUneWrap = new QAction(MainWindow);
        actionUneWrap->setObjectName("actionUneWrap");
        actionUneWrap->setCheckable(true);
        QIcon icon12(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyCenter));
        actionUneWrap->setIcon(icon12);
        actionUneWrap->setMenuRole(QAction::MenuRole::NoRole);
        actionShowToolbar = new QAction(MainWindow);
        actionShowToolbar->setObjectName("actionShowToolbar");
        actionShowToolbar->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/IcOutlineHandyman.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionShowToolbar->setIcon(icon13);
        actionShowToolbar->setMenuRole(QAction::MenuRole::NoRole);
        actionShowstatusbar = new QAction(MainWindow);
        actionShowstatusbar->setObjectName("actionShowstatusbar");
        actionShowstatusbar->setCheckable(true);
        QIcon icon14(QIcon::fromTheme(QIcon::ThemeIcon::DriveHarddisk));
        actionShowstatusbar->setIcon(icon14);
        actionShowstatusbar->setMenuRole(QAction::MenuRole::NoRole);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon15(QIcon::fromTheme(QIcon::ThemeIcon::EditRedo));
        actionRedo->setIcon(icon15);
        actionRedo->setMenuRole(QAction::MenuRole::NoRole);
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName("actionSelectAll");
        QIcon icon16(QIcon::fromTheme(QIcon::ThemeIcon::EditSelectAll));
        actionSelectAll->setIcon(icon16);
        actionSelectAll->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon17(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon17);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionShowLineNumber = new QAction(MainWindow);
        actionShowLineNumber->setObjectName("actionShowLineNumber");
        actionShowLineNumber->setCheckable(true);
        QIcon icon18(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove));
        actionShowLineNumber->setIcon(icon18);
        actionShowLineNumber->setMenuRole(QAction::MenuRole::NoRole);
        actionFontColor = new QAction(MainWindow);
        actionFontColor->setObjectName("actionFontColor");
        actionFontColor->setMenuRole(QAction::MenuRole::NoRole);
        actionEditorBackground = new QAction(MainWindow);
        actionEditorBackground->setObjectName("actionEditorBackground");
        actionEditorBackground->setMenuRole(QAction::MenuRole::NoRole);
        actionFontBackground = new QAction(MainWindow);
        actionFontBackground->setObjectName("actionFontBackground");
        actionFontBackground->setMenuRole(QAction::MenuRole::NoRole);
        actionToggleTheme = new QAction(MainWindow);
        actionToggleTheme->setObjectName("actionToggleTheme");
        QIcon icon19(QIcon::fromTheme(QIcon::ThemeIcon::MediaRecord));
        actionToggleTheme->setIcon(icon19);
        actionToggleTheme->setMenuRole(QAction::MenuRole::NoRole);
        actionAddBookmark = new QAction(MainWindow);
        actionAddBookmark->setObjectName("actionAddBookmark");
        actionAddBookmark->setMenuRole(QAction::MenuRole::NoRole);
        actionRemoveBookmark = new QAction(MainWindow);
        actionRemoveBookmark->setObjectName("actionRemoveBookmark");
        actionRemoveBookmark->setMenuRole(QAction::MenuRole::NoRole);
        actionViewBookmarks = new QAction(MainWindow);
        actionViewBookmarks->setObjectName("actionViewBookmarks");
        actionViewBookmarks->setMenuRole(QAction::MenuRole::NoRole);
        actionGotoBookmark = new QAction(MainWindow);
        actionGotoBookmark->setObjectName("actionGotoBookmark");
        actionGotoBookmark->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 800, 600));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        menu_E = new QMenu(menubar);
        menu_E->setObjectName("menu_E");
        menu_O = new QMenu(menubar);
        menu_O->setObjectName("menu_O");
        menu_V = new QMenu(menubar);
        menu_V->setObjectName("menu_V");
        menu_H = new QMenu(menubar);
        menu_H->setObjectName("menu_H");
        menuBookmarks = new QMenu(menubar);
        menuBookmarks->setObjectName("menuBookmarks");
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_V->menuAction());
        menubar->addAction(menu_H->menuAction());
        menubar->addAction(menuBookmarks->menuAction());
        menu_F->addAction(actionNew);
        menu_F->addAction(actionOpen);
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveAs);
        menu_F->addAction(actionExit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionRedo);
        menu_E->addAction(actCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_O->addAction(actionShowLineNumber);
        menu_O->addAction(actionUneWrap);
        menu_O->addSeparator();
        menu_O->addAction(actionFont);
        menu_O->addAction(actionFontColor);
        menu_O->addSeparator();
        menu_O->addAction(actionFontBackground);
        menu_O->addAction(actionEditorBackground);
        menu_V->addAction(actionShowToolbar);
        menu_V->addAction(actionShowstatusbar);
        menu_V->addAction(actionFind);
        menu_V->addAction(actionReplace);
        menu_H->addAction(actionAbout);
        menuBookmarks->addAction(actionAddBookmark);
        menuBookmarks->addAction(actionRemoveBookmark);
        menuBookmarks->addAction(actionViewBookmarks);
        menuBookmarks->addAction(actionGotoBookmark);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSaveAs);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addAction(actCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionFind);
        toolBar->addAction(actionReplace);
        toolBar->addSeparator();
        toolBar->addAction(actionFont);
        toolBar->addAction(actionShowLineNumber);
        toolBar->addAction(actionUneWrap);
        toolBar->addSeparator();
        toolBar->addAction(actionShowToolbar);
        toolBar->addAction(actionShowstatusbar);
        toolBar->addAction(actionToggleTheme);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(X)", nullptr));
#if QT_CONFIG(tooltip)
        actCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(X)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(tooltip)
        actionSaveAs->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200(Z)", nullptr));
#if QT_CONFIG(tooltip)
        actionUndo->setToolTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200(Z)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", nullptr));
#if QT_CONFIG(tooltip)
        actionCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(V)", nullptr));
#if QT_CONFIG(tooltip)
        actionPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(V)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276(F)", nullptr));
#if QT_CONFIG(tooltip)
        actionFind->setToolTip(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276(F)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242(H)", nullptr));
#if QT_CONFIG(tooltip)
        actionReplace->setToolTip(QCoreApplication::translate("MainWindow", "\346\233\277\346\215\242(H)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFont->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actionFont->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actionUneWrap->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actionUneWrap->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShowToolbar->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#if QT_CONFIG(tooltip)
        actionShowToolbar->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShowstatusbar->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
#if QT_CONFIG(tooltip)
        actionShowstatusbar->setToolTip(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232(shift+Z)", nullptr));
#if QT_CONFIG(tooltip)
        actionRedo->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232(shift+Z)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelectAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211(A)", nullptr));
#if QT_CONFIG(tooltip)
        actionSelectAll->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211(A)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShowLineNumber->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267", nullptr));
#if QT_CONFIG(tooltip)
        actionShowLineNumber->setToolTip(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFontColor->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionFontColor->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEditorBackground->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionEditorBackground->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFontBackground->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#if QT_CONFIG(tooltip)
        actionFontBackground->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        actionToggleTheme->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\346\267\261\346\265\205\350\211\262\346\250\241\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        actionToggleTheme->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\344\270\272\346\267\261/\346\265\205\350\211\262\346\250\241\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAddBookmark->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\271\246\347\255\276", nullptr));
        actionRemoveBookmark->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\344\271\246\347\255\276", nullptr));
        actionViewBookmarks->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\344\271\246\347\255\276", nullptr));
        actionGotoBookmark->setText(QCoreApplication::translate("MainWindow", "\350\267\263\350\275\254\344\271\246\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        actionGotoBookmark->setToolTip(QCoreApplication::translate("MainWindow", "\350\267\263\350\275\254\345\210\260\346\214\207\345\256\232\344\271\246\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", nullptr));
        menu_V->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        menuBookmarks->setTitle(QCoreApplication::translate("MainWindow", "\344\271\246\347\255\276(&B)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

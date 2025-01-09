#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "searchdialog.h"
#include "replacedialog.h"
#include "QFileDialog.h"
#include "QColorDialog.h"
#include <QMessageBox>
#include <QTextStream>
#include "QFontDialog.h"
#include <QClipboard>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QInputDialog>
#include "bookmarkdialog.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,isDarkTheme(false) // 初始化为浅色模式
{
    ui->setupUi(this);

    // 连接主题切换信号
    connect(ui->actionToggleTheme, &QAction::triggered, this, &MainWindow::switchTheme);

    QClipboard *clipboard = QApplication::clipboard();
    connect(clipboard, &QClipboard::dataChanged, this, &MainWindow::updatePasteAction);
    tabWidget = new QTabWidget(this);

    connect(tabWidget, &QTabWidget::currentChanged, this, &MainWindow::updateEditorActions);
    setCentralWidget(tabWidget);
    tabWidget->setTabsClosable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::on_tabCloseRequested);

    textchanged = false;
    on_actionNew_triggered();

    statusLabel.setMaximumWidth(180);
    statusLabel.setText("length:"+QString::number(0)+"   lines:"+QString::number(1));
    ui->statusBar->addPermanentWidget(&statusLabel);

    statusCursorLabel.setMaximumWidth(180);
    statusCursorLabel.setText("Ln:"+QString::number(0)+"   Col:"+QString::number(1));
    ui->statusBar->addPermanentWidget(&statusCursorLabel);

    QLabel *auther=new QLabel(ui->statusBar);
    auther->setText("黄展鸿");
    ui->statusBar->addPermanentWidget(auther);

    ui->actionCopy->setEnabled(false);
    ui->actCut->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionPaste->setEnabled(false);

    QPlainTextEdit::LineWrapMode mode=currentEditor()->lineWrapMode();

    ui->actionUneWrap->setChecked(true);

    ui->actionShowToolbar->setChecked(true);
    ui->actionShowstatusbar->setChecked(true);

    ui->actionShowLineNumber->setChecked(false);
    on_actionShowLineNumber_triggered(false);

    // 获取当前的 CodeEditor 实例
    CodeEditor *editor = qobject_cast<CodeEditor*>(tabWidget->currentWidget());
    if (editor) {
        connect(editor, &CodeEditor::hyperlinkActivated, this, &MainWindow::on_hyperlinkActivated);
        qDebug() << "Connected hyperlinkActivated signal to slot";
    }

    loadFavorites(); // 加载收藏夹
    qDebug() << "Favorites loaded:" << favorites;
}

MainWindow::~MainWindow()
{
    saveFavorites(); // 保存收藏夹
    delete ui;
}

void MainWindow::loadFavorites()
{
    settings.beginGroup("Favorites");
    QStringList keys = settings.childKeys();
    for (const QString &key : keys) {
        favorites[key] = settings.value(key).toString();
    }
    settings.endGroup();
}

void MainWindow::saveFavorites()
{
    settings.beginGroup("Favorites");
    settings.remove(""); // 清除所有旧的收藏夹
    for (const QString &key : favorites.keys()) {
        settings.setValue(key, favorites[key]);
        settings.sync();
    }
    qDebug() << "Favorites saved:" << favorites;
}

void MainWindow::on_actionAddFavorite_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "选择文件", "", "All Files (*)");
    if (!path.isEmpty()) {
        QFileInfo fileInfo(path);
        QString fileName = fileInfo.fileName();
        favorites[fileName] = path;
        saveFavorites();
        QMessageBox::information(this, "收藏夹", "文件已添加到收藏夹！");
    }
}

void MainWindow::on_actionRemoveFavorite_triggered()
{
    if (favorites.isEmpty()) {
        QMessageBox::information(this, "收藏夹", "收藏夹为空！");
        return;
    }

    QStringList favoriteNames = favorites.keys();
    bool ok;
    QString selectedFile = QInputDialog::getItem(this, "删除收藏夹", "选择要删除的文件", favoriteNames, 0, false, &ok);
    if (ok && !selectedFile.isEmpty()) {
        favorites.remove(selectedFile);
        saveFavorites();
        QMessageBox::information(this, "收藏夹", "文件已从收藏夹中删除！");
    }
}

void MainWindow::on_actionOpenFavorite_triggered()
{
    if (favorites.isEmpty()) {
        QMessageBox::information(this, "收藏夹", "收藏夹为空！");
        return;
    }

    QStringList favoriteNames = favorites.keys();
    bool ok;
    QString selectedFile = QInputDialog::getItem(this, "打开收藏夹", "选择要打开的文件", favoriteNames, 0, false, &ok);
    if (ok && !selectedFile.isEmpty()) {
        QString path = favorites[selectedFile];
        QFile file(path);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            CodeEditor *editor = new CodeEditor(this);
            editor->setPlainText(file.readAll());
            tabWidget->addTab(editor, selectedFile);
            tabWidget->setCurrentWidget(editor);
            file.close();
        } else {
            QMessageBox::warning(this, "错误", "无法打开文件！");
        }
    }
}

void MainWindow::on_actionViewFavorites_triggered()
{
    if (favorites.isEmpty()) {
        QMessageBox::information(this, "收藏夹", "收藏夹为空！");
        return;
    }

    QStringList favoriteList;
    for (const QString &key : favorites.keys()) {
        favoriteList.append(key + ": " + favorites[key]);
    }
    QString list = favoriteList.join("\n");
    QMessageBox::information(this, "收藏夹列表", list);
}

void MainWindow::on_actionAddBookmark_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        bool ok;
        QString name = QInputDialog::getText(this, "添加书签", "书签名称:", QLineEdit::Normal, "", &ok);
        if (ok && !name.isEmpty()) {
            int lineNumber = editor->textCursor().blockNumber();
            editor->addBookmark(name, lineNumber);
            QMessageBox::information(this, "书签", "书签添加成功！");
        }
    }
}

void MainWindow::on_actionRemoveBookmark_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        bool ok;
        QString name = QInputDialog::getText(this, "删除书签", "书签名称:", QLineEdit::Normal, "", &ok);
        if (ok && !name.isEmpty()) {
            editor->removeBookmark(name);
            QMessageBox::information(this, "书签", "书签删除成功！");
        }
    }
}

void MainWindow::on_actionGotoBookmark_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        QMap<QString, int> bookmarks = editor->getBookmarks();
        if (!bookmarks.isEmpty()) {
            BookmarkDialog dialog(bookmarks, this);
            if (dialog.exec() == QDialog::Accepted) {
                int lineNumber = dialog.selectedLineNumber();
                QTextCursor cursor = editor->textCursor();
                cursor.movePosition(QTextCursor::Start);
                cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, lineNumber);
                editor->setTextCursor(cursor);
                QMessageBox::information(this, "书签", "已跳转到书签位置！");
            }
        } else {
            QMessageBox::information(this, "书签", "没有书签可用。");
        }
    }
}

void MainWindow::on_actionViewBookmarks_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        QMap<QString, int> bookmarks = editor->getBookmarks();
        QString list;
        for (auto it = bookmarks.begin(); it != bookmarks.end(); ++it) {
            list += QString("%1: 第 %2 行\n").arg(it.key()).arg(it.value() + 1);
        }
        QMessageBox::information(this, "书签列表", list.isEmpty() ? "没有书签" : list);
    }
}

void MainWindow::on_hyperlinkActivated(const QUrl &url)
{
    qDebug() << "Hyperlink activated:" << url.toString();
    QDesktopServices::openUrl(url);
}

void MainWindow::switchTheme(){
    QFile file;
    if (isDarkTheme) {
        file.setFileName("F:/QT/Mynotepad/style/light.qss");
        isDarkTheme = false;
    } else {
        file.setFileName("F:/QT/Mynotepad/style/dark.qss");
        isDarkTheme = true;
    }

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "主题切换失败", "无法加载样式表");
        return;
    }

    QTextStream ts(&file);
    QString styleSheet = ts.readAll();
    qApp->setStyleSheet(styleSheet);
    file.close();
}

void MainWindow::updateEditorActions()
{
    CodeEditor *editor = currentEditor();
    bool hasEditor = (editor != nullptr);

    ui->actionCopy->setEnabled(hasEditor);
    ui->actCut->setEnabled(hasEditor);
    ui->actionPaste->setEnabled(hasEditor);
    ui->actionRedo->setEnabled(hasEditor);
    ui->actionUndo->setEnabled(hasEditor);

    if (editor) {
        connect(editor, &QPlainTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);
        connect(editor, &QPlainTextEdit::copyAvailable, ui->actCut, &QAction::setEnabled);
        connect(editor, &QPlainTextEdit::textChanged, this, &MainWindow::on_TextChanged);
        connect(editor, &QPlainTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);
        connect(editor, &QPlainTextEdit::redoAvailable, ui->actionRedo, &QAction::setEnabled);
    }
}

void MainWindow::on_TextChanged()
{
    // 根据当前的编辑器更新窗口标题，添加“修改中”标识
    QString currentTitle = windowTitle();
    if (!currentTitle.startsWith("*修改中 -")) {
        setWindowTitle("*修改中 - " + currentTitle);
    }
    textchanged = true;
}

void MainWindow::updatePasteAction()
{
    QClipboard *clipboard = QApplication::clipboard();
    ui->actionPaste->setEnabled(!clipboard->text().isEmpty());
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg;
    dlg.exec();
}


void MainWindow::on_actionFind_triggered()
{
    CodeEditor *editor = currentEditor();
    if (!editor) {
        QMessageBox::warning(this, "错误", "当前没有可用的编辑器");
        return;
    }

    SearchDialog dlg(this, editor);
    dlg.exec();
}


void MainWindow::on_actionReplace_triggered()
{
    CodeEditor *editor = currentEditor();
    if (!editor) {
        QMessageBox::warning(this, "错误", "当前没有可用的编辑器");
        return;
    }

    ReplaceDialog dlg(this, editor);
    dlg.exec();
}


void MainWindow::on_actionNew_triggered()
{
    CodeEditor *editor = new CodeEditor(this);
    int index = tabWidget->addTab(editor, "未命名文件");
    tabWidget->setCurrentIndex(index);
}

CodeEditor* MainWindow::currentEditor()
{
    return qobject_cast<CodeEditor*>(tabWidget->currentWidget());
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "打开文件", ".", "All Files (*)");
    if (filename.isEmpty())
        return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }

    filePath=filename;
    QString fileType = QFileInfo(filename).suffix().toLower(); // 获取文件扩展名
    CodeEditor *editor = new CodeEditor(this, fileType); // 根据文件类型创建编辑器
    editor->setPlainText(file.readAll());
    int index = tabWidget->addTab(editor, QFileInfo(filename).fileName());
    tabWidget->setCurrentIndex(index);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    CodeEditor *editor = currentEditor();
    if (!editor) {
        return;
    }

    if (filePath.isEmpty()) {
        // 如果没有打开的文件，调用另存为
        on_actionSaveAs_triggered();
    } else {
        // 直接保存到当前文件
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "错误", "无法保存文件");
            return;
        }
        QTextStream out(&file);
        out << editor->toPlainText();
        file.close();

        // 更新窗口标题，去掉“修改中”标识
        setWindowTitle(QFileInfo(filePath).fileName());
        textchanged = false; // 标记文件已保存
    }
}

void MainWindow::on_tabCloseRequested(int index)
{
    QWidget *widget = tabWidget->widget(index);
    tabWidget->removeTab(index);
    widget->deleteLater();
}


void MainWindow::on_actionSaveAs_triggered()
{
    CodeEditor *editor = currentEditor();
    if (!editor) {
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this, "保存文件", ".", tr("Text files (*.txt)"));
    if (filename.isEmpty()) {
        return;
    }

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法保存文件");
        return;
    }
    QTextStream out(&file);
    out << editor->toPlainText();
    file.close();

    // 更新文件路径和窗口标题
    filePath = filename;
    setWindowTitle(QFileInfo(filePath).fileName());
    textchanged = false; // 标记文件已保存
}

bool MainWindow::userEditConfirmed()
{
    if(textchanged){

        QString path = (filePath!="")?filePath:"无标题.txt";
        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle("...");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(QString("是否将更改保存到\n")+"\""+path+"\"?");
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        int r = msg.exec();
        switch(r){
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        case QMessageBox::No:
            textchanged=false;
            break;
        case QMessageBox::Cancel:
            return false;
        }
    }
    return true;
}

void MainWindow::on_actionUndo_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        editor->undo();
    }
}

void MainWindow::on_actCut_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        editor->cut();
    }
}


void MainWindow::on_actionCopy_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        editor->copy();
    }
}

void MainWindow::on_actionPaste_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        editor->paste();
    }
}


void MainWindow::on_actionRedo_triggered()
{
    CodeEditor *editor = currentEditor();
    if (editor) {
        editor->redo();
    }
}

void MainWindow::on_actionFontColor_triggered()
{
    QColor fcolor =QColorDialog::getColor(Qt::black,this,"设置字体颜色");
    if(fcolor.isValid()){
        currentEditor()->setStyleSheet(QString("QPlainTextEdit {color: %1}").arg(fcolor.name()));
    }
}


void MainWindow::on_actionEditorBackground_triggered()
{
    QColor bcolor =QColorDialog::getColor(Qt::black,this,"设置背景颜色");
    if(bcolor.isValid()){
        currentEditor()->setStyleSheet(QString("QPlainTextEdit {background-color: %1}").arg(bcolor.name()));
    }
}

void MainWindow::on_actionUneWrap_triggered()
{
    QPlainTextEdit::LineWrapMode mode=currentEditor()->lineWrapMode();

    if(mode==QPlainTextEdit::NoWrap){
        currentEditor()->setLineWrapMode(QPlainTextEdit::WidgetWidth);

        ui->actionUneWrap->setChecked(true);
    }else{
        currentEditor()->setLineWrapMode(QPlainTextEdit::NoWrap);

        ui->actionUneWrap->setChecked(false);
    }
}


void MainWindow::on_actionFont_triggered()
{
    bool ok=false;
    QFont font=QFontDialog::getFont(&ok,this);

    if(ok){
        currentEditor()->setFont(font);
    }
}


void MainWindow::on_actionShowToolbar_triggered()
{
    bool visible = ui->toolBar->isVisible();
    ui->toolBar->setVisible(!visible);
    ui->actionShowToolbar->setChecked(!visible);
}


void MainWindow::on_actionShowstatusbar_triggered()
{
    bool visible = ui->statusBar->isVisible();
    ui->statusBar->setVisible(!visible);
    ui->actionShowstatusbar->setChecked(!visible);
}


void MainWindow::on_actionSelectAll_triggered()
{
    currentEditor()->selectAll();
}


void MainWindow::on_actionExit_triggered()
{
    if(userEditConfirmed())
        exit(0);
}


void MainWindow::on_actionFontBackground_triggered()
{

}

void MainWindow::on_actionShowLineNumber_triggered(bool checked)
{
    currentEditor()->HLNA(!checked);
}


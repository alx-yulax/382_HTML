#include <QtGui/QtGui>

#include <QApplication>

#include <QWebEngineView>
#include <QHBoxLayout>
#include <QPlainTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWindow;

    QString text = "<!DOCTYPE html><html><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>";

    auto *hbox = new QHBoxLayout(&mainWindow);
    auto *textEdit = new QPlainTextEdit(text,&mainWindow);
    auto *webView = new QWebEngineView(&mainWindow);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);

    sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
    textEdit->setSizePolicy(sizePolicy);

    sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
    webView->setSizePolicy(sizePolicy);

    hbox->addWidget(textEdit);
    hbox->addWidget(webView);

    webView->setHtml(textEdit->toPlainText());

    QObject::connect(textEdit,&QPlainTextEdit::textChanged,[textEdit, webView]
    {
        webView->setHtml(textEdit->toPlainText());
    });

    mainWindow.show();

    return a.exec();
}

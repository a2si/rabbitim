#ifndef FRMMESSAGE_H
#define FRMMESSAGE_H

#include <QFrame>
#include <QStandardItemModel>
#include "qxmpp/QXmppUtils.h"
#include "qxmpp/QXmppPresence.h"
#include "../../Global.h"

extern CGlobal g_Global;

class MainWindow;
class CRoster;

namespace Ui {
class CFrmMessage;
}

class CFrmMessage : public QFrame
{
    Q_OBJECT

public:
    explicit CFrmMessage(QWidget *parent = 0);
    ~CFrmMessage();

    //注意：只在对话框初始化后调用一次,必须最先调用一次
    int SetRoster(CRoster* pRoster, MainWindow* pMainWindow);
    int AppendMessage(const QString &szMessage);
    int AppendMessageToList(const QString &szMessage, const QString &name = g_Global.GetName(), bool bRemote = false);

protected:
    virtual void hideEvent(QHideEvent *);
    virtual void showEvent(QShowEvent* );
    void closeEvent(QCloseEvent *e);

private slots:
    void on_pbBack_clicked();

    void on_pbSend_clicked();

    void on_tbMore_clicked();

    void on_pbVideo_clicked();

    void ChangedPresence(QXmppPresence::Status::Type status);

private:
    Ui::CFrmMessage *ui;

    CRoster *m_pRoster;
    MainWindow* m_pMainWindow;

    QStandardItemModel *m_pModel;
    QStringList m_szMessages;
};

#endif // FRMMESSAGE_H
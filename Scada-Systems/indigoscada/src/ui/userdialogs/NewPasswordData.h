/**********************************************************************
--- Qt Architect generated file ---
File: NewPasswordData.h
Last generated: Fri Feb 16 15:11:34 2001
DO NOT EDIT!!!  This file will be automatically
regenerated by qtarch.  All changes will be lost.
*********************************************************************/
#ifndef NewPasswordData_included
#define NewPasswordData_included
#include <qt.h>
class NewPasswordData : public QDialog
{
	Q_OBJECT
	public:
	NewPasswordData(QWidget *parent = NULL, const char *name = NULL);
	virtual ~NewPasswordData();
	protected slots:
	virtual void OkClicked() =0;
	public:
	QLineEdit *Password1;
	QLineEdit *Password2;
	QPushButton *OkButton;
};
#endif // NewPasswordData_included


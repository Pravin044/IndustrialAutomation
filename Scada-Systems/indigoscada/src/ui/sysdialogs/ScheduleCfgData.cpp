/**********************************************************************
--- Qt Architect generated file ---
File: ScheduleCfgData.cpp
Last generated: Thu Jan 4 16:01:05 2001
DO NOT EDIT!!!  This file will be automatically
regenerated by qtarch.  All changes will be lost.
*********************************************************************/
#include <qt.h>
#include "ScheduleCfgData.h"

ScheduleCfgData::ScheduleCfgData(QWidget *parent, const char *name)
: QDialog(parent, name, TRUE, 208)
{
	QFrame *qtarch_Frame_9 = new QFrame(this, "Frame_9");
	qtarch_Frame_9->setGeometry(10, 20, 850, 400);
	qtarch_Frame_9->setMinimumSize(0, 0);
	qtarch_Frame_9->setMaximumSize(32767, 32767);
	qtarch_Frame_9->setFocusPolicy(QWidget::NoFocus);
	qtarch_Frame_9->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Frame_9->setFontPropagation(QWidget::SameFont);
	qtarch_Frame_9->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Frame_9->setFrameStyle( 51 );
	qtarch_Frame_9->setLineWidth( 2 );
	qtarch_Frame_9->setMidLineWidth( 0 );
	qtarch_Frame_9->QFrame::setMargin( 0 );
	QLabel *qtarch_Label_36 = new QLabel(this, "Label_36");
	qtarch_Label_36->setGeometry(50, 40, 100, 30);
	qtarch_Label_36->setMinimumSize(0, 0);
	qtarch_Label_36->setMaximumSize(32767, 32767);
	qtarch_Label_36->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_36->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_36->setFontPropagation(QWidget::SameFont);
	qtarch_Label_36->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_36->setFrameStyle( 0 );
	qtarch_Label_36->setLineWidth( 1 );
	qtarch_Label_36->setMidLineWidth( 0 );
	qtarch_Label_36->QFrame::setMargin( 0 );
	qtarch_Label_36->setText( tr( "Name" ) );
	qtarch_Label_36->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_36->setMargin( 0 );
	Name = new QComboBox(FALSE, this, "ComboBox_15");
	Name->setGeometry(160, 40, 430, 30);
	Name->setMinimumSize(0, 0);
	Name->setMaximumSize(32767, 32767);
	Name->setFocusPolicy(QWidget::StrongFocus);
	Name->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	Name->setFontPropagation(QWidget::SameFont);
	Name->setPalettePropagation(QWidget::SameFont);
	#endif
	Name->setSizeLimit( 10 );
	Name->setAutoResize( FALSE );
	Name->setMaxCount( 2147483647 );
	Name->setAutoCompletion( FALSE );
	connect(Name, SIGNAL(activated(int)), SLOT(SelChanged(int)));
	connect(Name, SIGNAL(highlighted(int)), SLOT(SelChanged(int)));
	QLabel *qtarch_Label_37 = new QLabel(this, "Label_37");
	qtarch_Label_37->setGeometry(50, 90, 100, 30);
	qtarch_Label_37->setMinimumSize(0, 0);
	qtarch_Label_37->setMaximumSize(32767, 32767);
	qtarch_Label_37->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_37->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_37->setFontPropagation(QWidget::SameFont);
	qtarch_Label_37->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_37->setFrameStyle( 0 );
	qtarch_Label_37->setLineWidth( 1 );
	qtarch_Label_37->setMidLineWidth( 0 );
	qtarch_Label_37->QFrame::setMargin( 0 );
	qtarch_Label_37->setText( tr( "Comment" ) );
	qtarch_Label_37->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_37->setMargin( 0 );
	Comment = new QLineEdit(this, "LineEdit_15");
	Comment->setGeometry(160, 90, 430, 30);
	Comment->setMinimumSize(0, 0);
	Comment->setMaximumSize(32767, 32767);
	Comment->setFocusPolicy(QWidget::StrongFocus);
	Comment->setBackgroundMode(QWidget::PaletteBase);
#if QT_VERSION < 300
	Comment->setFontPropagation(QWidget::SameFont);
	Comment->setPalettePropagation(QWidget::SameFont);
	#endif
	Comment->setText(tr(NONE_STR) );
	Comment->setMaxLength( 128 );
	Comment->setFrame( QLineEdit::Normal );
	Comment->setFrame( TRUE );
	Comment->setAlignment( AlignLeft );
	QLabel *qtarch_Label_38 = new QLabel(this, "Label_38");
	qtarch_Label_38->setGeometry(50, 150, 100, 30);
	qtarch_Label_38->setMinimumSize(0, 0);
	qtarch_Label_38->setMaximumSize(32767, 32767);
	qtarch_Label_38->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_38->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_38->setFontPropagation(QWidget::SameFont);
	qtarch_Label_38->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_38->setFrameStyle( 0 );
	qtarch_Label_38->setLineWidth( 1 );
	qtarch_Label_38->setMidLineWidth( 0 );
	qtarch_Label_38->QFrame::setMargin( 0 );
	qtarch_Label_38->setText( tr( "Frequency" ) );
	qtarch_Label_38->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_38->setMargin( 0 );
	FrequencyMode = new QComboBox(FALSE, this, "ComboBox_16");
	FrequencyMode->setGeometry(160, 150, 160, 30);
	FrequencyMode->setMinimumSize(0, 0);
	FrequencyMode->setMaximumSize(32767, 32767);
	FrequencyMode->setFocusPolicy(QWidget::StrongFocus);
	FrequencyMode->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	FrequencyMode->setFontPropagation(QWidget::SameFont);
	FrequencyMode->setPalettePropagation(QWidget::SameFont);
	#endif
	FrequencyMode->setSizeLimit( 10 );
	FrequencyMode->setAutoResize( FALSE );
	FrequencyMode->insertItem( tr( "Every Monday" ) );
	FrequencyMode->insertItem( tr( "Every Tuesday" ) );
	FrequencyMode->insertItem( tr( "Every Wednesday" ) );
	FrequencyMode->insertItem( tr( "Every Thursday" ) );
	FrequencyMode->insertItem( tr( "Every Friday" ) );
	FrequencyMode->insertItem( tr( "Every Saturday" ) );
	FrequencyMode->insertItem( tr( "Every Sunday" ) );
	FrequencyMode->insertItem( tr( "Every Day" ) );
	FrequencyMode->insertItem( tr( "Periodic" ) );
	FrequencyMode->insertItem( tr( "First Monday" ) );
	FrequencyMode->insertItem( tr( "First Tuesday" ) );
	FrequencyMode->insertItem( tr( "First Wednesday" ) );
	FrequencyMode->insertItem( tr( "First Thursday" ) );
	FrequencyMode->insertItem( tr( "First Friday" ) );
	FrequencyMode->insertItem( tr( "First Saturday" ) );
	FrequencyMode->insertItem( tr( "First Sunday" ) );
	FrequencyMode->insertItem( tr( "First Working Day" ) );
	FrequencyMode->insertItem( tr( "Last Monday" ) );
	FrequencyMode->insertItem( tr( "Last Tuesday" ) );
	FrequencyMode->insertItem( tr( "Last Wednesday" ) );
	FrequencyMode->insertItem( tr( "Last Thursday" ) );
	FrequencyMode->insertItem( tr( "Last Friday" ) );
	FrequencyMode->insertItem( tr( "Last Saturday" ) );
	FrequencyMode->insertItem( tr( "Last Sunday" ) );
	FrequencyMode->insertItem( tr( "Last Working Day" ) );
	FrequencyMode->setMaxCount( 30 );
	FrequencyMode->setAutoCompletion( FALSE );
	connect(FrequencyMode, SIGNAL(highlighted(int)), SLOT(FreqChange(int)));
	connect(FrequencyMode, SIGNAL(highlighted(int)), SLOT(FreqChange(int)));
	Time = new TIMEEDIT(this, "User_5");
	Time->setGeometry(360, 150, 100, 30);
	Time->setMinimumSize(0, 0);
	Time->setMaximumSize(32767, 32767);
	Time->setFocusPolicy(QWidget::StrongFocus);
	Time->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	Time->setFontPropagation(QWidget::SameFont);
	Time->setPalettePropagation(QWidget::SameFont);
	#endif
	QLabel *qtarch_Label_39 = new QLabel(this, "Label_39");
	qtarch_Label_39->setGeometry(50, 210, 100, 30);
	qtarch_Label_39->setMinimumSize(0, 0);
	qtarch_Label_39->setMaximumSize(32767, 32767);
	qtarch_Label_39->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_39->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_39->setFontPropagation(QWidget::SameFont);
	qtarch_Label_39->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_39->setFrameStyle( 0 );
	qtarch_Label_39->setLineWidth( 1 );
	qtarch_Label_39->setMidLineWidth( 0 );
	qtarch_Label_39->QFrame::setMargin( 0 );
	qtarch_Label_39->setText( tr( "Trigger Point" ) );
	qtarch_Label_39->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_39->setMargin( 0 );
	SamplePointList = new QComboBox(FALSE, this, "ComboBox_17");
	SamplePointList->setGeometry(160, 210, 300, 30);
	SamplePointList->setMinimumSize(0, 0);
	SamplePointList->setMaximumSize(32767, 32767);
	SamplePointList->setFocusPolicy(QWidget::StrongFocus);
	SamplePointList->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	SamplePointList->setFontPropagation(QWidget::SameFont);
	SamplePointList->setPalettePropagation(QWidget::SameFont);
	#endif
	SamplePointList->setSizeLimit( 10 );
	SamplePointList->setAutoResize( FALSE );
	SamplePointList->insertItem( tr( "(***)" ) );
	SamplePointList->setMaxCount( 2147483647 );
	SamplePointList->setAutoCompletion( FALSE );
	connect(SamplePointList, SIGNAL(activated(int)), SLOT(SpChanged(int)));
	connect(SamplePointList, SIGNAL(highlighted(int)), SLOT(SpChanged(int)));
	RelOp = new QComboBox(FALSE, this, "ComboBox_18");
	RelOp->setGeometry(610, 210, 100, 30);
	RelOp->setMinimumSize(0, 0);
	RelOp->setMaximumSize(32767, 32767);
	RelOp->setFocusPolicy(QWidget::StrongFocus);
	RelOp->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	RelOp->setFontPropagation(QWidget::SameFont);
	RelOp->setPalettePropagation(QWidget::SameFont);
	#endif
	RelOp->setSizeLimit( 10 );
	RelOp->setAutoResize( FALSE );
	RelOp->insertItem( tr( ">" ) );
	RelOp->insertItem( tr( "<" ) );
	RelOp->insertItem( tr( "=" ) );
	RelOp->insertItem( tr( "<>" ) );
	RelOp->setMaxCount( 2147483647 );
	RelOp->setAutoCompletion( FALSE );
	TriggerValue = new QLineEdit(this, "LineEdit_16");
	TriggerValue->setGeometry(720, 210, 100, 30);
	TriggerValue->setMinimumSize(0, 0);
	TriggerValue->setMaximumSize(32767, 32767);
	TriggerValue->setFocusPolicy(QWidget::StrongFocus);
	TriggerValue->setBackgroundMode(QWidget::PaletteBase);
#if QT_VERSION < 300
	TriggerValue->setFontPropagation(QWidget::SameFont);
	TriggerValue->setPalettePropagation(QWidget::SameFont);
	#endif
	TriggerValue->setText( tr( "0" ) );
	TriggerValue->setMaxLength( 8 );
	TriggerValue->setFrame( QLineEdit::Normal );
	TriggerValue->setFrame( TRUE );
	TriggerValue->setAlignment( AlignLeft );
	TagList = new QComboBox(FALSE, this, "ComboBox_19");
	TagList->setGeometry(490, 210, 100, 30);
	TagList->setMinimumSize(0, 0);
	TagList->setMaximumSize(32767, 32767);
	TagList->setFocusPolicy(QWidget::StrongFocus);
	TagList->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	TagList->setFontPropagation(QWidget::SameFont);
	TagList->setPalettePropagation(QWidget::SameFont);
	#endif
	TagList->setSizeLimit( 10 );
	TagList->setAutoResize( FALSE );
	TagList->setMaxCount( 2147483647 );
	TagList->setAutoCompletion( FALSE );
	QLabel *qtarch_Label_40 = new QLabel(this, "Label_40");
	qtarch_Label_40->setGeometry(50, 270, 100, 30);
	qtarch_Label_40->setMinimumSize(0, 0);
	qtarch_Label_40->setMaximumSize(32767, 32767);
	qtarch_Label_40->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_40->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_40->setFontPropagation(QWidget::SameFont);
	qtarch_Label_40->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_40->setFrameStyle( 0 );
	qtarch_Label_40->setLineWidth( 1 );
	qtarch_Label_40->setMidLineWidth( 0 );
	qtarch_Label_40->QFrame::setMargin( 0 );
	qtarch_Label_40->setText( tr( "Report" ) );
	qtarch_Label_40->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_40->setMargin( 0 );
	ReportList = new QComboBox(FALSE, this, "ComboBox_20");
	ReportList->setGeometry(160, 270, 300, 30);
	ReportList->setMinimumSize(0, 0);
	ReportList->setMaximumSize(32767, 32767);
	ReportList->setFocusPolicy(QWidget::StrongFocus);
	ReportList->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	ReportList->setFontPropagation(QWidget::SameFont);
	ReportList->setPalettePropagation(QWidget::SameFont);
	#endif
	ReportList->setSizeLimit( 10 );
	ReportList->setAutoResize( FALSE );
	ReportList->insertItem( tr( "(***)" ) );
	ReportList->setMaxCount( 2147483647 );
	ReportList->setAutoCompletion( FALSE );
	ApplyButton = new QPushButton(this, "PushButton_38");
	ApplyButton->setGeometry(20, 450, 100, 30);
	ApplyButton->setMinimumSize(0, 0);
	ApplyButton->setMaximumSize(32767, 32767);
	ApplyButton->setFocusPolicy(QWidget::TabFocus);
	ApplyButton->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	ApplyButton->setFontPropagation(QWidget::SameFont);
	ApplyButton->setPalettePropagation(QWidget::SameFont);
	#endif
	ApplyButton->setText( tr( "Apply" ) );
	ApplyButton->setAutoRepeat( FALSE );
	ApplyButton->setAutoResize( FALSE );
	ApplyButton->setToggleButton( FALSE );
	ApplyButton->setDefault( FALSE );
	ApplyButton->setAutoDefault( FALSE );
	ApplyButton->setIsMenuButton( FALSE );
	connect(ApplyButton, SIGNAL(clicked()), SLOT(Apply()));
	NewButton = new QPushButton(this, "PushButton_39");
	NewButton->setGeometry(140, 450, 100, 30);
	NewButton->setMinimumSize(0, 0);
	NewButton->setMaximumSize(32767, 32767);
	NewButton->setFocusPolicy(QWidget::TabFocus);
	NewButton->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	NewButton->setFontPropagation(QWidget::SameFont);
	NewButton->setPalettePropagation(QWidget::SameFont);
	#endif
	NewButton->setText( tr( "New..." ) );
	NewButton->setAutoRepeat( FALSE );
	NewButton->setAutoResize( FALSE );
	NewButton->setToggleButton( FALSE );
	NewButton->setDefault( FALSE );
	NewButton->setAutoDefault( FALSE );
	NewButton->setIsMenuButton( FALSE );
	connect(NewButton, SIGNAL(clicked()), SLOT(New()));
	DeleteButton = new QPushButton(this, "PushButton_40");
	DeleteButton->setGeometry(260, 450, 100, 30);
	DeleteButton->setMinimumSize(0, 0);
	DeleteButton->setMaximumSize(32767, 32767);
	DeleteButton->setFocusPolicy(QWidget::TabFocus);
	DeleteButton->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	DeleteButton->setFontPropagation(QWidget::SameFont);
	DeleteButton->setPalettePropagation(QWidget::SameFont);
	#endif
	DeleteButton->setText( tr( "Delete" ) );
	DeleteButton->setAutoRepeat( FALSE );
	DeleteButton->setAutoResize( FALSE );
	DeleteButton->setToggleButton( FALSE );
	DeleteButton->setDefault( FALSE );
	DeleteButton->setAutoDefault( FALSE );
	DeleteButton->setIsMenuButton( FALSE );
	connect(DeleteButton, SIGNAL(clicked()), SLOT(Delete()));
	QPushButton *qtarch_PushButton_41 = new QPushButton(this, "PushButton_41");
	qtarch_PushButton_41->setGeometry(380, 450, 100, 30);
	qtarch_PushButton_41->setMinimumSize(0, 0);
	qtarch_PushButton_41->setMaximumSize(32767, 32767);
	qtarch_PushButton_41->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_41->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	qtarch_PushButton_41->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_41->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_41->setText( tr( "Help" ) );
	qtarch_PushButton_41->setAutoRepeat( FALSE );
	qtarch_PushButton_41->setAutoResize( FALSE );
	qtarch_PushButton_41->setToggleButton( FALSE );
	qtarch_PushButton_41->setDefault( FALSE );
	qtarch_PushButton_41->setAutoDefault( FALSE );
	qtarch_PushButton_41->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_41, SIGNAL(clicked()), SLOT(Help()));
	QPushButton *qtarch_PushButton_42 = new QPushButton(this, "PushButton_42");
	qtarch_PushButton_42->setGeometry(770, 450, 100, 30);
	qtarch_PushButton_42->setMinimumSize(0, 0);
	qtarch_PushButton_42->setMaximumSize(32767, 32767);
	qtarch_PushButton_42->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_42->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	qtarch_PushButton_42->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_42->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_42->setText( tr( "Exit" ) );
	qtarch_PushButton_42->setAutoRepeat( FALSE );
	qtarch_PushButton_42->setAutoResize( FALSE );
	qtarch_PushButton_42->setToggleButton( FALSE );
	qtarch_PushButton_42->setDefault( FALSE );
	qtarch_PushButton_42->setAutoDefault( FALSE );
	qtarch_PushButton_42->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_42, SIGNAL(clicked()), SLOT(reject()));
	PrintReport = new QCheckBox(this, "CheckBox_14");
	PrintReport->setGeometry(490, 270, 110, 30);
	PrintReport->setMinimumSize(0, 0);
	PrintReport->setMaximumSize(32767, 32767);
	PrintReport->setFocusPolicy(QWidget::TabFocus);
	PrintReport->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	PrintReport->setFontPropagation(QWidget::SameFont);
	PrintReport->setPalettePropagation(QWidget::SameFont);
	#endif
	PrintReport->setText( tr( "Print Report" ) );
	PrintReport->setAutoRepeat( FALSE );
	PrintReport->setAutoResize( FALSE );
	PrintReport->setChecked( FALSE );
	QLabel *qtarch_Label_41 = new QLabel(this, "Label_41");
	qtarch_Label_41->setGeometry(50, 320, 100, 30);
	qtarch_Label_41->setMinimumSize(0, 0);
	qtarch_Label_41->setMaximumSize(32767, 32767);
	qtarch_Label_41->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_41->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_41->setFontPropagation(QWidget::SameFont);
	qtarch_Label_41->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_41->setFrameStyle( 0 );
	qtarch_Label_41->setLineWidth( 1 );
	qtarch_Label_41->setMidLineWidth( 0 );
	qtarch_Label_41->QFrame::setMargin( 0 );
	qtarch_Label_41->setText( tr( "Receipe" ) );
	qtarch_Label_41->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_41->setMargin( 0 );
	ReceipeList = new QComboBox(FALSE, this, "ComboBox_21");
	ReceipeList->setGeometry(160, 320, 300, 30);
	ReceipeList->setMinimumSize(0, 0);
	ReceipeList->setMaximumSize(32767, 32767);
	ReceipeList->setFocusPolicy(QWidget::StrongFocus);
	ReceipeList->setBackgroundMode(QWidget::NoBackground);
#if QT_VERSION < 300
	ReceipeList->setFontPropagation(QWidget::SameFont);
	ReceipeList->setPalettePropagation(QWidget::SameFont);
	#endif
	ReceipeList->setSizeLimit( 10 );
	ReceipeList->setAutoResize( FALSE );
	ReceipeList->insertItem( tr(NONE_STR) );
	ReceipeList->setMaxCount( 2147483647 );
	ReceipeList->setAutoCompletion( FALSE );
	EditReportButton = new QPushButton(this, "PushButton_43");
	EditReportButton->setGeometry(610, 270, 100, 30);
	EditReportButton->setMinimumSize(0, 0);
	EditReportButton->setMaximumSize(32767, 32767);
	EditReportButton->setFocusPolicy(QWidget::TabFocus);
	EditReportButton->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	EditReportButton->setFontPropagation(QWidget::SameFont);
	EditReportButton->setPalettePropagation(QWidget::SameFont);
	#endif
	EditReportButton->setText( tr( "Edit Report..." ) );
	EditReportButton->setAutoRepeat( FALSE );
	EditReportButton->setAutoResize( FALSE );
	EditReportButton->setToggleButton( FALSE );
	EditReportButton->setDefault( FALSE );
	EditReportButton->setAutoDefault( FALSE );
	EditReportButton->setIsMenuButton( FALSE );
	connect(EditReportButton, SIGNAL(clicked()), SLOT(EditReport()));
	EditReceipeButton = new QPushButton(this, "PushButton_44");
	EditReceipeButton->setGeometry(610, 320, 100, 30);
	EditReceipeButton->setMinimumSize(0, 0);
	EditReceipeButton->setMaximumSize(32767, 32767);
	EditReceipeButton->setFocusPolicy(QWidget::TabFocus);
	EditReceipeButton->setBackgroundMode(QWidget::PaletteButton);
#if QT_VERSION < 300
	EditReceipeButton->setFontPropagation(QWidget::SameFont);
	EditReceipeButton->setPalettePropagation(QWidget::SameFont);
	#endif
	EditReceipeButton->setText( tr( "Edit Receipe..." ) );
	EditReceipeButton->setAutoRepeat( FALSE );
	EditReceipeButton->setAutoResize( FALSE );
	EditReceipeButton->setToggleButton( FALSE );
	EditReceipeButton->setDefault( FALSE );
	EditReceipeButton->setAutoDefault( FALSE );
	EditReceipeButton->setIsMenuButton( FALSE );
	connect(EditReceipeButton, SIGNAL(clicked()), SLOT(EditReceipe()));
	Action = new QLineEdit(this, "LineEdit_17");
	Action->setGeometry(160, 370, 550, 30);
	Action->setMinimumSize(0, 0);
	Action->setMaximumSize(32767, 32767);
	Action->setFocusPolicy(QWidget::StrongFocus);
	Action->setBackgroundMode(QWidget::PaletteBase);
#if QT_VERSION < 300
	Action->setFontPropagation(QWidget::SameFont);
	Action->setPalettePropagation(QWidget::SameFont);
	#endif
	Action->setText( "" );
	Action->setMaxLength( 32767 );
	Action->setFrame( QLineEdit::Normal );
	Action->setFrame( TRUE );
	Action->setAlignment( AlignLeft );
	QLabel *qtarch_Label_42 = new QLabel(this, "Label_42");
	qtarch_Label_42->setGeometry(50, 370, 100, 30);
	qtarch_Label_42->setMinimumSize(0, 0);
	qtarch_Label_42->setMaximumSize(32767, 32767);
	qtarch_Label_42->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_42->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	qtarch_Label_42->setFontPropagation(QWidget::SameFont);
	qtarch_Label_42->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_42->setFrameStyle( 0 );
	qtarch_Label_42->setLineWidth( 1 );
	qtarch_Label_42->setMidLineWidth( 0 );
	qtarch_Label_42->QFrame::setMargin( 0 );
	qtarch_Label_42->setText( tr( "Action" ) );
	qtarch_Label_42->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_42->setMargin( 0 );
	resize(890,490);
	setMinimumSize(0, 0);
	setMaximumSize(32767, 32767);
}
ScheduleCfgData::~ScheduleCfgData()
{
}


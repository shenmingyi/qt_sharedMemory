/*
���ߣ������ https://blog.csdn.net/ly305750665
���ܣ�Webengine-Jequery��תHtml
*/

#ifndef WEBENGINEPLAY_H
#define WEBENGINEPLAY_H

#include <QtWidgets/QDialog>
#include "ui_webengineplay.h"

class WebenginePlay : public QDialog
{
	Q_OBJECT

public:
	WebenginePlay(QWidget *parent = 0);
	~WebenginePlay();

private slots:
	void changeLocation();
	void onHightlightLink();
	void onRotateImages();
	void onRemoveGifImages();
	void onUpdateScrollerStyle();

private:
	Ui::WebenginePlayClass ui;
};

#endif // WEBENGINEPLAY_H

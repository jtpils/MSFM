/*
 *  Created on: Mar 11, 2016
 *      Author: yoyo
 */

#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QList>

class QImage;
class ImageWidget: public QWidget
{
	Q_OBJECT
	//property, no ";" at the back
	Q_PROPERTY(float minZoom READ minimumZoom WRITE setMinimumZoom)
	Q_PROPERTY(float zoomFactor READ zoomFactor WRITE setZoomFactor)

signals:
	void markSelected(const int);
	void pointsMarked(const QList<QPointF> &);
	void selectionWindowChanged(const QRect &);
	void markDeleted(const int);
	void imageLoaded(const QImage &);
	void deletePressed();

public slots:
	void setImage(const QString &fileName);
	void setImage(const QImage &img);
	void setMarks(const QList<QPointF> &,  const QList<bool> &);
	
public:
	ImageWidget(QWidget *parent = 0);
	QSize sizeHint() const;
	QString getImagePath(){return imagePath;}
	float imgWidth(){ return image.width();}
	float imgHeight(){return image.height();}
	void setMinimumZoom(float newZoom);
	float minimumZoom() const { return minZoom; }
	void setZoomFactor(float newZoom);
	float zoomFactor() const { return zoom; }
	QList<QPointF> getMarks(){return marks;}
	void setSelected(const int);
	int getMarkToHightlight(){return markToHighlight;}
	void deleteSelected();
	bool isVisible(int idx);
	void setMask(QList<bool> m){mask = m;}
	QList<bool> getMask(){return mask;}

	
protected:
	void reset();
	virtual void drawMarks();
	virtual void drawSelectionWindow();
	void paintEvent(QPaintEvent *event);
	void wheelEvent(QWheelEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	virtual void  distToNearestMark(const QPointF &pos, float &minDist, int &minIdx);
	virtual QRect  pointsToRect(const QPointF &p1, const QPointF &p2);
	
private:
	QImage 					image;
	QString 				imagePath;
	QPixmap 				pixmap;
	float 					minZoom;
	float 					zoom;
	QList<QPointF> 			marks;
	QList<bool> 			mask;
	int 					markToHighlight;
	bool					showSelectWin;
	QPointF					selectWinStart;
	QPointF					selectWinEnd;
};

#endif


#ifndef DIAGRAM_H
#define DIAGRAM_H


#include <QWidget>
#include <QtWidgets>

class Diagram : public QWidget
{
    Q_OBJECT
public:
    explicit Diagram(QWidget *parent = nullptr);
    QVector <QVector<int>> nums = {};
    void paintEvent(QPaintEvent *);
    QPen pen;
    QBrush *br;
    QColor penColor;
    QColor brushColor;
    bool openGraph(QString name);
    bool saveImg(const QString &fileName);

private:
    qreal radius;

signals:

};

#endif // DIAGRAM_H


#ifndef TOPTEN_H
#define TOPTEN_H


#include <QWidget>
#include <QTableWidget>

class topTen : public QWidget
{
    Q_OBJECT
public:
    topTen(QWidget *parent = nullptr);
    void add(int score, QString name);
    bool isTop(int score);
    void refill();
private:
    //void save();
    std::multimap<int, QString, std::less<int>> storage;
    QTableWidget ratingTable;

};

#endif // TOPTEN_H

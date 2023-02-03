#ifndef CALC_H
#define CALC_H

#include <QMessageBox>
#include <cmath>
#include <string>
#include <vector>
#include <QObject>

using namespace std;


class calc : public QObject{
    Q_OBJECT
private:
    string m_a;
    vector<double> m_num;
    vector<char> m_opr;
    int error = 0;

    void _Calc(char c);
    int CheckNum(char c);
    int CheckOperate(char c);
    int PreorOpr(char c);
    void CheckFun(string &str);

public:
    calc(string &a);
    void Parsing();
    double getRezult();
};

#endif // CALC_H

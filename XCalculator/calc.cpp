#include "calc.h"

calc::calc(string &a)
{
    m_a = a;
}

int calc::CheckNum(char c)
{
    return (c <= '9' && c >= '0') || c == '.' || c == ',';
}

int calc::CheckOperate(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}
int calc::PreorOpr(char c)
{
    if(c<0) return 3;
    return c=='+' || c=='-' ? 1 :
           c=='*' || c=='/' || c=='%' ? 2 :
           c=='^' ? 4 :
           -1;
}
void calc::_Calc(char c)
{
    if(c<0)
        {
            double x=m_num.back(); m_num.pop_back();
            switch(-c){
                case '+': m_num.push_back(x); break;
                case '-': m_num.push_back(-x); break;
                case 's': m_num.push_back(sin(x)); break;
            case 'c': m_num.push_back(cos(x)); break;
            case 't': m_num.push_back(tan(x)); break;
            case 'w': m_num.push_back(1/tan(x)); break;
            case 'a': m_num.push_back(asin(x)); break;
            case 'r': m_num.push_back(acos(x)); break;
            case 'g': m_num.push_back(atan(x)); break;
            case 'q': m_num.push_back(M_PI_2 - atan(x)); break;
            case 'l': m_num.push_back(log(x)); break;

            }
        }
        else
        {
            double y=m_num.back(); m_num.pop_back();
            double x=m_num.back(); m_num.pop_back();
            switch(c){
                case '+': m_num.push_back( x + y ); break;
                case '-': m_num.push_back( x - y ); break;
                case '*': m_num.push_back( x * y ); break;
                case '/': m_num.push_back( x / y ); break;
                case '^': m_num.push_back(pow(x,y)); break;
            }
        }
}

void calc::Parsing()
{
    int n(m_a.size()), i(0);
    bool check(true);
    if(CheckOperate(m_a[n-1]) || m_a[n-1] == '(')
    {
        QMessageBox mb;
        mb.setText("Expression isn't correct!");
        mb.exec();
        return;
    }
    while(i < n){
        if(m_a[i] == '('){
            m_opr.push_back('(');
            check = true; i++;
        }
        else if(m_a[i] == ')'){
            while(m_opr.back() != '('){
                _Calc(m_opr.back());
                m_opr.pop_back();
            }
            m_opr.pop_back();
            check = false; i++;
        }
        else if(CheckOperate(m_a[i]))
                {
                    char z=m_a[i];
                    if(check==true) z=-z;
                    while(!(m_opr.empty()) && (PreorOpr(m_opr.back()) >= PreorOpr(z)) )
                    {
                        _Calc(m_opr.back());
                        m_opr.pop_back();
                    }
                    m_opr.push_back(z);
                    check=true; i++;
                }
        else if(m_a[i] >= 'a' && m_a[i] <= 't'){
            string str_ = "";
            while(m_a[i] >= 'a' && m_a[i] <= 'z'){
                str_ += m_a[i];
                i++;
            }
            CheckFun(str_);
            check = true;
        }
        else{
            string str_ = "";
            while(CheckNum(m_a[i])){
                        str_ += m_a[i];
                        i++;
                    }
            double res = atof(str_.c_str());
            m_num.push_back(res);
            check=false;
        }

    }
    while(!(m_opr.empty()))
    {
        _Calc(m_opr.back()); m_opr.pop_back();

    }

}

double calc::getRezult()
{
    if(m_num.empty())
        return 0;
    return m_num.back();
}


void calc::CheckFun(string &str)
{
    if(str == "sin") m_opr.push_back(-'s');
    else if(str == "tg") m_opr.push_back(-'t');
    else if(str == "cos") m_opr.push_back(-'c');
    else if(str == "arcsin") m_opr.push_back(-'a');
    else if(str == "arccos") m_opr.push_back(-'r');
    else if(str == "arctg") m_opr.push_back(-'g');
    else if(str == "arcctg") m_opr.push_back(-'q');
    else if(str == "ctg") m_opr.push_back(-'w');
    else if(str == "ln") m_opr.push_back(-'l');

}

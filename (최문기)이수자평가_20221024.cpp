#include <iostream>
using namespace std;

//3
#include <cstring>

class Calc
{
private:
    int a;
    int b;
    char c1[2] = "+";
    char c2[2] = "-";
    char c3[2] = "*";
    char c4[2] = "/";
public:
    Calc();
    ~Calc();
    void calculate(char operation[2]);
    void setValue(int a, int b);
};

Calc::Calc()
{
}

Calc::~Calc()
{
}

void Calc::calculate(char operation[1])
{
    if(strcmp(c1, operation) == 0) printf("%d", a + b);
    else if(strcmp(c2, operation) == 0) printf("%d", a - b);
    else if(strcmp(c3, operation) == 0) printf("%d", a * b);
    else if(strcmp(c4, operation) == 0) printf("%d", a / b);
}

void Calc::setValue(int a, int b)
{
    this->a = a;
    this->b = b;
}

class AddCalc : public Calc
{
private:
public:
    AddCalc(int a, int b, char operation[1]);
    ~AddCalc();
};

AddCalc::AddCalc(int a, int b, char operation[1])
: Calc()
{
    setValue(a, b);
    calculate(operation);
}

AddCalc::~AddCalc()
{
}

class SubCalc : public Calc
{
private:
public:
    SubCalc(int a, int b, char operation[1]);
    ~SubCalc();
};

SubCalc::SubCalc(int a, int b, char operation[1])
: Calc()
{
    setValue(a, b);
    calculate(operation);
}

SubCalc::~SubCalc()
{
}

class MulCalc : public Calc
{
private:
public:
    MulCalc(int a, int b, char operation[1]);
    ~MulCalc();
};

MulCalc::MulCalc(int a, int b, char operation[1])
: Calc()
{
    setValue(a, b);
    calculate(operation);
}

MulCalc::~MulCalc()
{
}

class DivCalc : public Calc
{
private:
public:
    DivCalc(int a, int b, char operation[1]);
    ~DivCalc();
};

DivCalc::DivCalc(int a, int b, char operation[1])
: Calc()
{
    setValue(a, b);
    calculate(operation);
}

DivCalc::~DivCalc()
{
}


int main()
{
    int num1 = 0, num2 = 0;
    char operation[2] = {0};
    char c1[2] = "+";
    char c2[2] = "-";
    char c3[2] = "*";
    char c4[2] = "/";

    cout << "input first integer" << endl;
    scanf("%d %d", &num1, &num2);
    cout << "type operation(+, -, * /)";
    scanf("%s", &operation);

    if(strcmp(c1, operation) == 0)
    {
        AddCalc addcalc(num1, num2, operation);
    }
    else if(strcmp(c2, operation) == 0)
    {
        SubCalc subcalc(num1, num2, operation);
    }
    else if(strcmp(c3, operation) == 0)
    {
        MulCalc subcalc(num1, num2, operation);
    }
    else if(strcmp(c4, operation) == 0)
    {
        DivCalc subcalc(num1, num2, operation);
    }
}

//4
int main()
{
    int num = 0;
    while(1)
    {
        printf("1부터 100까지 정수를 입력하세요 : ");
        scanf("%d", &num);
        if(num < 1 | num > 100)
        {
            cout << "예외 : 잘못 입력";
            break;
        }
        else if(num % 2)
        {
            cout << "홀수" <<endl;
        }
        else cout << "짝수" << endl;
    }
    return 0;
}

//5
namespace TEST
{ 
    int gData = 100;
    namespace DEV
    { 
        int gData = 200;
        namespace WIN
        {
            int gData = 300;
        }
    }
}

int main(int argc, char *argv[])
{
    printf("%d, %d, %d", TEST::gData, TEST::DEV::gData, TEST::DEV::WIN::gData);
    cout << TEST::gData << TEST::DEV::gData << TEST::DEV::WIN::gData;
    
    return 0;
}

//6
#include <malloc.h>
#include <string.h>
#include <string>

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard
{
private:
    char* inname;
    char* incompany;
    char* inphone_number;
    int inrank;

public:
    NameCard(char* name, char* company, char* phone_number, int rank);
    ~NameCard();
    void ShowNameCardInfo();
};

NameCard::NameCard(char* name, char* company, char* phone_number, int rank)
{
    inname = new char[strlen(name) + 1];
    strcpy(inname, name);
    incompany = new char[strlen(company)+1];
    strcpy(incompany, company);
    inphone_number = new char[strlen(phone_number)+1];
    strcpy(inphone_number, phone_number);
    inrank = rank;
}

NameCard::~NameCard()
{
    delete inname;
    delete incompany;
    delete inphone_number;
}

void NameCard::ShowNameCardInfo()
{
    printf("이름 : ");
    cout << inname << endl;
    printf("회사 : ");
    cout << incompany << endl;
    printf("전화번호 : ");
    cout << inphone_number << endl;
    printf("직급 : ");
    if(inrank == 0)
    {
        cout << "사원" << endl;
    }
    if(inrank == 1)
    {
        cout << "주임" << endl;
    }
    if(inrank == 2)
    {
        cout << "대리" << endl;
    }
    if(inrank == 3)
    {
        cout << "과장" << endl;
    }
}


int main(void)
{    
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}
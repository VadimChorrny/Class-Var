#include "Var.h"

Var::Var(const int& number)
{
    typeID = 0;
    pInt = new int(number);
}

Var::Var(const double& number)
{
    typeID = 1;
    pDouble = new double(number);
}

Var::Var(const string& str)
{
    typeID = 2;
    pStr = new string(str);
}

void Var::Show()
{
    switch (typeID)
    {
    case 0: cout << *pInt; return;
    case 1: cout << *pDouble; return;
    case 2: cout << *pStr; return;
    }
    cout << "NULL";

}

int Var::toInt() const
{
    switch (typeID)
    {
    case 0: return *pInt;
    case 1: return (int)*pDouble;
    case 2: return atoi((*pStr).c_str());
    }
    return 0;
}

double Var::toDouble() const
{
    switch (typeID)
    {
    case 0: return (double)*pInt;
    case 1: return *pDouble;
    case 2: return (double)atof((*pStr).c_str());
    }
    return 0;
}

char* Var::toCharPtr() const
{
    char* tmpStr = new char[80];
    switch (typeID)
    {
    case 0:
        return itoa(*pInt, tmpStr, 10);
    case 1:
        sprintf(tmpStr, "%lf", *pDouble);
        return tmpStr;
    case 2:
        strcpy(tmpStr, (*pStr).c_str());
        return tmpStr;
    }
    return NULL;
}

const string Var::toString() const
{
    if (typeID == 2)
    {
        return string(*pStr);

    }
    return string(toCharPtr());


}

const Var Var::operator + (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return Var(*pInt + rightVar.toInt());

    case 1:
        return Var(*pDouble + rightVar.toDouble());

    case 2:
        return Var(*pStr + rightVar.toString());

    }
    return *this;
}

const Var Var::operator - (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return Var(*pInt - rightVar.toInt());
    case 1:
        return Var(*pDouble - rightVar.toDouble());

    case 2:
        return Var(*pStr - rightVar.toString());

    }
    return *this;
}

const Var Var::operator * (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return Var(*pInt * rightVar.toInt());

    case 1:
        return Var(*pDouble * rightVar.toDouble());

    case 2:
        return Var(*pStr * rightVar.toString());

    }
    return *this;
}

const Var Var::operator / (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return Var(*pInt / rightVar.toInt());

    case 1:
        return Var(*pDouble / rightVar.toDouble());

    case 2:
        return Var(*pStr / rightVar.toString());

    }
    return *this;
}

Var& Var::operator += (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        *pInt = *pInt + rightVar.toInt();
        return *this;
    case 1:
        *pDouble = *pDouble + rightVar.toDouble();
        return *this;
    case 2:
        *pStr = *pStr + rightVar.toString();
        return *this;
    }
    return *this;
}

Var& Var::operator -= (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        *pInt = *pInt - rightVar.toInt();
        return *this;
    case 1:
        *pDouble = *pDouble - rightVar.toDouble();
        return *this;
    case 2:
        *pStr = *pStr - rightVar.toString();
        return *this;
    }
    return *this;
}

Var& Var::operator *= (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        *pInt = *pInt * rightVar.toInt();
        break;
    case 1:
        *pDouble = *pDouble * rightVar.toDouble();
        break;
    case 2:
        *pStr = *pStr * rightVar.toString();
        break;
    }
    return *this;
}

Var& Var::operator /= (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        *pInt = *pInt / rightVar.toInt();
        break;
    case 1:
        *pDouble = *pDouble / rightVar.toDouble();
        break;
    case 2:
        *pStr = *pStr / rightVar.toString();
        break;
    }
    return *this;
}

bool Var::operator > (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return *pInt > rightVar.toInt();
    case 1:
        return *pDouble > rightVar.toDouble();
    case 2:
        return *pStr > rightVar.toString();
    }
    return false;
}

bool Var::operator < (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return *pInt < rightVar.toInt();
    case 1:
        return *pDouble < rightVar.toDouble();
    case 2:
        return *pStr < rightVar.toString();
    }
    return false;
}

bool Var::operator == (const Var& rightVar)
{
    switch (typeID)
    {
    case 0:
        return *pInt == rightVar.toInt();
    case 1:
        return *pDouble == rightVar.toDouble();
    case 2:
        return *pStr == rightVar.toString();
    }
    return false;
}

bool Var::operator <= (const Var& rightVar)
{
    return(!(*this > rightVar));
}

bool Var::operator >= (const Var& rightVar)
{
    return(!(*this < rightVar));
}

bool Var::operator != (const Var& rightVar)
{
    return(!(*this == rightVar));
}
Var& Var::operator =(const Var& rightVar)
{
    if (this == &rightVar)
    {
        return *this;
    }
    switch (typeID)
    {
    case 0:
        delete pInt;
        break;
    case 1:
        delete pDouble;
        break;
    case 2:
        delete pStr;
        break;
    }
    typeID = -1;
    switch (rightVar.typeID)
    {
    case 0:
        pInt = new int(*(rightVar.pInt));
        break;
    case 1:
        pDouble = new double(*(rightVar.pDouble));
        break;
    case 2:
        pStr = new string(*(rightVar.pStr));
        break;
    }
    typeID = rightVar.typeID;
    return *this;
}
Var& Var::operator = (const int& number)
{
    switch (typeID)
    {
    case 0:
        delete pInt;
        break;
    case 1:
        delete pDouble;
        break;
    case 2:
        delete pStr;
        break;
    }
    typeID = 0;
    pInt = new int(number);
    return *this;


}
Var& Var::operator = (const double& number)
{
    switch (typeID)
    {
    case 0:
        delete pInt;
        break;
    case 1:
        delete pDouble;
        break;
    case 2:
        delete pStr;
        break;
    }
    typeID = 1;
    pDouble = new double(number);
    return *this;
}
Var& Var::operator = (const string& str)
{
    switch (typeID)
    {
    case 0:
        delete pInt;
        break;
    case 1:
        delete pDouble;
        break;
    case 2:
        delete pStr;
        break;
    }
    typeID = 2;
    pStr = new string(str);
    return *this;
}


const string operator * (const string& leftStr, const string& rightStr)
{
    string tmp;
    string::const_iterator i;
    string::const_iterator j;
    for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
        for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
            if (*i == *j)
            {
                tmp.push_back(*i);
                break;
            }

    return tmp;

}
const string operator / (const string& leftStr, const string& rightStr)
{
    bool flag = true;
    string tmp;
    string::const_iterator i;
    string::const_iterator j;
    for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
    {
        for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
        {
            if (*i == *j)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            flag = true;
            continue;
        }
        tmp.push_back(*i);
    }
    return tmp;

}
const string operator - (const string& leftStr, const string& rightStr)
{
    return leftStr;
}

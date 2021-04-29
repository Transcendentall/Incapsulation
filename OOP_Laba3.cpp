#include <iostream>

using namespace std;



class Rectangle1   // отсутствие инкапсуляции
{
private:

public:
    int a = 0;
    int b = 0;
    void CalculateS()
        {
            cout << "S (of rectangle1) = " << a*b << endl << endl;
        }

protected:

};

class Rectangle2   // èíêàïñóëÿöèÿ ñ ïîìîùüþ getter/setter
{
private:
    int a = 0;
    int b = 0;

public:
    void CalculateS()
        {
            if ((a>=0) && (b>=0))
            {
                cout << "S (of rectangle2) = " << a*b << endl << endl;
            }
        }

void seta(int a)
{

        try
        {
            if (a < 0)
            throw 1;
        }
        catch(int err)
        {
            if (err=1)
            {
                cout << "ACHTUNG! Ñòîðîíà ïðÿìîóãîëüíèêà äîëæíà áûòü áîëüøå èëè ðàâíà 0!" << endl;
            }
        }

    this->a = a;
}

int geta()
{
    return this->a;
}

void setb(int b)
{

        try
        {
            if (b < 0)
            throw 1;
        }
        catch(int err)
        {
            if (err=1)
            {
                cout << "ACHTUNG! Ñòîðîíà ïðÿìîóãîëüíèêà äîëæíà áûòü áîëüøå èëè ðàâíà 0!" << endl;
            }
        }

    this->b = b;
}

int getb()
{
    return this->b;
}

protected:

};


class Rectangle3   // èíêàïñóëÿöèÿ ñ ïîìîùüþ ñïåö. ïðîòîêîëîâ äîñòóïà
{
private:
    int a = 0;
    int b = 0;

public:
    void CalculateS()
        {
            cout << "S (of rectangle3) = " << a*b << endl << endl;
        }

void inca()
{
    this->a = a+1;
}
int outa()
{
    cout << "a = " << this->a << endl;;
    return (this->a);
}

void incb()
{
    this->b = b+1;
}

int outb()
{
    cout << "b = " << this->b << endl;;
    return (this->b);
}

protected:

};

class AbstractRectangle4   // èíêàïñóëÿöèÿ çà ñ÷¸ò àáñòðàêöèé
{
private:

public:
    virtual void CalculateS() const = 0;
    virtual void seta(int a) = 0;
    virtual void setb(int b) = 0;
    virtual int geta() const = 0;
    virtual int getb() const = 0;

protected:

};
class Rectangle4: public AbstractRectangle4
{
private:
    int a = 0;
    int b = 0;

public:
    void CalculateS() const override
        {
            if ((a>=0) && (b>=0))
            {
                cout << "S (of rectangle4) = " << a*b << endl << endl;
            }
        }

void seta(int a) override
{

        try
        {
            if (a < 0)
            throw 1;
        }
        catch(int err)
        {
            if (err=1)
            {
                cout << "ACHTUNG! Ñòîðîíà ïðÿìîóãîëüíèêà äîëæíà áûòü áîëüøå èëè ðàâíà 0!" << endl;
            }
        }

    this->a = a;
}

int geta() const override
{
    return this->a;
}

void setb(int b) override
{

        try
        {
            if (b < 0)
            throw 1;
        }
        catch(int err)
        {
            if (err=1)
            {
                cout << "ACHTUNG! Ñòîðîíà ïðÿìîóãîëüíèêà äîëæíà áûòü áîëüøå èëè ðàâíà 0!" << endl;
            }
        }

    this->b = b;
}

int getb() const override
{
    return this->b;
}

protected:

};

int main()
{

    Rectangle1* R1 = new Rectangle1(); // áåç èíêàïñóëÿöèè
    R1->a=3;
    R1->b=2;
    R1->CalculateS();

    Rectangle2* R2 = new Rectangle2(); // èíêàïñóëÿöèÿ ñ ïîìîùüþ getter/setter
    R2->seta(3);
    R2->setb(2);
    R2->CalculateS();

    Rectangle3* R3 = new Rectangle3(); // èíêàïñóëÿöèÿ ñ ïîìîùüþ ñïåö. ïðîòîêîëîâ
    for (int i=0; i<3; ++i)
    {
    R3->inca();
    }
    for (int i=0; i<2; ++i)
    {
    R3->incb();
    }
    R3->CalculateS();


    AbstractRectangle4* R4 = new Rectangle4(); // èíêàïñóëÿöèÿ çà ñ÷¸ò àáñòðàêöèé
    R4->seta(3);
    R4->setb(2);
    R4->CalculateS();

}

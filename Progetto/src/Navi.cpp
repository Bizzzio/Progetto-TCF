#include <iostream>
#include "Navi.h"
using namespace std;

Navi::Navi(bool horizontal, int x, int y, int l)
{
    SetLength(l);
    SetHorizontal(horizontal);
    SetX(x);
    SetY(y);
    for (int i = 0; i < GetLength(); i++)
        Hit.push_back(false); //costruisce il vettore Hit; siccome in costruzione nessuna casella è colpita, il vector di Hit è riempito di false
}

void Navi::SetX(int x)
{
    X = x;
}

void Navi::SetY(int y)
{
    Y = y;
}

void Navi::SetHorizontal(bool horizontal)
{
    Horizontal = horizontal;
}

void Navi::SetLength(int length)
{
    Length = length;
}

int Navi::GetX() const
{
    return X;
}

int Navi::GetY() const
{
    return Y;
}

int Navi::GetLength() const
{
    return Length;
}

bool Navi::IsHorizontal() const
{
    return Horizontal;
}

bool Navi::Sunk() const
{

    vector<bool>::const_iterator k;
    for (k = Hit.begin(); k < Hit.end(); k++)
    {
        if (!(*k))
            return false;
    }

    return true;
}

void Navi::DrawEnemy(int x, int y) const
{

    if (GetLength() == -1) //se la nave è acqua si stampa una ~, perchè se viene chiamata la "nave acqua" allora vuol dire che è stata colpita
    {
        cout << "~ ";
    }

    else
    {
        if (Sunk()) //se la nave è affondata si stampa la lunghezza della nave anzichè una X
        {
            cout << GetLength() << " ";
        }
        else
        {
            if (IsHorizontal())
            {
                if (GetVector()[x - GetX()]) //qua viene identificata la cella del vettore Hit corrispondente alla casella colpita
                    cout << "X ";
                else
                    cout << ". ";
            }
            else
            {
                if (GetVector()[y - GetY()])
                    cout << "X ";
                else
                    cout << ". ";
            }
        }
    }
}

void Navi::DrawAlly(int x, int y) const
{

    if (Length == -1)
    {
        cout << "~ ";
    }

    else
    {
        if (IsHorizontal())
        {
            if (GetVector()[x - GetX()])
                cout << "X ";
            else
                cout << GetLength() << " ";
        }
        else
        {
            if (GetVector()[y - GetY()])
                cout << "X ";
            else
                cout << GetLength() << " ";
        }
    }
}

void Navi::Strike(int x, int y) //questa funzione si occupa di cambiare la casella del vettore in true quando la cella corrispondente viene colpita
{
    if (IsHorizontal())
        Hit[x - GetX()] = true;

    else
        Hit[y - GetY()] = true;
}

bool Navi::IsHit(int x, int y) const
{
    if (IsHorizontal())
        return Hit[x - GetX()];

    else
        return Hit[y - GetY()];
}

vector<bool> Navi::GetVector() const
{
    return Hit;
}
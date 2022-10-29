#include <iostream>
#include <vector>
#include <windows.h>
#include <time.h>

using namespace std;

bool isValid(vector<vector<int>>& plansza, int x, int y, int wielkosc_planszy, int startowy);
void wypelnianie(vector<vector<int>>& plansza, int x, int y, int wielkosc_planszy, int startowy,int &wall);

int main()
{
    int wielkosc_planszy = 0, x = 0, y = 0, wall = 0;
    srand(time(NULL));
    while (wielkosc_planszy < 3 || wielkosc_planszy > 500) {
        cout << "Podaj wielkosc planszy(od 3 do 500): ";
        cin >> wielkosc_planszy;
    }
    vector<vector<int>> plansza(wielkosc_planszy, vector<int>(wielkosc_planszy, 0));

    for (auto it_row = plansza.begin() + 1; it_row != plansza.end() - 1; it_row++) {
        for (auto it_col = it_row->begin() + 1; it_col != it_row->end() - 1; it_col++)
        {
            *it_col = (rand() % 3) / 2;
        }
    }

    while(plansza[x][y]== 0) {
        for (int i = 0; i < wielkosc_planszy; i++)
        {
            for (int j = 0; j < wielkosc_planszy; j++)
            {
                cout << plansza[i][j] << " ";
            }
            cout << endl;
        }
        if (plansza[x][y] == 0)
            cout << "Podaj pozycje startowa (1)" << endl;
        cout << "Podaj pozycje startowe(x,y)" << endl;
        cout << "Podaj x: ";
        cin >> y;
        cout << "Podaj y: ";
        cin >> x;
        x--;
        y--;
        system("cls");
        
    }
    int startowy = plansza[x][y];
    wypelnianie(plansza, x, y, wielkosc_planszy, startowy, wall);

    for (int i = 0; i < wielkosc_planszy; i++)
    {
        for (int j = 0; j < wielkosc_planszy; j++)
        {
            cout << plansza[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Ilosc scian w komnacie: " << wall;
    return 0;

}


void wypelnianie(vector<vector<int>>& plansza, int x, int y, int wielkosc_planszy, int startowy, int &wall) {
    vector<pair<int, int>> start;
    pair<int, int> s(x, y);
    start.push_back(s);

    plansza[x][y] = 2;

    while (start.size() > 0) {
        pair<int, int> pix = start[start.size() - 1];
        start.pop_back();

        int Xx = pix.first;
        int Yy = pix.second;
        if (isValid(plansza, Xx - 1, Yy, wielkosc_planszy, startowy))
        {
            plansza[(allocator<int>::size_type(Xx)) - 1][Yy] = 2;
            s.first = Xx - 1;
            s.second = Yy;
            start.push_back(s);
        }
        else if(plansza[(allocator<int>::size_type(Xx)) - 1][Yy] == 0)
            wall++;

        if (isValid(plansza, Xx + 1, Yy, wielkosc_planszy, startowy))
        {
            plansza[(allocator<int>::size_type(Xx)) + 1][Yy] = 2;
            s.first = Xx + 1;
            s.second = Yy;
            start.push_back(s);
        }
        else if (plansza[(allocator<int>::size_type(Xx)) + 1][Yy] == 0)
            wall++;

        if (isValid(plansza, Xx, Yy - 1, wielkosc_planszy, startowy))
        {
            plansza[Xx][(allocator<int>::size_type(Yy)) - 1] = 2;
            s.first = Xx;
            s.second = Yy - 1;
            start.push_back(s);
        }
        else if (plansza[Xx][allocator<int>::size_type(Yy) - 1] == 0)
            wall++;

        if (isValid(plansza, Xx, Yy + 1, wielkosc_planszy, startowy))
        {
            plansza[Xx][allocator<int>::size_type(Yy) + 1] = 2;
            s.first = Xx;
            s.second = Yy + 1;
            start.push_back(s);
        }
        else if (plansza[Xx][allocator<int>::size_type(Yy) + 1] == 0)
            wall++;
    }
}

bool isValid(vector<vector<int>>& plansza, int x, int y, int wielkosc_planszy, int startowy)
{
    if (x < 0 || x >= wielkosc_planszy || y < 0 || y >= wielkosc_planszy || plansza[x][y] != startowy
        || plansza[x][y] == 2)
        return false;
    else
        return true;
}




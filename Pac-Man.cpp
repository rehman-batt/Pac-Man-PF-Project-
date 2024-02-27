#include <iostream>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <conio.h>

using namespace std;

string map[40][30];
int noOfPallets = 0, score = 0;
bool finish = true;

void designMap()
{
    for (int y = 0; y < 30; y++)
    {
        for (int x = 0; x < 40; x++)
        {
            if ((x == 0) || (x + 1 == 40) || (y == 0) || (y + 1 == 30))
            {
                map[x][y] = "#";
            }
            else
            {
                if ((rand() % 2) && (x % 2) && (y % 2))
                {
                    map[x][y] = "#";
                }
                else
                {
                    if ((rand() % 50 == 2))
                    {
                        map[x][y] = "O";
                        noOfPallets++;
                    }
                    else
                    {
                        map[x][y] = " ";
                    }
                }
            }
        }
    }
}

void spawn(int *xCoordinatePac, int *yCoordinatePac, int *xCoordinateG1, int *yCoordinateG1, int *xCoordinateG2, int *yCoordinateG2, int *xCoordinateG3, int *yCoordinateG3)
{
    do
    {
        *xCoordinatePac = rand() % 37 + 1;
        *yCoordinatePac = rand() % 27 + 1;
    } while (!(map[*xCoordinatePac][*yCoordinatePac] == " "));

    do
    {
        *xCoordinateG1 = rand() % 37 + 1;
        *yCoordinateG1 = rand() % 27 + 1;
    } while (!(map[*xCoordinateG1][*yCoordinateG1] == " "));

    do
    {
        *xCoordinateG2 = rand() % 37 + 1;
        *yCoordinateG2 = rand() % 27 + 1;
    } while (!(map[*xCoordinateG2][*yCoordinateG2] == " "));

    do
    {
        *xCoordinateG3 = rand() % 37 + 1;
        *yCoordinateG3 = rand() % 27 + 1;
    } while (!(map[*xCoordinateG3][*yCoordinateG3] == " "));

    map[*xCoordinatePac][*yCoordinatePac] = "<";
    map[*xCoordinateG1][*yCoordinateG1] = "8";
    map[*xCoordinateG2][*yCoordinateG2] = "8";
    map[*xCoordinateG3][*yCoordinateG3] = "8";
}

void draw(int *xCoordinatePac, int *yCoordinatePac)
{

    system("cls");

    cout << "\tScore: " << score << endl
         << endl;

    for (int y = 0; y < 30; y++)
    {
        for (int x = 0; x < 40; x++)
        {
            cout << map[x][y];
        }
        cout << endl;
    }
}

void move(int *xCoordinatePac, int *yCoordinatePac)
{

    char nextMove = getch();

    if ((nextMove == 'w') || (nextMove == 'W'))
    {
        if (!(map[*xCoordinatePac][*(yCoordinatePac)-1] == "#"))
        {
            (*yCoordinatePac)--;
            if (map[*xCoordinatePac][*yCoordinatePac] == "O")
            {
                score += 50;
                noOfPallets--;
            }
            else if (map[*xCoordinatePac][*yCoordinatePac] == "8")
            {
                noOfPallets = 0;
                finish = false;
            }

            map[*xCoordinatePac][*yCoordinatePac] = "^";
            map[*xCoordinatePac][*(yCoordinatePac) + 1] = " ";
        }
    }
    else if ((nextMove == 's') || (nextMove == 'S'))
    {
        if (!(map[*xCoordinatePac][*(yCoordinatePac) + 1] == "#"))
        {
            (*yCoordinatePac)++;
            if (map[*xCoordinatePac][*yCoordinatePac] == "O")
            {
                score += 50;
                noOfPallets--;
            }
            else if (map[*xCoordinatePac][*yCoordinatePac] == "8")
            {
                noOfPallets = 0;
                finish = false;
            }

            map[*xCoordinatePac][*yCoordinatePac] = "V";
            map[*xCoordinatePac][*(yCoordinatePac)-1] = " ";
        }
    }
    else if ((nextMove == 'a') || (nextMove == 'A'))
    {
        if (!(map[(*xCoordinatePac) - 1][*yCoordinatePac] == "#"))
        {
            (*xCoordinatePac)--;
            if (map[*xCoordinatePac][*yCoordinatePac] == "O")
            {
                score += 50;
                noOfPallets--;
            }
            else if (map[*xCoordinatePac][*yCoordinatePac] == "8")
            {
                noOfPallets = 0;
                finish = false;
            }

            map[*xCoordinatePac][*yCoordinatePac] = "<";
            map[*(xCoordinatePac) + 1][*yCoordinatePac] = " ";
        }
    }
    else if ((nextMove == 'd') || (nextMove == 'D'))
    {
        if (!(map[(*xCoordinatePac) + 1][*yCoordinatePac] == "#"))
        {
            (*xCoordinatePac)++;
            if (map[*xCoordinatePac][*yCoordinatePac] == "O")
            {
                score += 50;
                noOfPallets--;
            }
            else if (map[*xCoordinatePac][*yCoordinatePac] == "8")
            {
                noOfPallets = 0;
                finish = false;
            }

            map[*xCoordinatePac][*yCoordinatePac] = ">";
            map[*(xCoordinatePac)-1][*yCoordinatePac] = " ";
        }
    }
}

void ghostMovement(int *xCoordinatePac, int *yCoordinatePac, int *xCoordinateG1, int *yCoordinateG1, int *xCoordinateG2, int *yCoordinateG2, int *xCoordinateG3, int *yCoordinateG3)
{

    int move = 0;

    // Random Ghost 1
    do
    {
        int g1 = rand() % 4;

        if (g1 == 0)
        {
            if ((map[(*xCoordinateG1) + 1][*yCoordinateG1] == "^") || (map[(*xCoordinateG1) + 1][*yCoordinateG1] == "V") || (map[(*xCoordinateG1) + 1][*yCoordinateG1] == ">") || (map[(*xCoordinateG1) + 1][*yCoordinateG1] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[(*xCoordinateG1) + 1][*yCoordinateG1] == "#")) && (!(map[(*xCoordinateG1) + 1][*yCoordinateG1] == "O")))
            {
                (*xCoordinateG1)++;
                move++;
                map[*xCoordinateG1][*yCoordinateG1] = "8";
                map[*(xCoordinateG1)-1][*yCoordinateG1] = " ";
            }
        }
        else if (g1 == 1)
        {
            if ((map[(*xCoordinateG1) - 1][*yCoordinateG1] == "^") || (map[(*xCoordinateG1) - 1][*yCoordinateG1] == "V") || (map[(*xCoordinateG1) - 1][*yCoordinateG1] == ">") || (map[(*xCoordinateG1) - 1][*yCoordinateG1] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[(*xCoordinateG1) - 1][*yCoordinateG1] == "#")) && (!(map[(*xCoordinateG1) - 1][*yCoordinateG1] == "O")))
            {
                (*xCoordinateG1)--;
                move++;
                map[*xCoordinateG1][*yCoordinateG1] = "8";
                map[*(xCoordinateG1) + 1][*yCoordinateG1] = " ";
            }
        }
        else if (g1 == 2)
        {
            if ((map[*xCoordinateG1][*(yCoordinateG1) + 1] == "^") || (map[*xCoordinateG1][*(yCoordinateG1) + 1] == "V") || (map[*xCoordinateG1][*(yCoordinateG1) + 1] == ">") || (map[*xCoordinateG1][*(yCoordinateG1) + 1] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[*xCoordinateG1][*(yCoordinateG1) + 1] == "#")) && (!(map[*xCoordinateG1][*(yCoordinateG1) + 1] == "O")))
            {
                (*yCoordinateG1)++;
                move++;
                map[*xCoordinateG1][*yCoordinateG1] = "8";
                map[*xCoordinateG1][*(yCoordinateG1)-1] = " ";
            }
        }
        else if (g1 == 3)
        {
            if ((map[*xCoordinateG1][*(yCoordinateG1)-1] == "^") || (map[*xCoordinateG1][*(yCoordinateG1)-1] == "V") || (map[*xCoordinateG1][*(yCoordinateG1)-1] == ">") || (map[*xCoordinateG1][*(yCoordinateG1)-1] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[*xCoordinateG1][*(yCoordinateG1)-1] == "#")) && (!(map[*xCoordinateG1][*(yCoordinateG1)-1] == "O")))
            {
                (*yCoordinateG1)--;
                move++;
                map[*xCoordinateG1][*yCoordinateG1] = "8";
                map[*xCoordinateG1][*(yCoordinateG1) + 1] = " ";
            }
        }

    } while (move == 0);

    // Random Ghost 2
    do
    {
        int g2 = rand() % 4;

        if (g2 == 0)
        {
            if ((map[(*xCoordinateG2) + 1][*yCoordinateG2] == "^") || (map[(*xCoordinateG2) + 1][*yCoordinateG2] == "V") || (map[(*xCoordinateG2) + 1][*yCoordinateG2] == ">") || (map[(*xCoordinateG2) + 1][*yCoordinateG2] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[(*xCoordinateG2) + 1][*yCoordinateG2] == "#")) && (!(map[(*xCoordinateG2) + 1][*yCoordinateG2] == "O")))
            {
                (*xCoordinateG2)++;
                move++;
                map[*xCoordinateG2][*yCoordinateG2] = "8";
                map[*(xCoordinateG2)-1][*yCoordinateG2] = " ";
            }
        }
        else if (g2 == 1)
        {
            if ((map[(*xCoordinateG2) - 1][*yCoordinateG2] == "^") || (map[(*xCoordinateG2) - 1][*yCoordinateG2] == "V") || (map[(*xCoordinateG2) - 1][*yCoordinateG2] == ">") || (map[(*xCoordinateG2) - 1][*yCoordinateG2] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[(*xCoordinateG2) - 1][*yCoordinateG2] == "#")) && (!(map[(*xCoordinateG2) - 1][*yCoordinateG2] == "O")))
            {
                (*xCoordinateG2)--;
                move++;
                map[*xCoordinateG2][*yCoordinateG2] = "8";
                map[*(xCoordinateG2) + 1][*yCoordinateG2] = " ";
            }
        }
        else if (g2 == 2)
        {
            if ((map[*xCoordinateG2][*(yCoordinateG2) + 1] == "^") || (map[*xCoordinateG2][*(yCoordinateG2) + 1] == "V") || (map[*xCoordinateG2][*(yCoordinateG2) + 1] == ">") || (map[*xCoordinateG2][*(yCoordinateG2) + 1] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[*xCoordinateG2][*(yCoordinateG2) + 1] == "#")) && (!(map[*xCoordinateG2][*(yCoordinateG2) + 1] == "O")))
            {
                (*yCoordinateG2)++;
                move++;
                map[*xCoordinateG2][*yCoordinateG2] = "8";
                map[*xCoordinateG2][*(yCoordinateG2)-1] = " ";
            }
        }
        else if (g2 == 3)
        {
            if ((map[*xCoordinateG2][*(yCoordinateG2)-1] == "^") || (map[*xCoordinateG2][*(yCoordinateG2)-1] == "V") || (map[*xCoordinateG2][*(yCoordinateG2)-1] == ">") || (map[*xCoordinateG2][*(yCoordinateG2)-1] == "<"))
            {
                noOfPallets = 0;
                finish = false;
            }
            else if ((!(map[*xCoordinateG2][*(yCoordinateG2)-1] == "#")) && (!(map[*xCoordinateG2][*(yCoordinateG2)-1] == "O")))
            {
                (*yCoordinateG2)--;
                move++;
                map[*xCoordinateG2][*yCoordinateG2] = "8";
                map[*xCoordinateG2][*(yCoordinateG2) + 1] = " ";
            }
        }

    } while (move == 1);

    

    int eDistance = sqrt((pow(*xCoordinatePac - *xCoordinateG3, 2)) + (pow(*yCoordinatePac - *yCoordinateG3, 2)));

    if ((eDistance > (sqrt((pow(*xCoordinatePac - ((*xCoordinateG3) + 1), 2)) + (pow(*yCoordinatePac - *yCoordinateG3, 2))))) && ((!(map[(*xCoordinateG3) + 1][*yCoordinateG3] == "#"))) && ((!(map[(*xCoordinateG3) + 1][*yCoordinateG3] == "O"))))
    {
        if ((map[(*xCoordinateG3) + 1][*yCoordinateG3] == "^") || (map[(*xCoordinateG3) + 1][*yCoordinateG3] == "V") || (map[(*xCoordinateG3) + 1][*yCoordinateG3] == ">") || (map[(*xCoordinateG3) + 1][*yCoordinateG3] == "<"))
        {
            noOfPallets = 0;
            finish = false;
        }
        else
        {
            (*xCoordinateG3)++;
            map[*xCoordinateG3][*yCoordinateG3] = "8";
            map[*(xCoordinateG3)-1][*yCoordinateG3] = " ";
        }
    }
    else if ((eDistance > (sqrt((pow(*xCoordinatePac - ((*xCoordinateG3) - 1), 2)) + (pow(*yCoordinatePac - *yCoordinateG3, 2))))) && ((!(map[(*xCoordinateG3) - 1][*yCoordinateG3] == "#"))) && ((!(map[(*xCoordinateG3) - 1][*yCoordinateG3] == "O"))))
    {
        if ((map[(*xCoordinateG3) - 1][*yCoordinateG3] == "^") || (map[(*xCoordinateG3) - 1][*yCoordinateG3] == "V") || (map[(*xCoordinateG3) - 1][*yCoordinateG3] == ">") || (map[(*xCoordinateG3) - 1][*yCoordinateG3] == "<"))
        {
            noOfPallets = 0;
            finish = false;
        }
        else
        {
            (*xCoordinateG3)--;
            map[*xCoordinateG3][*yCoordinateG3] = "8";
            map[*(xCoordinateG3) + 1][*yCoordinateG3] = " ";
        }
    }
    else if ((eDistance > (sqrt((pow(*xCoordinatePac - *xCoordinateG3, 2)) + (pow(*yCoordinatePac - ((*yCoordinateG3) + 1), 2))))) && ((!(map[*xCoordinateG3][(*yCoordinateG3) + 1] == "#"))) && ((!(map[*xCoordinateG3][(*yCoordinateG3) + 1] == "O"))))
    {
        if ((map[*xCoordinateG3][*(yCoordinateG3) + 1] == "^") || (map[*xCoordinateG3][*(yCoordinateG3) + 1] == "V") || (map[*xCoordinateG3][*(yCoordinateG3) + 1] == ">") || (map[*xCoordinateG3][*(yCoordinateG3) + 1] == "<"))
        {
            noOfPallets = 0;
            finish = false;
        }
        else
        {
            (*yCoordinateG3)++;
            map[*xCoordinateG3][*yCoordinateG3] = "8";
            map[*xCoordinateG3][(*yCoordinateG3) - 1] = " ";
        }
    }
    else if ((eDistance > (sqrt((pow(*xCoordinatePac - *xCoordinateG3, 2)) + (pow(*yCoordinatePac - ((*yCoordinateG3) - 1), 2))))) && ((!(map[*xCoordinateG3][(*yCoordinateG3) - 1] == "#"))) && ((!(map[*xCoordinateG3][(*yCoordinateG3) - 1] == "O"))))
    {
        if ((map[*xCoordinateG3][*(yCoordinateG3)-1] == "^") || (map[*xCoordinateG3][*(yCoordinateG3)-1] == "V") || (map[*xCoordinateG3][*(yCoordinateG3)-1] == ">") || (map[*xCoordinateG3][*(yCoordinateG3)-1] == "<"))
        {
            noOfPallets = 0;
            finish = false;
        }
        else
        {
            (*yCoordinateG3)--;
            map[*xCoordinateG3][*yCoordinateG3] = "8";
            map[*xCoordinateG3][(*yCoordinateG3) + 1] = " ";
        }
    }
    else if ((!(map[(*xCoordinateG3) + 1][*yCoordinateG3] == "#")) && (!(map[(*xCoordinateG3) + 1][*yCoordinateG3] == "O")))
    {
        (*xCoordinateG3)++;
        map[*xCoordinateG3][*yCoordinateG3] = "8";
        map[*(xCoordinateG3)-1][*yCoordinateG3] = " ";
    }
    else if ((!(map[(*xCoordinateG3) - 1][*yCoordinateG3] == "#")) && (!(map[(*xCoordinateG3) - 1][*yCoordinateG3] == "O")))
    {
        (*xCoordinateG3)--;
        map[*xCoordinateG3][*yCoordinateG3] = "8";
        map[*(xCoordinateG3) + 1][*yCoordinateG3] = " ";
    }
    else if ((!(map[*xCoordinateG3][*(yCoordinateG3) + 1] == "#")) && (!(map[*xCoordinateG3][*(yCoordinateG3) + 1] == "O")))
    {
        (*yCoordinateG3)++;
        map[*xCoordinateG3][*yCoordinateG3] = "8";
        map[*xCoordinateG3][*(yCoordinateG3)-1] = " ";
    }
    else if ((!(map[*xCoordinateG3][*(yCoordinateG3)-1] == "#")) && (!(map[*xCoordinateG3][*(yCoordinateG3)-1] == "O")))
    {
        (*yCoordinateG3)--;
        move++;
        map[*xCoordinateG3][*yCoordinateG3] = "8";
        map[*xCoordinateG3][*(yCoordinateG3) + 1] = " ";
    }
}

int main()
{
    int xCoordinatePac, yCoordinatePac, xCoordinateG1, yCoordinateG1, xCoordinateG2, yCoordinateG2, xCoordinateG3, yCoordinateG3;
    srand(time(NULL));
    designMap();
    spawn(&xCoordinatePac, &yCoordinatePac, &xCoordinateG1, &yCoordinateG1, &xCoordinateG2, &yCoordinateG2, &xCoordinateG3, &yCoordinateG3);

    while (noOfPallets)
    {
        draw(&xCoordinatePac, &yCoordinatePac);
        move(&xCoordinatePac, &yCoordinatePac);
        ghostMovement(&xCoordinatePac, &yCoordinatePac, &xCoordinateG1, &yCoordinateG1, &xCoordinateG2, &yCoordinateG2, &xCoordinateG3, &yCoordinateG3);
    }

    if (finish)
    {
        cout << "\n\nScore: " << score << endl;
        cout << "\nYou Win!";
    }
    else
    {
        cout << "\n\nScore: " << score << endl;
        cout << "\nYou Lose!";
    }
}

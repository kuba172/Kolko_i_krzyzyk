#include <iostream>
#include <vector>

using namespace std;

void draw_field(vector<char>& matrix)
{
    cout << "|" << matrix.at(0) << "|" << matrix.at(1) << "|" << matrix.at(2) <<"|" << endl;
    cout << "|" << matrix.at(3) << "|" << matrix.at(4) << "|" << matrix.at(5) << "|" << endl;
    cout << "|" << matrix.at(6) << "|" << matrix.at(7) << "|" << matrix.at(8) << "|" << endl;
}

char winner(vector<char>& matrix)
{
    
        if (matrix.at(0) == 'X' and matrix.at(1) == 'X' and matrix.at(2) == 'X') return 'X';
        if (matrix.at(3) == 'X' and matrix.at(4) == 'X' and matrix.at(5) == 'X') return 'X';
        if (matrix.at(6) == 'X' and matrix.at(7) == 'X' and matrix.at(8) == 'X') return 'X';
        if (matrix.at(0) == 'X' and matrix.at(3) == 'X' and matrix.at(6) == 'X') return 'X';
        if (matrix.at(1) == 'X' and matrix.at(4) == 'X' and matrix.at(7) == 'X') return 'X';
        if (matrix.at(2) == 'X' and matrix.at(5) == 'X' and matrix.at(8) == 'X') return 'X';
        if (matrix.at(0) == 'X' and matrix.at(4) == 'X' and matrix.at(8) == 'X') return 'X';
        if (matrix.at(2) == 'X' and matrix.at(4) == 'X' and matrix.at(6) == 'X') return 'X';

        if (matrix.at(0) == 'O' and matrix.at(1) == 'O' and matrix.at(2) == 'O') return 'O';
        if (matrix.at(3) == 'O' and matrix.at(4) == 'O' and matrix.at(5) == 'O') return 'O';
        if (matrix.at(6) == 'O' and matrix.at(7) == 'O' and matrix.at(8) == 'O') return 'O';
        if (matrix.at(0) == 'O' and matrix.at(3) == 'O' and matrix.at(6) == 'O') return 'O';
        if (matrix.at(1) == 'O' and matrix.at(4) == 'O' and matrix.at(7) == 'O') return 'O';
        if (matrix.at(2) == 'O' and matrix.at(5) == 'O' and matrix.at(8) == 'O') return 'O';
        if (matrix.at(0) == 'O' and matrix.at(4) == 'O' and matrix.at(8) == 'O') return 'O';
        if (matrix.at(2) == 'O' and matrix.at(4) == 'O' and matrix.at(6) == 'O') return 'O';

        return ' ';
}


int main()
{
    vector<char> matrix = { '1','2','3','4','5','6','7','8','9' };
    const char player[2] = { 'X','O' };
    const int max_number_of_move = 9;
    int move;


   
    int i = 0;
    for (int j = 0; j <= max_number_of_move;j++)
        {
         cout << "Witaj w grze kolko i krzyzyk dla dwoch graczy!" << endl;
         draw_field(matrix);
         cout << "Ruch gracza " << player[i] << " (1 - 9):" << endl;
         cin >> move;
         if (move < 1 or move > 9)
            {
              system("cls");
              continue;
            }

         if (matrix.at(move - 1) != 'X' and matrix.at(move - 1) != 'O')
         {
             matrix.at(move - 1) = player[i];

         }
         else
         {
             j--;
             if (i == 1)i = 0;
             else i = 1;
         }
             
          

          if (winner(matrix) == 'X')
          {
              system("cls");
              draw_field(matrix);
              cout << "Wygral gracz X!" << endl;
              break;
          }

          if (winner(matrix) == 'O')
          {
              system("cls");
              draw_field(matrix);
              cout << "Wygral gracz O!" << endl;
              break;
          }

          if (j == 8)
          {
              system("cls");
              draw_field(matrix);
              cout << "Remis!" << endl;
              break;
          }

          if (player[i] == 'X')
          {
              i++;
              system("cls");
              continue;
          }
              
          if (player[i] == 'O')
          {
              i--;
              system("cls");
              continue;
          }
        }
}



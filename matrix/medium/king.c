/**
*               # 1222. Queens that can attack the king
*
*           On an 8x8 chessboard, there can be multiple Black
*           Queens and one White King.
*
*           Given an array of integer coordinates queens that
*           represents the positions of the Black Queens, and
*           a pair of coordinates king that represent the posi
*           tion of the White King, return the coordinates of
*           all the queens (in any order) that can attack the
*           King
*/


// Check if a pair of coordinates is safe
unsigned int is_safe(int x, int y)
{
    return (x >= 0 && x < 8) && (y >= 0 && y < 8);
}


// Pretend the king is a queen and simulates queen movements, stopping at
// the first queen founded in each direction
int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes){


    int hash[64] = {0};
    int **ret = calloc(sizeof(int*), queensSize);


    for (int i = 0; i < queensSize; i++)
    {
       hash[queens[i][0] + (queens[i][1] * 8)] = 1;
    }

    *returnColumnSizes = calloc(sizeof(int), queensSize);


    int count= 0;

    // Go from left to right
    for (int dx = -1; dx < 2; dx++)
    {
        // From bottom to up
        for (int dy = -1; dy < 2; dy++)
        {
            int i, j;
            if (dx == 0 && dy == 0) continue;
           for (i = king[0], j = king[1]; is_safe(i, j); i+=dx, j += dy)
           {
               if (hash[i + (j * 8)])
               {
                   int* queen = calloc(sizeof(int), 2);
                   queen[0] = i;
                   queen[1] = j;
                   ret[count] = queen;
                   count++;
                   break;
               }
           }
        }
    }

    for (int i = 0; i < count; i++)
    {

       (*returnColumnSizes)[i] = 2;
    }
    *returnSize = count;

    return ret;

}

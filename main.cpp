#include <QCoreApplication>

#include "MatchTwins.cpp"
#include "SortArrayWithBits.cpp"
#include "TicTacToeGame.cpp"


void testFunc();
void testFunc2();
int solution(vector<int>& A, int K);

int main(int argc, char *argv[])
{
    /* Read input from STDIN. Print output to STDOUT */

    //testMain();
    //test_rearrange();
    //testFunc();
    main_game();

//    vector<int> vect  {1, 1, 3, 3, 3, 4, 5, 5, 5, 5};           // 6
//    vector<int> vect2 {1, 1, 3, 3, 3, 3, 4, 5, 5, 5, 8};        // 7
//    vector<int> vect3 {1, 1, 3, 3, 3, 3, 4, 5, 8, 8, 8};        //
//    vector<int> vect4 {1, 1, 3, 3, 3, 3, 4, 5, 8, 9, 9};
//    vector<int> vect5 {1, 1, 3, 3, 3, 4, 4, 4, 8, 9};

    //int result = solution(vect5, 2);
    return 0;
}

int solution(vector<int>& A, int K)
{
    int n = A.size();
    int best = 0;
    int count = 1;

    for (int i = 0; i < n - K - 1; i++) {
        if (A[i] == A[i + 1])
            count = count + 1;
        else
            count = 1;

        best = max(best, count);
    }
    int result = best + K;
    return result;
}

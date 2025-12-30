using System.Text;

namespace Study;

public class baekjoon16967_2
{
    static int H, W, X, Y;
    static int[,] A, B;

    static void Main()
    {
        var input = Console.ReadLine().Split();
        H = int.Parse(input[0]);
        W = int.Parse(input[1]);
        X = int.Parse(input[2]);
        Y = int.Parse(input[3]);

        A = new int[H, W];
        B = new int[H + X, W + Y];

        SetMatrixB();
        FindMatrixA();
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                sb.Append(A[i, j]).Append(' ');
            }
            sb.AppendLine();
        }

        Console.Write(sb.ToString());
    }

    static void SetMatrixB()
    {
        for (int i = 0; i < H + X; i++)
        {
            var row = Console.ReadLine().Split();
            for (int j = 0; j < W; j++)
            {
                B[i, j] = int.Parse(row[j]);
            }
        }
    }

    static void FindMatrixA()
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                int value = 0;
                
                if (InMatrixA(i, j))
                {
                    value = B[i, j];
                    SetMatrixA(i, j, value);
                }
                else
                {
                    value = B[i, j] - A[i - X, j - Y];
                    SetMatrixA(i,j, value);
                }
            }
        }
    }

    static bool InMatrixA(int i, int j) => i < X || j < Y;

    static void SetMatrixA(int i, int j, int value) => A[i, j] = value;
}
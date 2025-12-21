using System;
using System.Text;

class Program
{
    static void Main()
    {
        int T = int.Parse(Console.ReadLine());
        StringBuilder sb = new StringBuilder();

        for (int t = 0; t < T; t++)
        {
            var first = Console.ReadLine().Split();
            int N = int.Parse(first[0]);
            long D = long.Parse(first[1]);

            int count = 0;

            for (int i = 0; i < N; i++)
            {
                var input = Console.ReadLine().Split();
                long v = long.Parse(input[0]);
                long f = long.Parse(input[1]);
                long c = long.Parse(input[2]);

                // f / c >= D / v  →  f * v >= D * c
                if (f * v >= D * c)
                {
                    count++;
                }
            }

            sb.AppendLine(count.ToString());
        }

        Console.Write(sb.ToString());
    }
}

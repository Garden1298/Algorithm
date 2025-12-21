using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int K = int.Parse(Console.ReadLine());
        Stack<int> stack = new Stack<int>();

        for (int i = 0; i < K; i++)
        {
            int num = int.Parse(Console.ReadLine());

            if (num == 0)
            {
                stack.Pop();
            }
            else
            {
                stack.Push(num);
            }
        }

        long sum = 0;
        foreach (int n in stack)
        {
            sum += n;
        }

        Console.WriteLine(sum);
    }
}

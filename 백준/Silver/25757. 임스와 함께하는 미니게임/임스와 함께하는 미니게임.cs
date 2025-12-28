using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        char game = input[1][0];

        HashSet<string> people = new HashSet<string>();

        for (int i = 0; i < N; i++)
        {
            people.Add(Console.ReadLine());
        }

        int need;
        if (game == 'Y') need = 1;
        else if (game == 'F') need = 2;
        else need = 3; // O

        Console.WriteLine(people.Count / need);
    }
}

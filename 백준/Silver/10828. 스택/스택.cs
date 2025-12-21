using System;
using System.Collections.Generic;
using System.Text;

public class baekjoon10828
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        Stack<int> stack = new Stack<int>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++)
        {
            string input = Console.ReadLine();
            string[] cmd = input.Split(' ');

            switch (cmd[0])
            {
                case "push":
                    stack.Push(int.Parse(cmd[1]));
                    break;
                case "pop":
                    sb.AppendLine(stack.Count == 0 ? "-1" : stack.Pop().ToString());
                    break;
                case "size":
                    sb.AppendLine(stack.Count.ToString());
                    break;
                case "empty":
                    sb.AppendLine(stack.Count == 0 ? "1" : "0");
                    break;
                case "top":
                    if (stack.Count == 0)
                    {
                        sb.AppendLine("-1");
                    }
                    else
                    {
                        sb.AppendLine(stack.Peek().ToString());
                    }
                    break;
            }
        }
        
        Console.WriteLine(sb.ToString());
    }
}
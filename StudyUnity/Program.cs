using System;

namespace StudyUnity
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num = { 1,2,3,4,5,6,7,8,9 };

            foreach (int number in num)
            {
                Console.WriteLine($"3 * {number} = {number * 3}");
            }


            Console.WriteLine("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

            for (int i = 1; i < num.Length+1; i++)
            {
                Console.WriteLine($"3 * {i} = {i * 3}");
            }
        }
    }
}
using System;

namespace StudyUnity
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

            foreach (var number in numbers) {
                Console.WriteLine(number);
            }

            Console.WriteLine("======================");

            Array.Clear(numbers, 2, 3);

            foreach (var number in numbers) {
                Console.WriteLine(number);
            }
        }
    }
}
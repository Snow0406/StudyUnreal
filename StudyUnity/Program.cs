using System;

namespace StudyUnity
{
    public static class ExtensionMethodClass
    {
        public static string toSnow(this object input)
        {
            return "스노우 히히";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int num1 = 10;
            int num2 = 20;
            object num3 = 30;

            Set(num1, num2);
            Console.WriteLine(num3.toSnow());
        }

        static void Set(int a = 1, int b = 2)
        {
            Console.WriteLine(a + b);
        }
    }
}
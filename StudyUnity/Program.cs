using System;

namespace ConsoleApp1
{
    class MyClass
    {
        public int num;
    }

    struct MyStruct
    {
        public int num;
    }

    class Program
    {
        static void Main(string[] args)
        {
            MyStruct a = new MyStruct();
            MyStruct b = a;
            a.num = 10;

            Console.WriteLine(b.num);

        }
    }
}
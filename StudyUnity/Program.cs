using System;

namespace Snow
{
    class Program
    {
        private delegate void Yuki(int num);
        static void A(int num) { Console.WriteLine($"A : {num}"); }
        static void B(int num) { Console.WriteLine($"B : {num}"); }

        static void Main()
        {
            Yuki yuki = new Yuki(A);
            yuki(123);
            yuki = B;
            yuki(456);
        }
    }
}
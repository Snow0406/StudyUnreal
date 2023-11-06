using System;
using System.Threading; // 사용

namespace Snow
{
    class Program
    {
        static int num = 0;

        static object lockObj = new object();
        static void Main()
        {
            Thread add = new Thread(Add);
            add.Name = "추가";
            add.Start();
            Thread sub = new Thread(Sub);
            sub.Name = "감소";
            sub.Start();

            add.Join();
            sub.Join();

            Console.WriteLine(num);
        }
        static void Sub()
        {
            for (int i = 0; i < 100000; i++) {
                Interlocked.Decrement(ref num);
            }
        }

        static void Add()
        {
            for (int i = 0; i < 100000; i++) {
                Interlocked.Increment(ref num);
            }
        }
    }
}
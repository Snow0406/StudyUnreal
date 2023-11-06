using System;
using System.Threading; // 사용

namespace Snow
{
    class Program
    {
        //static int num = 0;

       // static object lockObj = new object();
        static void Main()
        {


            for (int i = 0; i < 10; i++) {
                Task task = new Task(() => {

                    Console.WriteLine("Orders received!~");
                    Thread.Sleep(1000);
                    Console.WriteLine("Job finished!");

                });
                task.Start();
            }


            Thread.Sleep(2000);
            Console.WriteLine("Build Succeed");
            while (true) { }

        }
    }
}
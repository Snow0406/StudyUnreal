using System;
using System.Collections;
using System.Linq;

namespace Snow
{
    class Program
    {
        static void Main()
        {
            List<int> list = new List<int>();
            while (true) {
                string? s = Console.ReadLine();
                if (s == "0") {
                    var linqData = from data in list where data % 3 == 0 orderby data ascending select data;
                    Console.WriteLine("=========================");
                    foreach (var data in linqData) {
                        Console.WriteLine(data);
                    }
                    break;
                } else {
                    list.Add(int.Parse(s));
                }
            }

        }
    }
}
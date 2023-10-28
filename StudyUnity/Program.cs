using System;
using System.Collections;

namespace StudyUnity
{
    
    class Snow
    {
        static void Main()
        {
            Queue<int> Queue = new Queue<int>();
            Queue.Enqueue(1);
            Queue.Enqueue(2);
            Queue.Enqueue(3);
            Queue.Enqueue(4);

            Console.WriteLine($"Count : {Queue.Count}");

            Queue.Clear();

            Console.WriteLine($"Count : {Queue.Count}");
        }
    }
}
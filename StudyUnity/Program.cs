using System;
using System.Collections;

namespace StudyUnity
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable hashtable = new Hashtable();
            hashtable.Add("name", "snow");
            hashtable.Add("age", 18);

            foreach (string key in hashtable.Keys) {
                Console.WriteLine(key);
            }
        }
    }
}
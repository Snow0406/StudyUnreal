using System;

namespace StudyUnity
{
    class Animal
    { }

    class Cat : Animal
    {
        public void Test()
        {
            Console.WriteLine("hello");
        }

    }

    class Program
    {
        static void Test<T>(Animal p) where T : Animal
        {
            T cat = (T)p;
        }
        static void Main(string[] args)
        {
            Animal animal = new Cat();
            if (animal is Cat a) {
                Cat cat = (Cat)a;
            }
            if (animal is Cat) {
                Cat cat = (Cat)animal;
                Console.WriteLine("Right");
            } else {
                Console.WriteLine("False");
            }
        }
    }
}
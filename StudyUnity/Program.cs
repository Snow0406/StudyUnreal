using System;

namespace Snow
{
    class Program
    {
        class Snow {
            float playerX = 10;
            float playerY = 20;
            public float Distance { get => MathF.Abs(playerX - playerY); }
        }

        public delegate void Yuki();
        static Yuki yuki;
        static void Main()
        {
            //yuki = delegate () { Console.WriteLine("asdf"); };
            //yuki();
            //
            //yuki = () => { Console.WriteLine("Lamda Yuki"); };
            //yuki();

            Snow snow = new Snow();
            Console.WriteLine(snow.Distance); 
        }
    }
}
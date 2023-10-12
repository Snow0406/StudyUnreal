using System;

namespace StudyUnity
{
    interface IToolManager
    {
        void Manage();
    }
    interface ITool : IToolManager
    {
        void UseTool();
    }

    abstract class Player
    {
        public string name;
        public int id;

        public float hp;
        public float mp;

        abstract public void Move();
    }

    class Action : Player
    {
        public override void Move()
        {
            throw new NotImplementedException();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            
        }
    }
}
using System;
using System.Collections;

namespace StudyUnity
{
    interface IA
    {
    }
    class B : IA
    {
    }
    class C
    {
    }

    class QQQ<T> where T : IA
    {
        public T Return(T a)
        {
            return a;
        }
    }

    class Start
    {
        static void Main()
        {
            QQQ<B> bQQ = new QQQ<B>();
            QQQ<C> cQQ = new QQQ<C>(); // 에러

        }
    }
}
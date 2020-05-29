using System;
namespace SimpleEvent
{
    using System;
    /***********发布器类***********/
    public class EventTest
    {
        private int x = 1;

        public delegate void EventHandler(ref int x);
        public event EventHandler CastTriger;

        public virtual void Cast()
        {
            if (CastTriger != null)
            {
                CastTriger(ref x); /* 事件被触发 */
                Console.WriteLine(x);
            }
            else
            {
                Console.WriteLine("event not fire");
            }
        }
    }


    /***********订阅器类***********/

    public class SubscribEvent
    {
        private int x;
        public void SetX(int x)
        {
            this.x = x;
        }

        public void printf(ref int n)
        {
            n *= 9;
            Console.WriteLine(x + "event fire");
        }
    }

    /***********触发***********/
    public class MainClass
    {
        public static void Main()
        {
            EventTest e = new EventTest(); /* 实例化对象,第一次没有触发事件 */
            SubscribEvent v = new SubscribEvent(); /* 实例化对象 */
            v.SetX(1);
            e.CastTriger += new EventTest.EventHandler(v.printf); /* 注册 */
            e.CastTriger += new EventTest.EventHandler(v.printf); /* 注册 */
            SubscribEvent v2 = new SubscribEvent(); /* 实例化对象 */
            v2.SetX(2);
            e.CastTriger += new EventTest.EventHandler(v2.printf); /* 注册 */

            e.Cast();

            e.CastTriger -= new EventTest.EventHandler(v.printf); /* 注册 */
            e.Cast();

            Console.ReadKey();
        }
    }
}
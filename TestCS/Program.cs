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
            CastTriger?.Invoke(ref x); /* 事件被触发 */
        }
    }

    struct TestStruct
    {
        public int[] val;
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
            TestStruct a = new TestStruct();
            Console.WriteLine(a.val[0]);

            Console.ReadKey();
        }




        void testEvent()
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
        }



    }
}
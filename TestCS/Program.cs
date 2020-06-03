using System;
using System.Collections.Generic;
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

    public class Attribute
    {
        public readonly static Dictionary<string, int> index = InitDictionary();
        private static Dictionary<string, int> InitDictionary()
        {
            Dictionary<string, int> dictionary = new Dictionary<string, int>();
            List<string> attriList = new List<string> { "hpMaxBase" , "mpMaxBase", "hpRegBase", "mpRegBase",
                "conBase", "strBase", "dexBase", "itgBase", "defBase", "resBase", "hpMaxPct", "mpMaxPct",
                "hpRegPct", "mpRegPct", "conPct", "strPct", "dexPct", "itgPct", "defPct", "resPct",
                "deArmor", "deRes", "deArmorPct", "deResPct", "crt", "crtDmg", "acc", "eva", "accPct", "evaPct",
                "stealLife", "stealMana", "physDmgRdc", "magicDmgRdc", "dmgRdc", "dmgPhysics", "dmgMagic",
                "dmgPure", "dmgFire", "dmgWater", "dmgWind", "dmgEarth", "dmgLight", "dmgDark", "dmgThunder" };
            int size = attriList.Count;
            for (int i = 0; i < size; ++i)
            {
                dictionary.Add(attriList[i], i);
            }
            return dictionary;
        }

        public int[] val = new int[45];
    }

    /***********触发***********/
    public class MainClass
    {
        public static void Main()
        {
            int x;
            if (Attribute.index.ContainsKey("aaa"))
                x = Attribute.index["aaa"];


            foreach (KeyValuePair<string, int> kvp in Attribute.index)
            {
                Console.WriteLine("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            }

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
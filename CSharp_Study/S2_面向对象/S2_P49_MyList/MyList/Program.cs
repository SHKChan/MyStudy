using System;
using System.Collections;
using System.Collections.Generic;

namespace MyList
{
    class Program
    {
        static void Main(string[] args)
        {
            MyList<int> ls = new MyList<int>() { 5,4,3,2,1 };
            ls.Add(-1);
            ls.Insert(1, 6);
            ls.Insert(1, 8);
            ls.Sort();
            Console.WriteLine("ShowList: ");
            ShowList(ls);
            Console.WriteLine();
            Console.WriteLine("ls[7] = " + ls[7]);
            Console.ReadLine();
        }

        static void ShowList(MyList<int> ls)
        {
            foreach(int item in ls)
            {
                Console.WriteLine(item);
            }

        }
    }

    //利用数组实现的泛型列表类
    class MyList<T> : IEnumerable<T>
    {
        private T[] ls;
        
        public int Count { get; private set; }
        public int Capacity { get; private set; }

        private void Initialize()
        {
            this.Count = 0;
            this.ls = new T[this.Capacity];
        }

        //无参构造
        public MyList()
        {
            this.Capacity = 4;
            Initialize();
        }

        //指定容量构造
        public MyList(int capacity)
        {
            this.Capacity = capacity;
            Initialize();
        }

        //增加元素
        public void Add(T item)
        {
            if (this.Count < this.Capacity)
            {
                ls[this.Count++] = item;
            }
            else
            {
                this.Capacity *= 2;
                T[] lsNew = new T[this.Capacity];
                for (int i = 0; i < this.Count; i++)
                {
                    lsNew[i] = ls[i];
                }
                lsNew[this.Count++] = item;
                this.ls = lsNew;
            }
        }

        //插入元素至
        public void Insert(int index, T item)
        {
            if (index < 0 || index > this.Count)
            {
                throw new ArgumentOutOfRangeException();
            }

            if (index == this.Count)
            {
                this.Add(item);
                return;
            }

            T[] lsNew = new T[this.Capacity];
            for (int i = 0; i < this.Count; i++)
            {
                if (index > i)
                {
                    lsNew[i] = this.ls[i];
                }
                else if (index == i)
                {
                    lsNew[i] = item;
                    lsNew[i+1] = this.ls[i];
                }
                else
                {
                    lsNew[i+1] = this.ls[i]; 
                }
            }
            this.ls = lsNew;
            this.Count++;
        }
        
        //索引器
        public T this[int index]
        {
            get
            {

                if (index < 0 || index > this.Count - 1)
                {
                    throw new ArgumentOutOfRangeException();
                }
                return this.ls[index];
            }
            set
            {

                if (index < 0 || index > this.Count - 1)
                {
                    throw new ArgumentOutOfRangeException();
                }
                this.ls[index] = value;
            }
        }

        //移除指定位置元素
        public void RemoveAt(int index)
        {
            if (index < 0 || index > this.Count -1)
            {
                throw new ArgumentOutOfRangeException();
            }
            T[] lsNew = new T[this.Capacity];
            for (int i = 0; i < this.Count; i++)
            {
                if (index > i)
                {
                    lsNew[i] = this.ls[i];
                }
                else if (index == i)
                {
                    continue;
                }
                else
                {
                    lsNew[i-1] = this.ls[i];
                }
            }
            this.ls = lsNew;
            this.Count--;
        }

        //匹配到的第一个元素的索引
        public int IndexOf(T item)
        {
            for (int i = 0; i < this.Count; i++)
            {
                T var1 = item;
                T var2 = this.ls[i];
                if (var1.Equals(var2))
                //if (var1 == var2)
                {
                    return i;
                }
            }
            return -1;
        }

        //匹配到的最后一个元素的索引
        public int LastIndexOf(T item)
        {
            for (int i = this.Count; i > 0; i--)
            {
                dynamic var1 = item;
                dynamic var2 = this.ls[i];
                if (var1.Equals(var2))
                //if (var1 == var2)
                {
                    return i;
                }
            }
            return -1;
        }

        //从小到大排序
        public void Sort()
        {
            for (int i = 0; i < this.Count; i++)
            {
                dynamic item = this.ls[i];
                for (int j = i+1; j < this.Count; j++)
                {
                    dynamic var = this.ls[j];
                    if (var < item)
                    {
                        this.ls[i] = var;
                        this.ls[j] = item;
                        item = this.ls[i];
                    }
                }
            }
        }

        //提供迭代接口
        //继承IEnumerable<T>需要实现的接口
        public IEnumerator<T> GetEnumerator()
        {
            return new MyEnumerator(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this.GetEnumerator();
        }

        //真正的迭代器
        //继承IEnumerator<T>实现接口
        class MyEnumerator : IEnumerator<T>
        {
            private int index = -1;
            private MyList<T> myList;
            object IEnumerator.Current => Current;

            public T Current
            {
                get
                {
                    if (index < 0 || index >= myList.Count)
                    {
                        return default(T);
                    }
                    return myList.ls[index];
                }
            }

            public MyEnumerator(MyList<T> ls)
            {
                this.myList = ls;
            }

            public void Dispose() { }

            public bool MoveNext()
            {
                return ++index < myList.Count;
            }

            public void Reset()
            {
                index = -1;
            }

        }

    }
}

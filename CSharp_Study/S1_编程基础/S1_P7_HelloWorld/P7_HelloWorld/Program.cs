using System; //引入命名空间

//定义命名空间
namespace P7_HelloWorld
{
    //定义类,类注释另起一行
    class Program
    {
        //定义程序的入口方法,写法固定,方法注释另起一行
        static void Main(string[] args)
        {
            int a = 10;
            string str = "Test";
            byte bt = 200;
            Console.WriteLine("Hello World!");

            Console.WriteLine("");
            Console.WriteLine("1\n\t2\n3");

            Console.WriteLine("");
            Console.WriteLine("   *");
            Console.WriteLine("  ***");
            Console.WriteLine(" *****");
            Console.WriteLine("*******");
            Console.WriteLine("   *");
            Console.WriteLine("   *");
            Console.WriteLine("   *");

            Console.WriteLine("");
            Console.WriteLine("\\\""); //转义\和转移"

            Console.WriteLine("");
            Console.WriteLine("SiKi说:\"what is \\n\""); //转义\和转移"

            Console.ReadKey();
        }
    }
}

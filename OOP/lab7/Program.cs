internal class Program
{
    public delegate void Del();
    static Del StaticDel = Method1; 
    private static void Main(string[] args)
    {
        Class1 cl1 = new();
        Class2 cl2 = new();

        Console.WriteLine(cl1.ObjectDel("abcde"));
        Console.WriteLine(Class1.StaticDel("abcde"));
        Console.WriteLine(cl2.ObjectDel("abcde"));

        cl1.ObjectDel += cl2.DeleteLastTwo;
        Console.WriteLine(cl1.ObjectDel("abcde"));

        StaticDel += Method2;
        StaticDel();

        cl1.Event += cl1.EventHandler2;
        cl1.DoEvent("abcde");
    }

    public static void Method1() {
        Console.WriteLine("Method 1");
    }

    public static void Method2() {
        Console.WriteLine("Method 2");
    }
}
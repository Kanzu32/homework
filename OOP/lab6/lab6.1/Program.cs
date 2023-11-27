internal class Program
{
    private static void Main(string[] args)
    {
        Class2 cl2 = new Class2("abcdefg");
        cl2.F0();
        Console.WriteLine(cl2.Str);
        (cl2 as Iy).F1("123456");
        Console.WriteLine(cl2.Str);
        Ix x_cl2 = cl2;
        x_cl2.F1("123456");
        Console.WriteLine(cl2.Str);

        Class1 cl1 = new Class1("abcdefg");
        cl1.F0();
        Console.WriteLine(cl1.Str);
        (cl1 as Iy).F1("123456");
        Console.WriteLine(cl1.Str);
        Ix x_cl1 = cl1;
        x_cl1.F1("123456");
        Console.WriteLine(cl1.Str);
    }
}
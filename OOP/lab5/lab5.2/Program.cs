internal class Program
{
    private static void Main(string[] args)
    {
        Arithmetic a = new(1, 1);
        Geometric g = new(2, 2);
        Console.WriteLine(a.Sum(5));
        Console.WriteLine(g.Sum(3));
    }
}
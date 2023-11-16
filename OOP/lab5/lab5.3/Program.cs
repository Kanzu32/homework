internal class Program
{
    private static void Main(string[] args)
    {
        Signal s1 = new("s1 content");
        Auxiliary a1 = new("a1 content");
        Result r1 = new("r1 content");
        s1.Process();
        s1.Save();
        a1.Save();
        r1.Save();
        Data.PrintSaved();
    }
}
internal class Program
{
    private static void Main(string[] args)
    {
        Detail d1 = new Detail("D1");
        Mechanism m1 = new Mechanism("M1");
        Node n1 = new Node("N1");
        Node n2 = new Node("N2");
        d1.Add();
        m1.Add();
        n1.Add();
        n2.Add();
        Product.Print();
    }
}
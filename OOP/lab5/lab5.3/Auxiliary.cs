class Auxiliary : Data {
    public Auxiliary(string content) : base(content) {}
    override public void Print() {
        Console.Write("AUXILIARY: ");
        base.Print();
    }
}
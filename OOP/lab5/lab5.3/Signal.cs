class Signal : Data {
    public Signal(string content) : base(content) {}
    override public void Print() {
        Console.Write("SIGNAL: ");
        base.Print();
    }
}
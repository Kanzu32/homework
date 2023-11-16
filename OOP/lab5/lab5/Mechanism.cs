class Mechanism : Product {
    public Mechanism(string name) : base(name) {}
    override public void Show() {
        Console.WriteLine("Mechanism: " + name);
    }
}
class Detail : Product {
    public Detail(string name) : base(name) {}
    override public void Show() {
        Console.WriteLine("Detail: " + name);
    }
}
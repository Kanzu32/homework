class Result : Data {
    public Result(string content) : base(content) {}
    override public void Print() {
        Console.Write("RESULT: ");
        base.Print();
    }
}
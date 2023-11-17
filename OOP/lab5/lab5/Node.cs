class Node : Product {
    public Node(string name) : base(name) {}
    override public void Show() {
        Console.WriteLine("Node: " + name);
    }
}
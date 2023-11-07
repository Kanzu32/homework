class Publication {
    protected string name;
    protected double price;

    public Publication(string name, double price) {
        this.name = name;
        this.price = price;
    }

    public string Name {
        get {
            return this.name;
        }
    }

    public double Price {
        get {
            return this.price;
        }
    }

    public override string ToString() {
        return $"{name}, Book, {price}";
    }
}
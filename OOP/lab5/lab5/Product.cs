abstract class Product {
    protected string name;
    static private List<Product> list = new List<Product>(); 
    public Product(string name) {
        this.name = name ?? " ";
    }

    public void Add() {
        list.Add(this);
    }

    public virtual void Show() {
        Console.WriteLine(name);
    }

    public static void Print() {
        foreach (var item in list){
            item.Show();
        }
    }
}
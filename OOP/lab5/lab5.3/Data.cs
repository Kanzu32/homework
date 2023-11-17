abstract class Data {
    protected string content;
    protected bool isProcessed;
    static private List<Data> list = new List<Data>(); 

    public Data(string content) {
        this.content = content;
    }

    public virtual void Print() {
        Console.WriteLine(content + ", is processed: " + isProcessed);
    }

    public virtual void Save() {
        Data.list.Add(this);
    }

    public virtual void Process() {
        isProcessed = true;
    }

    public static void PrintSaved() {
        foreach (var item in list){
            item.Print();
        }
    }
}
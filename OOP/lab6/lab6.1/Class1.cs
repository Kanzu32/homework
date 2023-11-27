class Class1: Iy, Ix {
    private string str = "";

    public Class1(string str)
    {
        this.str = str;
    }

    public string Str
    {
        get {return str;}
        private set {}
    }

    public void F0() {
        if (str.Length > 2)
        {
            str = str.Substring(2);
        }
        else
        {
            str = "";
        }
    }

    public void F0(string p)
    {
        if (p.Length > 2)
        {
            str = p.Substring(2);
        }
        else
        {
            str = "";
        }
    }

    void Iy.F1(string p)
    {
        if (str.Length > 0)
        {
            str = string.Concat("-", str.Substring(1));
        }
        else
        {
            str = "-";
        }
    }

    public void F1(string p)
    {
        if (p.Length > 2)
        {
            str = p.Substring(2);
        }
        else
        {
            str = "";
        }
    }
}
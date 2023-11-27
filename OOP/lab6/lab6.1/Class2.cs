class Class2: Ix, Iy{
    private string str = "";

    public Class2(string str)
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
            str = str.Substring(0, str.Length-2);
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
            str = p.Substring(0, p.Length-2);
        }
        else
        {
            str = "";
        }
    }

    public void F1(string p)
    {
        if (p.Length > 2)
        {
            str = p.Substring(0, p.Length-2);
        }
        else
        {
            str = "";
        }
    }
}
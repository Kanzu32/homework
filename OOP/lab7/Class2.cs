class Class2
{
    public Del ObjectDel;
    public delegate string Del(string s);
    public Class2() {
        ObjectDel = DeleteLastTwo;
    }

    public string DeleteLastTwo(string s)
    {
        return s[0..^2];
    }
}
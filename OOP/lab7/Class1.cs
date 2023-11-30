using System.IO.Compression;

class Class1
{
    public static Del StaticDel = DeleteFirstTwo;
    public Del ObjectDel;
    public VoidDel EventDel;
    public delegate string Del(string s);
    public delegate void VoidDel(string s);
    public event VoidDel Event;
    public Class1() {
        ObjectDel = ChangeFirst;
        EventDel = EventHandler1;
        Event = EventDel;
    }

    public static string DeleteFirstTwo(string s)
    {
        return s[2..];
    }

    public string ChangeFirst(string s)
    {
        return "_"+s[1..];
    }

    public void EventHandler1(string s)
    {
        Console.WriteLine("Handler 1: " + DeleteFirstTwo(s));
    }

    public void EventHandler2(string s)
    {
        Console.WriteLine("Handler 2: " + ChangeFirst(s));
    }

    public void DoEvent(string s)
    {
        Event.Invoke(s);
    }
}
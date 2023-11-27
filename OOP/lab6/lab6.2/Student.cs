using System.Collections;
using System.Diagnostics.Contracts;

class Student : IComparable, IComparer {
    readonly string firstName;
    readonly string middleName;
    readonly string lastName;
    readonly int group; 
    List<Exam> exams;
    
    public Student(string firstName, string middleName, string lastName, int group, List<Exam> exams)
    {
        this.firstName = firstName;
        this.middleName = middleName;
        this.lastName = lastName;
        this.group = group;
        this.exams = exams;
    }

    public int Compare(object? a, object? b)
    {
        if (a is not null && b is not null && a is Student st1 && b is Student st2)
        {
            return st1.group.CompareTo(st2.group);
        }
        throw new ArgumentException("ArgumentException");
    }

    public int CompareTo(object? b)
    {
        if (b is not null && b is Student another)
        {
            return this.group.CompareTo(another.group);
        }
        throw new ArgumentException("ArgumentException");
    }

    public void Print()
    {
        Console.Write(firstName + " " + middleName + " " + lastName + ", Group: " + group);

        foreach (Exam exam in exams)
        {
            Console.Write(" " + exam.name + ": " + exam.grade);
        }

        Console.Write("\n");
    }

    public bool IsExamed()
    {
        if (exams.Count >= 3)
        {
            foreach (Exam exam in exams)
            {
                if (exam.grade <= 2) return false;
            }
            return true;
        }
        return false;
    }

    public static bool operator >  (Student operand1, Student operand2)
    {
       return operand1.CompareTo(operand2) > 0;
    }

    public static bool operator <  (Student operand1, Student operand2)
    {
       return operand1.CompareTo(operand2) < 0;
    }

    public static bool operator >=  (Student operand1, Student operand2)
    {
       return operand1.CompareTo(operand2) >= 0;
    }

    public static bool operator <=  (Student operand1, Student operand2)
    {
       return operand1.CompareTo(operand2) <= 0;
    }
}
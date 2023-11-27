using System.Collections;

internal class Program
{
    private static ArrayList array = new ArrayList();
    private static void AddToArray(string firstName, string middleName, string lastName, int group, params Exam[] exams)
    {
        List<Exam> list = [.. exams];
        array.Add(new Student(firstName, middleName, lastName, group, list));
    }

    private static void Main(string[] args)
    {
        AddToArray("Ivan", "Ivanovich", "Ivanov", 100, new Exam("Subject 1", 4), new Exam("Subject 2", 5), new Exam("Subject 3", 5));
        AddToArray("Petr", "Petrovich", "Petrov", 100, new Exam("Subject 1", 4), new Exam("Subject 2", 5), new Exam("Subject 3", 5));
        AddToArray("Student", "1", "1", 110, new Exam("Subject 1", 2), new Exam("Subject 2", 5), new Exam("Subject 3", 5));
        AddToArray("Student", "2", "2", 112, new Exam("Subject 1", 4), new Exam("Subject 2", 5), new Exam("Subject 3", 5));
        AddToArray("Student", "3", "3", 100, new Exam("Subject 1", 4), new Exam("Subject 2", 5));
        AddToArray("Student", "4", "4", 110, new Exam("Subject 1", 3), new Exam("Subject 2", 3), new Exam("Subject 3", 3));
        AddToArray("Student", "5", "5", 220, new Exam("Subject 1", 5), new Exam("Subject 2", 5), new Exam("Subject 3", 5));

        ArrayList examed = new ArrayList();
        
        foreach (Student student in array)
        {
            if (student.IsExamed())
            {
                examed.Add(student);
            }
        }

        examed.Sort();

        foreach (Student student in examed)
        {
            student.Print();
        }
    }
}
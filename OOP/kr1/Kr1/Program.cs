using Kr1;

internal class Program
{
    private static void Main(string[] args)
    {

        Article article1 = new Article(new Person("A", "B", "C"),"title", 5.43);
		Article article2 = new Article(new Person("H", "N", "A"), "t", 2.3);
		Console.WriteLine(article1.CompareTo(article2));
		Console.WriteLine(new ArticleComparer().Compare(article1, article2));
		Console.WriteLine(article1.Compare(article1, article2));
	}

    
}


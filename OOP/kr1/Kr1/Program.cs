using Kr1;

internal class Program
{
    private static void Main(string[] args)
    {
		Console.WriteLine("Задание 1:\n");

		Person e1 = new Person("Иванов", "И");
		Person a1 = new Person("A", "AF");
		Person a2 = new Person("B", "BF");
		Person a3 = new Person("C", "CF");
		Magazine magazine = new Magazine("New magazine", Frequency.Weekly, DateTime.Now, 1000,
				[new Article(a2, "Aa", 8.9), new Article(a3, "Cc", 5), new Article(a1, "Bb", 4.6)], [e1]);
		
		Console.WriteLine(magazine.ToString());
		magazine.SortByTitle();
		Console.WriteLine(magazine.ToString());
		magazine.SortByAuthor();
		Console.WriteLine(magazine.ToString());
		magazine.SortByRating();
		Console.WriteLine(magazine.ToString());

		Console.WriteLine("Задание 2:\n");

		MagazineCollection<string> collection = new MagazineCollection<string>(magazine => magazine.Title);
		collection.AddDefaults();
		collection.AddMagazines(magazine);
		Console.WriteLine(collection.ToString());

		Console.WriteLine("Задание 3:\n");

		Console.WriteLine("MaxAverageRating: " + collection.MaxAverageRating + "\n");
		foreach (var entry in collection.FrequencyGroup(Frequency.Weekly))
		{
			Console.WriteLine(entry.Value.ToShortString()+"\n");
		}
		foreach (var group in collection.GroupByFrequency)
		{
			Console.WriteLine("Group " + group.Key + "\n");
			foreach (var entry in group)
			{
				Console.WriteLine(entry.Value.ToShortString());
			}
			Console.WriteLine("\n");
		}

		Console.WriteLine("Задание 4:\n");

		TestCollections<Edition, Magazine> test = new TestCollections<Edition, Magazine>(50000, TestCollections<Edition, Magazine>.GeneratePair);
		//foreach (var entry in test.KeyDictionary)
		//{
		//	Console.WriteLine(entry.Value.ToString());
		//}
		test.Test();
	}

    
}


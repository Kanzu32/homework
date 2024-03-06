namespace Kr1
{
	class Article : IComparable, IComparer<Article>
	{
		public Person Author { get; set; }
		public string Title { get; set; }
		public double Rating { get; set; }

		public Article(Person author, string title, double rating)
		{
			Author = author;
			Title = title;
			Rating = rating;
		}

		public Article()
		{
			Author = new Person();
			Title = "Untitled article";
			Rating = 0;
		}

		public override string ToString()
		{
			return $"Article: {Title}, {Author}, RAITING: {Rating:f2}";
		}

		public int CompareTo(object? obj) // by title
		{
			ArgumentNullException.ThrowIfNull(obj);
			if (obj is Article article) return Title.CompareTo(article.Title);
			else throw new ArgumentException("Unable to compare Article with non-article object.");
		}

		public int Compare(Article? x, Article? y) // by lastname
		{
			ArgumentNullException.ThrowIfNull(x);
			ArgumentNullException.ThrowIfNull(y);
			return x.Author.Lastname.CompareTo(y.Author.Lastname);
		}
	}
}
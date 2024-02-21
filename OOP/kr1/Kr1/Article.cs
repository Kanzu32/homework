namespace Kr1
{
	class Article
	{
		Person author;
		string title;
		double rating;
		public Article(Person author, string title, double rating)
		{
			this.author = author;
			this.title = title;
			this.rating = rating;
		}

		public Article()
		{
			this.author = new Person();
			this.title = "Unnamed book";
			this.rating = 0;
		}

		public override string ToString()
		{
			return $"{title}, {author} RAITING: {rating:f2}";
		}

		public Person Author { get => author; set => author = value; }
		public string Title { get => title; set => title = value; }
		public double Rating { get => rating; set => rating = value; }
	}
}
namespace Kr1
{
	class ArticleComparer : IComparer<Article>
	{
		public int Compare(Article? x, Article? y) // by rating
		{
			ArgumentNullException.ThrowIfNull(x);
			ArgumentNullException.ThrowIfNull(y);
			//return x.Rating.CompareTo(y.Rating); // по возрастанию
			return y.Rating.CompareTo(x.Rating);
		}
	}
}

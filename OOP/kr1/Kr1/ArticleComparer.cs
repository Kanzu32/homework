namespace Kr1
{
	class ArticleComparer : IComparer<Article>
	{
		public int Compare(Article? x, Article? y)
		{
			ArgumentNullException.ThrowIfNull(x);
			ArgumentNullException.ThrowIfNull(y);
			return x.Rating.CompareTo(y.Rating);
		}
	}
}

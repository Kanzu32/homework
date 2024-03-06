using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kr1
{
	class Magazine
	{
		public string Title { get => _title; set => _title = value; }
		private string _title;

		public Frequency Frequency { get => _frequency; set => _frequency = value; }
		private Frequency _frequency;

		public DateTime ReleaseDate { get => _releaseDate; set => _releaseDate = value; }
		private DateTime _releaseDate;

		public int Circulation { get => _circulation; set => _circulation = value; }
		private int _circulation;

		public Article[] Articles { get { return [.. _articles]; } set { _articles = [.. value]; } }
		public List<Article> ArticlesList { get { return [.. _articles]; } set { _articles = [.. value]; } }
		private Article[] _articles;

		public List<Person> Editors { get { return [.. _editors]; } set { _editors = [.. value]; } }
		private List<Person> _editors;

		public double AverageRating
		{
			get
			{
				if (Articles.Length == 0) return 0;
				double sum = 0;
				foreach (var Article in Articles)
				{
					sum += Article.Rating;
				}
				return sum / Articles.Length;
			}
		}

		public Magazine(string title, Frequency frequency, DateTime releaseDate, int circulation)
		{
			_title = title;
			_frequency = frequency;
			_releaseDate = releaseDate;
			_circulation = circulation;
			_articles = [];
			_editors = [];
		}

		public Magazine(string title, Frequency frequency, DateTime releaseDate, int circulation, Article[] articles) : this(title, frequency, releaseDate, circulation)
		{
			_articles = articles;
		}

		public Magazine(string title, Frequency frequency, DateTime releaseDate, int circulation, Article[] articles, Person[] editors) : this(title, frequency, releaseDate, circulation, articles)
		{
			_editors = [..editors];
		}

		public Magazine()
		{
			_title = "Untitled magazine";
			_frequency = new Frequency();
			_releaseDate = new DateTime();
			_circulation = 0;
			_articles = [];
			_editors = [];
		}

		public bool this[Frequency frequency]
		{
			get
			{
				if (Frequency == frequency) return true;
				return false;
			}
		}

		public void AddArticles(Article[] articles)
		{
			Articles = [.. Articles, .. articles];
		}

		public void SortByTitle()
		{
			Array.Sort(_articles, (article1, article2) => article1.CompareTo(article2));
		}

		public void SortByAuthor()
		{
			Array.Sort(_articles, (article1, article2) => article1.Compare(article1, article2));
		}

		public void SortByRating()
		{
			Array.Sort(_articles, new ArticleComparer());
		}

		public override string ToString()
		{
			string str = $"Magazine: title {Title}, freq {Frequency}, release {ReleaseDate}, circulation {Circulation}\n";
			foreach (var article in Articles) {
				str += article.ToString() + "\n";
			}

			return str;
		}

		public string ToShortString()
		{
			return $"Magazine: title {Title}, freq {Frequency}, release {ReleaseDate}, circulation {Circulation}, aver. rating {AverageRating:f2}";
		}
	}

	delegate TKey KeySelector<TKey>(Magazine mg);

	class MagazineCollection<TKey>
	{
		private Dictionary<TKey, Magazine> _collection;
		private KeySelector<TKey> _keySelector;

		public MagazineCollection(KeySelector<TKey> keySelector)
		{
			_keySelector = keySelector;
			_collection = new Dictionary<TKey, Magazine>();
		}

		public double MaxAverageRating
		{
			get
			{
				if (_collection.Values.Count == 0) return 0;
				return _collection.Max(entry => entry.Value.AverageRating);
			}
		}

		public IEnumerable<KeyValuePair<TKey, Magazine>> FrequencyGroup(Frequency value)
		{
			return _collection.Where(entry => entry.Value.Frequency == value);
		}

		public IEnumerable<IGrouping<Frequency, KeyValuePair<TKey, Magazine>>> GroupByFrequency
		{
			get
			{
				return _collection.GroupBy(entry => entry.Value.Frequency);
			}
		}

		public void AddDefaults()
		{
			Person p1 = new Person("Петров", "П");
			Person p2 = new Person("Игорев", "И");
			Person p3 = new Person("Иванов", "И");
			AddMagazines(
				new Magazine("Журнал 1", Frequency.Daily, DateTime.Now, 1000, [new Article(p1, "Статья 1", 8.9), new Article(p1, "Статья 2", 7.3)], [p2]),
				new Magazine("Журнал 2", Frequency.Weekly, DateTime.Now, 1000, [new Article(p1, "Статья 1", 8.9), new Article(p2, "Статья 2", 7.3)], [p3]),
				new Magazine("Журнал 3", Frequency.Monthly, DateTime.Now, 1000, [new Article(p2, "Статья 1", 8.9), new Article(p1, "Статья 2", 7.3)], [p3]));
		}
		
		public void AddMagazines(params Magazine[] magazines)
		{
			foreach (var magazine in magazines)
			{
				TKey key = _keySelector(magazine);
				_collection.Add(key, magazine);
			}
		}

		public override string ToString()
		{
			string str = "";
			foreach (Magazine magazine in _collection.Values)
			{
				str += $"Magazine: title {magazine.Title}, freq {magazine.Frequency}, release {magazine.ReleaseDate}, circulation {magazine.Circulation}\nEditors:\n";
				foreach (Person editor in magazine.Editors)
				{
					str += "\t" + editor.ToString() + "\n";
				}
				str += "Articles:\n";
				foreach (Article article in magazine.Articles)
				{
					str += "\t" + article.ToString() + "\n";
				}
				str += "\n";
			}
			return str;
		}

		public string ToShortString()
		{
			string str = "";
			foreach (Magazine magazine in _collection.Values)
			{
				str += magazine.ToShortString() + $" Editors count: {magazine.Editors.Count}, Articles count: {magazine.ArticlesList.Count}";

			}
			return str;
		}
	}
}

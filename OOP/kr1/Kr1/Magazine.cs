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
		private List<Article> _articles; //закрытое поле типа Article [] со списком статей в журнале И System.Collections.Generic.List<Article> для списка статей в журнале ???

		private List<Person> _editors;

		public double AverageRating
		{
			get
			{
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

		public void AddArticles(Article[] articles) {
			Articles = [.. Articles, .. articles];
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
			return $"Magazine: title {Title}, freq {Frequency}, release {ReleaseDate}, circulation {Circulation}, aver. rating {AverageRating}";
		}
	}
}

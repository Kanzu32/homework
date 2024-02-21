using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kr1
{
	class Magazine
	{
		string name;
		Frequency frequency;
		DateTime date;
		int circulation;
		Article[] articles; //???
		List<Person> editors;
		List<Article> articles2; //???

		public Magazine(string name, Frequency frequency, DateTime date, int circulation)
		{
			this.name = name;
			this.frequency = frequency;
			this.date = date;
			this.circulation = circulation;
			this.articles = [];
		}

		public Magazine()
		{
			this.name = "Unnamed magazine";
			this.frequency = new Frequency();
			this.date = new DateTime();
			this.circulation = 0;
			this.articles = [];
		}

		public string Name { get => name; set => name = value; }
		public Frequency Frequency { get => frequency; set => frequency = value; }
		public DateTime Date { get => date; set => date = value; }
		public int Circulation { get => circulation; set => circulation = value; }
		//public Article[] Articles { get => articles; set => articles = value; } //???
		public Article[] Articles { get { return articles2.ToArray(); } set { articles2 = [.. articles2, .. value]; } }
		public double AvarageRating { get {
			// Среднее значение рейтинга !!!
			double sum = 0;
			foreach (var article in articles)
			{
				sum += article.Rating;
			}
			return sum/articles.Length;
		}}
		public bool this[Frequency frequency]
		{
			get {
				if (this.frequency == frequency) return true;
				return false;
			}
		}

		public void AddArticles(Article[] articles) {
			// !!!
			this.articles = [.. this.articles, .. articles];
		}

		public override string ToString()
		{
			// список со всеми статьями !!!
			string str = $"Magazine: name {name}, freq {frequency}, date {date}, circulation {circulation}\n";
			foreach (var article in this.articles) {
				str += article.ToString() + "\n";
			}

			return $"Magazine: name {name}, freq {frequency}, date {date}, circulation {circulation}\n"; ;
		}

		public string ToShortString()
		{
			// список со средним рейтингом !!!
			return $"Magazine: name {name}, freq {frequency}, date {date}, circulation {circulation}, avarage rating {AvarageRating}";
		}
	}
}

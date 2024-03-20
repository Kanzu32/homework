
using Kr1;
using System.Diagnostics;

delegate KeyValuePair<TKey,TValue> GenerateElement<TKey, TValue>(int i);

class TestCollections<TKey, TValue> where TKey: notnull {
	private static DateTime _staticDate = DateTime.Now;
	public List<TKey> KeyList => _keyList;
	private List<TKey> _keyList;
	public List<TValue> ValueList => _valueList;
    private List<TValue> _valueList;

	public Dictionary<TKey, TValue> KeyDictionary => _keyDictionary;
	private Dictionary<TKey, TValue> _keyDictionary;

	public Dictionary<string, TValue> StringDictionary => _stringDictionary;
	private Dictionary<string, TValue> _stringDictionary;

    private GenerateElement<TKey, TValue> _generateFunction;
	private int _count;
    public TestCollections(int count, GenerateElement<TKey, TValue> generateFunction) {
        _generateFunction = generateFunction;
		_count = count;
		_keyList = new List<TKey>(count);
		_valueList = new List<TValue>(count);
		_keyDictionary = new Dictionary<TKey, TValue>(count);
		_stringDictionary = new Dictionary<string, TValue>(count);

		for (int i = 0; i < count; i++)
		{
			KeyValuePair<TKey, TValue> pair = _generateFunction(i);
			_keyList.Add(pair.Key);
			_valueList.Add(pair.Value);
			_keyDictionary.Add(pair.Key, pair.Value);
			_stringDictionary.Add(pair.Key.ToString() ?? i.ToString(), pair.Value);
		}
    }

	public void TestSearchTimes()
	{
		var first = _generateFunction(0);
		var middle = _generateFunction(_keyList.Count / 2);
		var last = _generateFunction(_keyList.Count);
		var non = _generateFunction(_keyList.Count + 1);

		Console.WriteLine("First element");
		SearchTimeForElement(first);
		Console.WriteLine("\nMiddle element");
		SearchTimeForElement(middle);
		Console.WriteLine("\nLast element");
		SearchTimeForElement(last);
		Console.WriteLine("\nNo exist element");
		SearchTimeForElement(non);
	}

	private void SearchTimeForElement(KeyValuePair<TKey, TValue> element)
	{
		var sw = new Stopwatch();
		Console.WriteLine("KeyList");
		sw.Start();
		_keyList.Contains(element.Key);
		sw.Stop();
		Console.WriteLine($"{sw.Elapsed.TotalNanoseconds} ns");

		Console.WriteLine("ValueList");
		sw.Restart();
		_valueList.Contains(element.Value);
		sw.Stop();
		Console.WriteLine($"{sw.Elapsed.TotalNanoseconds} ns");

		Console.WriteLine("KeyDictionary (ContainsKey)");
		sw.Restart();
		_keyDictionary.ContainsKey(element.Key);
		sw.Stop();
		Console.WriteLine($"{sw.Elapsed.TotalNanoseconds} ns");

		Console.WriteLine("StringDictionary");
		sw.Restart();
		_stringDictionary.ContainsKey(element.Key.ToString());
		sw.Stop();
		Console.WriteLine($"{sw.Elapsed.TotalNanoseconds} ns");

		Console.WriteLine("KeyDictionary (ContainsValue)");
		sw.Restart();
		_keyDictionary.ContainsValue(element.Value);
		sw.Stop();
		Console.WriteLine($"{sw.Elapsed.TotalNanoseconds} ns");
	}

	public static KeyValuePair<Edition, Magazine> GeneratePair(int i)
	{
		Edition edition = new Edition($"Edition {i}", _staticDate, 100);
		Magazine magazine = new Magazine($"Magazine {i}", Frequency.Daily, _staticDate, 100);
		return new KeyValuePair<Edition, Magazine>(edition, magazine);
	}
};
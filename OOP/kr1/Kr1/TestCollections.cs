
using Kr1;
using System.Diagnostics;
using System.Linq;

delegate KeyValuePair<TKey,TValue> GenerateElement<TKey, TValue>(int i);

class TestCollections<TKey, TValue> {
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
			if (pair.Key == null) _stringDictionary.Add(i.ToString(), pair.Value);
			else _stringDictionary.Add(pair.Key.ToString() ?? i.ToString(), pair.Value);
		}
    }

	public void Test()
	{
		var sw = new Stopwatch();
		var first = _generateFunction(0);
		var last = _generateFunction(_count - 1);
		var middle = _generateFunction(_count/2);
		var non = _generateFunction(-1);

		Console.WriteLine("KeyList");
		sw.Start();
		_keyList.Contains(first.Key);
		sw.Stop();
		Console.WriteLine("First: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyList.Contains(middle.Key);
		sw.Stop();
		Console.WriteLine("Middle: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyList.Contains(last.Key);
		sw.Stop();
		Console.WriteLine("Last: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyList.Contains(non.Key);
		sw.Stop();
		Console.WriteLine("Non-existent: " + sw.Elapsed.TotalNanoseconds);

		Console.WriteLine("\nValueList");
		sw.Restart();
		_valueList.Contains(first.Value);
		sw.Stop();
		Console.WriteLine("First: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_valueList.Contains(middle.Value);
		sw.Stop();
		Console.WriteLine("Middle: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_valueList.Contains(last.Value);
		sw.Stop();
		Console.WriteLine("Last: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_valueList.Contains(non.Value);
		sw.Stop();
		Console.WriteLine("Non-existent: " + sw.Elapsed.TotalNanoseconds);


		Console.WriteLine("\nKeyDict");
		sw.Restart();
		_keyDictionary.ContainsKey(first.Key);
		sw.Stop();
		Console.WriteLine("First: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyDictionary.ContainsKey(middle.Key);
		sw.Stop();
		Console.WriteLine("Middle: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyDictionary.ContainsKey(last.Key);
		sw.Stop();
		Console.WriteLine("Last: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyDictionary.ContainsKey(non.Key);
		sw.Stop();
		Console.WriteLine("Non-existent: " + sw.Elapsed.TotalNanoseconds);


		Console.WriteLine("\nStringDict");
		sw.Restart();
		_stringDictionary.ContainsKey(first.ToString());
		sw.Stop();
		Console.WriteLine("First: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_stringDictionary.ContainsKey(middle.ToString());
		sw.Stop();
		Console.WriteLine("Middle: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_stringDictionary.ContainsKey(last.ToString());
		sw.Stop();
		Console.WriteLine("Last: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_stringDictionary.ContainsKey(non.ToString());
		sw.Stop();
		Console.WriteLine("Non-existent: " + sw.Elapsed.TotalNanoseconds);

		Console.WriteLine("\nKeyDict by value");
		sw.Restart();
		_keyDictionary.ContainsValue(first.Value);
		sw.Stop();
		Console.WriteLine("First: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyDictionary.ContainsValue(middle.Value);
		sw.Stop();
		Console.WriteLine("Middle: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyDictionary.ContainsValue(last.Value);
		sw.Stop();
		Console.WriteLine("Last: " + sw.Elapsed.TotalNanoseconds);

		sw.Restart();
		_keyDictionary.ContainsValue(non.Value);
		sw.Stop();
		Console.WriteLine("Non-existent: " + sw.Elapsed.TotalNanoseconds);
	}

	public static KeyValuePair<Edition, Magazine> GeneratePair(int i)
	{
		Edition edition = new Edition($"Edition {i}", _staticDate, 100);
		Magazine magazine = new Magazine($"Magazine {i}", Frequency.Daily, _staticDate, 100);
		return new KeyValuePair<Edition, Magazine>(edition, magazine);
	}
};
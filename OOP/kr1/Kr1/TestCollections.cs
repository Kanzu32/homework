
delegate ref KeyValuePair<TKey,TValue> GenerateElement<TKey, TValue>(int i);



class TestCollections<TKey, TValue> {
    private List<TKey> keyList;
    private List<TValue> valueList;

    private Dictionary<TKey, TValue> kv;
    private Dictionary<string, TValue> sv;

    private GenerateElement<TKey, TValue> generateFunction;

    public TestCollections(int count, GenerateElement<TKey, TValue> generateFunction) {
        this.generateFunction = generateFunction;
        //Надо  сравнить  время  поиска элемента в коллекциях-списках List<TKey> !!!
    }

    // public static ref KeyValuePair<TKey, TValue> Generate(int n) {
    //     return ref new KeyValuePair<TKey, TValue>(TKey key, TValue value);
    // }
};